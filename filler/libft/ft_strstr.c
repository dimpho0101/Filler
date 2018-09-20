/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diputu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 12:14:06 by diputu            #+#    #+#             */
/*   Updated: 2018/07/01 12:01:52 by diputu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		i;
	int		j;
	int		k;
	int		good;

	if (!ft_strlen(needle))
		return ((char *)haystack);
	i = -1;
	good = 0;
	while (*(haystack + ++i) && !good)
	{
		if (*(haystack + i) == *(needle + 0))
		{
			j = 0;
			k = i;
			good = 1;
			while (*(needle + j))
				if (*(needle + j++) != *(haystack + k++))
					good = 0;
			if (good)
				return ((char *)haystack + i);
		}
	}
	return (NULL);
}
