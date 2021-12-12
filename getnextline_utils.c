/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getnextline_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 12:36:34 by twagner           #+#    #+#             */
/*   Updated: 2021/12/12 14:56:48 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

static char	*ft_strcpy(char *dst, const char *src)
{
	size_t	i;

	i = -1;
	if (!src)
	{
		dst[0] = 0;
		return (dst);
	}
	while (src[++i])
		dst[i] = src[i];
	dst[i] = '\0';
	return (dst);
}

void	*ft_realloc(void *ptr, size_t size)
{
	char	*new;

	if (!ptr || size == 0)
	{
		if (size == 0)
			size = 1;
		new = (char *)malloc(sizeof(*new) * size);
		if (!new)
		{
			free(ptr);
			return (NULL);
		}
		return (new);
	}
	new = (char *)malloc(sizeof(*new) * size);
	if (!new)
	{
		free(ptr);
		return (NULL);
	}
	new = ft_strcpy(new, ptr);
	free(ptr);
	return (new);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	s_len;
	size_t	d_len;
	size_t	i;
	size_t	result;

	i = 0;
	s_len = ft_strlen(src);
	d_len = ft_strlen(dst);
	if (dstsize >= d_len)
		result = s_len + d_len;
	else
		result = s_len + dstsize;
	if (dstsize > d_len)
	{
		while (src[i] && d_len < dstsize - 1)
		{
			dst[d_len] = src[i];
			++d_len;
			++i;
		}
	}
	dst[d_len] = '\0';
	return (result);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	i;
	size_t	slen;
	size_t	rlen;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (start >= slen)
		rlen = 0;
	else if (start + len > slen)
		rlen = slen - start;
	else
		rlen = len;
	res = (char *)malloc(sizeof(*res) * (rlen + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (s[start + i] && i < rlen)
	{
		res[i] = s[start + i];
		++i;
	}
	res[i] = '\0';
	return (res);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		++s;
	}
	if (c == 0)
		return ((char *)s);
	return (NULL);
}
