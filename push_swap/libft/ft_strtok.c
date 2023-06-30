/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecullier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 14:12:24 by ecullier          #+#    #+#             */
/*   Updated: 2023/06/30 10:11:18 by ecullier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_delimiter(char c, const char *delim)
{
	while (*delim != '\0')
	{
		if (c == *delim)
		{
			return (1);
		}
		delim++;
	}
	return (0);
}

char	*ft_strtok(char *str, const char *delim)
{
	static char	*next_token;
	char		*start;

	if (str == NULL)
	{
		if (next_token == NULL)
		{
			return (NULL);
		}
		str = next_token;
	}
	start = str;
	while (*str != '\0')
	{
		if (is_delimiter(*str, delim))
		{
			*str = '\0';
			next_token = str + 1;
			return (start);
		}
		str++;
	}
	next_token = NULL;
	return (start);
}
