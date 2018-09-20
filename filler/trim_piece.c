/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim_piece.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diputu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 16:59:05 by diputu            #+#    #+#             */
/*   Updated: 2018/09/07 15:23:58 by diputu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	trim_piece(t_filler *check)
{
	int	x;
	int	y;

	y = 0;
	while (y < check->piece.piece_y)
	{
		x = 0;
		while (x < check->piece.piece_x)
		{
			if (check->piece.data[y][x] == '*')
				break ;
			x++;
		}
		if (check->piece.data[y][x] == '*')
			break ;
		y++;
	}
	check->tx = x;
}

void	column(t_filler *check)
{
	int x;
	int y;

	x = 0;
	while (x < check->piece.piece_x)
	{
		y = 0;
		while (y < check->piece.piece_y)
		{
			if (check->piece.data[y][x] == '*')
				break ;
			y++;
		}
		if (y != check->piece.piece_y)
			break ;
		x++;
	}
	check->ty = y;
}
