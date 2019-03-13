/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgonzale <bgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 17:10:13 by bgonzale          #+#    #+#             */
/*   Updated: 2019/01/09 11:54:36 by bgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>

typedef struct		s_tet
{
	char	**piece;
	int		length;
	int		height;
	char	az;
}					t_tet;

/*
** val.c
*/

t_list				*read_file(int fd);
void				val_piece(t_list **list, const char *buf, int num_blocks);
void				val_format(const char *piece);
void				val_tetrimino(const char *piece);

/*
** tet.c
*/

t_tet				*gen_piece(char *piece, char value);
void				get_lh(char *piece, char *lh);
void				xy_min(char *piece, char *m);
void				ft_gen_tet(char **new_piece, char *piece,
		char *m, char *lh);

/*
** board.c
*/

void				new_board(char ***board, int size);
int					bs_sqrt(int n);
void				print_board(char ***board, int board_size);
void				free_board(char ***board, int board_size);

/*
** solve.c
*/

void				solve_board(t_list *list, int board_size, char ***board);
char				check_free_space(char ***board, int board_size,
		t_list *list);
char				try_set_piece(char ***board, t_tet *tetris, int *xy);
void				add_piece(char ***board, t_tet *tetris, int *xy);
void				remove_piece(char ***board, t_tet *tetris, int *xy);

/*
** helpers
*/

void				ft_kill(char *str);
void				ft_contiue();

#endif
