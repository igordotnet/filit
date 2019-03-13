/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgonzale <bgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 17:07:15 by bgonzale          #+#    #+#             */
/*   Updated: 2019/01/09 11:49:09 by bgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "../libft/libft.h"

void	ft_lstrev(t_list **alst)
{
	t_list	*previous;
	t_list	*current;
	t_list	*next;

	previous = NULL;
	current = *alst;
	while (current != NULL)
	{
		next = current->next;
		current->next = previous;
		previous = current;
		current = next;
	}
	*alst = previous;
}

int		ft_lstcount(t_list *lst)
{
	int i;

	i = 0;
	while (lst != NULL)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

void	ft_contiue(void)
{
	int i;

	i = 0;
	i++;
}

void	ft_kill(char *str)
{
	ft_putstr(str);
	ft_putchar('\n');
	exit(1);
}

int		main(int argc, char **argv)
{
	t_list	*list;
	char	**board;
	int		num_blocks;
	int		board_size;

	if (argc != 2)
		ft_kill("usage: ./fillit file_name");
	if ((list = read_file(open(argv[1], O_RDONLY))) == NULL)
		ft_kill("error");
	ft_lstrev(&list);
	num_blocks = ft_lstcount(list);
	board_size = bs_sqrt(num_blocks * 4);
	new_board(&board, board_size);
	solve_board(list, board_size, &board);
	return (0);
}
