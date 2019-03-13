/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgonzale <bgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 20:11:48 by bgonzale          #+#    #+#             */
/*   Updated: 2019/01/09 11:49:03 by bgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "../libft/libft.h"

/*
** free_board(); Free board.
*/

void	free_board(char ***board, int board_size)
{
	int i;

	i = 0;
	while (i < board_size)
	{
		free(((*board)[i]));
		i++;
	}
	free((*board));
}

/*
** print_board(); Print board.
*/

void	print_board(char ***board, int board_size)
{
	int i;

	i = 0;
	while (i < board_size)
	{
		ft_putstr((*board)[i]);
		ft_putchar('\n');
		i++;
	}
}

/*
** bs_sqrt(); Find board starting size based on number of tetriminos.
*/

int		bs_sqrt(int n)
{
	int size;

	size = 2;
	while (size * size < n)
	{
		size++;
	}
	return (size);
}

/*
** new_board(); Creates new board and fills it with '.'
*/

void	new_board(char ***board, int board_size)
{
	int		i;
	int		j;

	i = 0;
	(*board) = (char **)malloc(sizeof(char *) * board_size);
	while (i < board_size)
	{
		(*board)[i] = (char *)malloc(sizeof(char) * board_size);
		i++;
	}
	i = 0;
	while (i < board_size)
	{
		j = 0;
		while (j < board_size)
		{
			(*board)[i][j++] = '.';
		}
		(*board)[i][j++] = '\0';
		i++;
	}
}
