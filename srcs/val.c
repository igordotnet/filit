/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   val.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgonzale <bgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 17:08:27 by bgonzale          #+#    #+#             */
/*   Updated: 2019/01/09 11:50:14 by bgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "../libft/libft.h"

/*
** val_tetrimino(); counts how many connections each [#] char has with another
** [#] char. the total connections should == 6 || 8 to be a valid tetrimino
*/

void	val_tetrimino(const char *piece)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (piece[i] != '\0')
	{
		if (piece[i] == '#')
		{
			if (i + 1 <= 19 && piece[i + 1] == '#')
				count++;
			if (i - 1 >= 0 && piece[i - 1] == '#')
				count++;
			if (i + 5 <= 19 && piece[i + 5] == '#')
				count++;
			if (i - 5 >= 0 && piece[i - 5] == '#')
				count++;
		}
		i++;
	}
	if (count == 6 || count == 8)
		ft_contiue();
	else
		ft_kill("error");
}

/*
** val_format(); by making sure the number of
** dots == 12, hashs == 4, nls == 4, total chars (i) == 20
** also makes sure when a nl is detected it checks previouse position
** for a [.] && [#]
*/

void	val_format(const char *piece)
{
	int i;
	int dots;
	int hashs;
	int nls;

	i = 0;
	dots = 0;
	hashs = 0;
	nls = 0;
	while (piece[i] != '\0')
	{
		if (piece[i] == '\n' && piece[i - 1] != '.' && piece[i - 1] != '#')
			ft_kill("error");
		if (piece[i] == '.')
			dots++;
		else if (piece[i] == '#')
			hashs++;
		else if (piece[i] == '\n')
			nls++;
		i++;
	}
	if (dots == 12 && hashs == 4 && nls == 4 && i == 20)
		val_tetrimino(piece);
	else
		ft_kill("error");
}

/*
** val_piece(); starts validating piece & generates piece if it's valid.
*/

void	val_piece(t_list **list, const char *buf, int num_blocks)
{
	int			i;
	int			pos;
	char		*temp;
	t_tet		*tetrimino;
	char		value;

	i = 0;
	pos = 0;
	value = 'A';
	while (i < num_blocks)
	{
		temp = ft_strsub(buf, pos, 20);
		val_format(temp);
		tetrimino = gen_piece(temp, value++);
		ft_lstadd(list, ft_lstnew(tetrimino, sizeof(t_tet)));
		free(temp);
		free(tetrimino);
		pos += 21;
		i++;
	}
}

/*
** read_file(); checks final piece to make sure is doesn't have additional
** character at the final piece. Also makes sure the number of pieces doesn't
** exceed 26.
*/

t_list	*read_file(int fd)
{
	t_list	*list;
	char	*buf;
	int		num_blocks;
	int		total;
	int		ret;

	list = NULL;
	buf = ft_strnew(547);
	ret = read(fd, buf, 546);
	buf[ret] = '\0';
	num_blocks = ret / 21;
	total = (num_blocks * 21) - 1;
	if ((ret - 1) == total || ret > 545)
		ft_kill("error");
	num_blocks++;
	val_piece(&list, buf, num_blocks);
	free(buf);
	return (list);
}
