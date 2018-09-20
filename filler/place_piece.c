/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_piece.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diputu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 15:27:16 by diputu            #+#    #+#             */
/*   Updated: 2018/09/07 15:34:39 by diputu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			find_place(t_filler *p, int y, int x)
{
	int i;
	int j;
	int touches;

	i = 0;
	touches = 0;
	while (i < p->piece.piece_y)
	{
		j = 0;
		while (j < p->piece.piece_x)
		{
			if ((((i + y) >= p->map.map_y || (j + x) >= p->map.map_x) ||
						i + y < 0 || j + x < 0) && p->piece.data[i][j] == '*')
				return (0);
			if (p->piece.data[i][j] == '*' &&
					p->map.data[i + y][j + x] == p->me.id)
				touches++;
			if (p->piece.data[i][j] == '*' &&
					p->map.data[i + y][j + x] == p->enemy.id)
				return (0);
			j++;
		}
		i++;
	}
	return ((touches == 1) ? 1 : 0);
}

int			check(t_filler *check, int y, int x)
{
	if (x + check->piece.piece_x > check->map.map_x)
		return (0);
	else if (y + check->piece.piece_y > check->map.map_y)
		return (0);
	else
		return (find_place(check, y, x));
}

int			down(t_filler *go)
{
	int		x;
	int		y;

	y = go->map.map_y - 1;
	while (y >= 0)
	{
		x = go->map.map_x - 1;
		while (x >= 0)
		{
			if (check(go, y - go->ty, x - go->tx) == 1)
			{
				go->x = x - go->tx;
				go->y = y - go->ty;
				place_piece(go);
				return (1);
			}
			x--;
		}
		y--;
	}
	return (0);
}

int			fill_it(t_filler *go)
{
	int x;
	int y;

	y = -1;
	trim_piece(go);
	if (go->me.id == 'X')
	while (++y < go->map.map_y)
		{
			x = 0;
			while (x < go->map.map_x)
			{
				if (check(go, y - go->ty, x - go->tx) == 1)
				{
					go->x = x - go->tx;
					go->y = y - go->ty;
					place_piece(go);
					return (1);
				}
				x++;
			}
		}
	else if (down(go) == 1)
		return (1);
	return (0);
}
