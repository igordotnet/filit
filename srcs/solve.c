/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgonzale <bgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 20:10:51 by bgonzale          #+#    #+#             */
/*   Updated: 2019/01/09 11:49:17 by bgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "../libft/libft.h"
#include <stdio.h>

/*
** remove_piece(); Removes piece from board.
*/

void	remove_piece(char ***board, t_tet *tetris, int *xy)
{
	int		i;
	int		j;
	int		length;
	int		height;
	char	**piece;

	i = 0;
	length = tetris->length;
	height = tetris->height;
	piece = tetris->piece;
	while (i < length)
	{
		j = 0;
		while (j < height)
		{
			if (piece[j][i] == '#')
			{
				(*board)[xy[1] + j][xy[0] + i] = '.';
			}
			j++;
		}
		i++;
	}
}

/*
** add_piece(); Adds piece to board.
*/

void	add_piece(char ***board, t_tet *tetris, int *xy)
{
	int		ij[2];
	int		length;
	int		height;
	char	**piece;
	char	value;

	ij[0] = 0;
	length = tetris->length;
	height = tetris->height;
	piece = tetris->piece;
	value = tetris->az;
	while (ij[0] < length)
	{
		ij[1] = 0;
		while (ij[1] < height)
		{
			if (piece[ij[1]][ij[0]] == '#')
			{
				(*board)[xy[1] + ij[1]][xy[0] + ij[0]] = value;
			}
			ij[1]++;
		}
		ij[0]++;
	}
}

/*
** try_set_piece(); Makes sure there isn't an overlap between the board pieces
** and the current piece being placed.
*/

char	try_set_piece(char ***board, t_tet *tetris, int *xy)
{
	int		i;
	int		j;
	int		length;
	int		height;
	char	**piece;

	length = tetris->length;
	height = tetris->height;
	piece = tetris->piece;
	i = 0;
	while (i < length)
	{
		j = 0;
		while (j < height)
		{
			if (piece[j][i] == '#' &&
			(*board)[j + xy[1]][i + xy[0]] != '.')
				return ('B');
			j++;
		}
		i++;
	}
	add_piece(board, tetris, xy);
	return ('A');
}

/*
** check_free_space(); Backtrack
*/

char	check_free_space(char ***board, int board_size, t_list *list)
{
	int		xy[2];
	t_tet	*tetris;
	printf("%s\n", "backtrack");
	if (list == NULL)
		return ('A');
	tetris = (t_tet *)(list->content);
	xy[1] = 0;
	while (xy[1] < board_size - tetris->height + 1)
	{
		xy[0] = 0;
		while (xy[0] < board_size - tetris->length + 1)
		{
			if (try_set_piece(board, tetris, xy) == 'A')
			{
				if (check_free_space(board, board_size, list->next) == 'A')
					return ('A');
				else
					remove_piece(board, tetris, xy);
			}
			xy[0]++;
		}
		xy[1]++;
	}
	return ('B');
}

/*
** solve_board(); While the list has tetreminos it will attempt to solve.
** if the pieces dont fit inside the current board it will be increased.
*/

void	solve_board(t_list *list, int board_size, char ***board)
{
	while (check_free_space(board, board_size, list) != 'A' && list != NULL)
	{
		free_board(board, board_size);
		board_size++;
		new_board(board, board_size);
	}
	print_board(board, board_size);
	free_board(board, board_size);
}
