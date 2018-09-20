/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diputu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/01 12:15:35 by diputu            #+#    #+#             */
/*   Updated: 2018/07/01 17:10:55 by diputu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int			ft_scanb(const int fd, char **line)
{
	int		con;
	char	*buf;
	char	*tmp;

	if (!(buf = ft_strnew(BUFF_SIZE)))
		return (-1);
	con = read(fd, buf, BUFF_SIZE);
	if (con > 0)
	{
		if (!(tmp = ft_strjoin(*line, buf)))
			return (-1);
		free(*line);
		*line = tmp;
		free(buf);
	}
	if (con == 0)
		free(buf);
	return (con);
}

int					get_next_line(const int fd, char **line)
{
	int				con;
	static char		*str;
	char			*str1;

	if (((!str && (!(str = ft_strnew(BUFF_SIZE)))) || fd < 0 || BUFF_SIZE <= 0))
		return (-1);
	str1 = ft_strchr(str, '\n');
	while (!str1)
	{
		con = ft_scanb(fd, &str);
		if (con == 0 && !ft_strlen(str))
			return (0);
		if (con == 0)
			ft_strcat(str, "\n");
		if (con < 0)
			return (-1);
		else
			str1 = ft_strchr(str, 10);
	}
	if (!(*line = ft_strsub(str, 0, ft_strlen(str) - ft_strlen(str1))))
		return (-1);
	ft_strcpy(str, str1 + 1);
	return (1);
}
