/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diputu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 14:30:48 by diputu            #+#    #+#             */
/*   Updated: 2018/09/07 15:04:51 by diputu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		place_piece(t_filler *fill)
{
	ft_putnbr(fill->y);
	ft_putchar(' ');
	ft_putnbr(fill->x);
	ft_putchar('\n');
}

void		get_player(t_filler *fill)
{
	char *line;

	get_next_line(0, &line);
	if (line[10] == '1' || line[10] == '2')
	{
		if (line[10] == '1')
			fill->me.id = 'O';
		else
			fill->me.id = 'X';
		if (line[10] == '2')
			fill->enemy.id = 'O';
		else
			fill->enemy.id = 'X';
	}
}

int			main(void)
{
	t_filler fill;

	get_player(&fill);
	while (1)
	{
		if (get_map_info(&fill) == 0)
			break ;
		get_piece_info(&fill);
		if (fill_it(&fill) == 1)
			continue ;
		else
		{
			ft_putnbr(0);
			ft_putchar(' ');
			ft_putnbr(0);
			ft_putchar('\n');
			return (0);
		}
	}
	return (0);
}
