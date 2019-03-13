/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tet.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgonzale <bgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 17:11:44 by bgonzale          #+#    #+#             */
/*   Updated: 2019/02/11 17:58:07 by bgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "../libft/libft.h"
#include <stdio.h>
/*
** ft_gen_tet(); Helps create piece
*/

void	ft_gen_tet(char **new_piece, char *piece, char *m, char *lh)
{
	int i;

	i = 0;
	piece = piece + m[0] + (lh[2] + m[1]) * 5;
	while (piece[i] && i != lh[0])
	{
		(*new_piece)[i] = piece[i];
		i++;
	}
	while (i != lh[0])
	{
		(*new_piece)[i] = '\0';
	}
}

/*
** xy_mima(); x and y cordinates to find position of first '#' in every row
** finds x & y min. xMin = m[0] | yMin = m[1]
*/

void	xy_min(char *piece, char *m)
{
	unsigned char i;

	i = 0;
	m[0] = 3;
	m[1] = 3;
	while (i < 20)
	{
		if (piece[i] == '#')
		{
			if (i % 5 < m[0])
				m[0] = i % 5;
			if (i / 5 < m[1])
				m[1] = i / 5;
		}
		i++;
	}
}

/*
** get_lh(); gets length & heigth. Stores length & height inside int array.
** lh[0] == length and lh[1] == height. lh_in[2] is local variable used to
** reduce code. lh_in[0] = length lh_in[1] = height.
*/

void	get_lh(char *piece, char *lh)
{
	int				i;
	unsigned char	lh_in[2];

	i = 0;
	lh_in[0] = 0;
	lh_in[1] = 0;
	while (piece[i] != '\0')
	{
		if (piece[i] == '#' && piece[i + 5] != '#')
			lh_in[0]++;
		i++;
	}
	i = 0;
	while (piece[i] != '\0')
	{
		if (piece[i] == '#')
		{
			lh_in[1]++;
			while (piece[i] != '\n')
				i++;
		}
		i++;
	}
	lh[0] = lh_in[0];
	lh[1] = lh_in[1];
}

/*
** gen_piece(); creates tetrimino and stores it into a struct
** m[0] + (i + m[2]) * 5 = positon of first # is tetrimino block.
** lh[0] = length of the tetrimino needed to tell ft_strncpy how many
** it needs to move in length to store into new_piece[i].
*/

t_tet	*gen_piece(char *piece, char value)
{
	int			i;
	char		lh[3];
	char		m[2];
	char		**new_piece;
	t_tet		*tetrimino;

	tetrimino = (t_tet *)malloc(sizeof(t_tet));
	i = 0;
	get_lh(piece, lh);
	xy_min(piece, m);
	new_piece = (char **)malloc(sizeof(char *) * lh[1]);
	while (i < lh[1])
	{
		lh[2] = i;
		new_piece[i] = (char *)malloc(sizeof(char *) * lh[0]);
		ft_gen_tet(&new_piece[i], piece, m, lh);
		i++;
	}
	tetrimino->piece = new_piece;
	tetrimino->length = lh[0];
	tetrimino->height = lh[1];
	tetrimino->az = value;
	return (tetrimino);
}
