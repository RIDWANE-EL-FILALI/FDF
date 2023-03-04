/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-fila <rel-fila@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 15:19:10 by rel-fila          #+#    #+#             */
/*   Updated: 2023/03/01 15:19:40 by rel-fila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	int		length;
	char	*hay;
	char	*nid;

	hay = (char *) haystack;
	nid = (char *) needle;
	if (*nid == '\0')
		return (hay);
	if (len == 0)
		return (0);
	i = 0;
	length = ft_strlen(nid);
	while (hay[i] != '\0' && (i + length) <= len)
	{
		if (ft_strncmp((hay + i), nid, length) == 0)
		{
			return (hay + i);
		}
		i++;
	}
	return (NULL);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while ((*s1 != '\0' || *s2 != '\0') && n > 0)
	{
		if (*s1 != *s2)
			return ((unsigned char)*s1 - (unsigned char)*s2);
		s1++;
		s2++;
		n--;
	}
	return (0);
}

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}
