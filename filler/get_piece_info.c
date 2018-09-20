/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_piece_info.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diputu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 15:12:55 by diputu            #+#    #+#             */
/*   Updated: 2018/09/07 15:23:09 by diputu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	get_piece_info(t_filler *fill)
{
	int		i;
	char	*line;

	get_next_line(0, &line);
	fill->piece.piece_y = ft_atoi(ft_strchr(line, ' '));
	fill->piece.piece_x = ft_atoi(ft_strrchr(line, ' '));
	fill->piece.data = (char **)malloc(sizeof(char *) *
			(fill->piece.piece_y + 1));
	i = 0;
	ft_strdel(&line);
	while (i < fill->piece.piece_y)
	{
		get_next_line(0, &line);
		fill->piece.data[i] = ft_strdup(line);
		i++;
	}
	fill->piece.data[i] = NULL;
}
