/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diputu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 14:29:51 by diputu            #+#    #+#             */
/*   Updated: 2018/09/07 15:30:35 by diputu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft/libft.h"
# include <stdio.h>

typedef struct	s_map
{
	int			map_x;
	int			map_y;
	char		**data;
}				t_map;

typedef	struct	s_piece
{
	int			piece_x;
	int			piece_y;
	char		**data;
}				t_piece;

typedef struct	s_player
{
	int			player_x;
	int			player_y;
	char		id;
}				t_player;

typedef	struct	s_point
{
	int			x;
	int			y;
}				t_point;

typedef	struct	s_filler
{
	int			x;
	int			y;
	int			tx;
	int			ty;
	t_point		point;
	t_map		map;
	t_piece		piece;
	t_player	me;
	t_player	enemy;
}				t_filler;

int				get_map_info(t_filler *fill);
void			get_piece_info(t_filler *fill);
int				fill_it(t_filler *go);
void			trim_piece(t_filler *check);
void			place_piece(t_filler *fill);
#endif
