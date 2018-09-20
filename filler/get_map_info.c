/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diputu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 14:30:39 by diputu            #+#    #+#             */
/*   Updated: 2018/09/05 17:06:12 by diputu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		get_map_info(t_filler *fill)
{
	int		i;
	char	*line;

	if (get_next_line(0, &line) == 0)
		return (0);
	fill->map.map_y = ft_atoi(ft_strchr(line, ' '));
	fill->map.map_x = ft_atoi(ft_strrchr(line, ' '));
	fill->map.data = (char **)malloc(sizeof(char *) * (fill->map.map_y + 1));
	get_next_line(0, &line);
	ft_strdel(&line);
	i = 0;
	while (i < fill->map.map_y)
	{
		get_next_line(0, &line);
		fill->map.data[i] = ft_strdup(line + 4);
		i++;
	}
	fill->map.data[i] = NULL;
	return (1);
}
