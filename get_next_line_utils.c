/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacastil <dacastil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 17:34:57 by dacastil          #+#    #+#             */
/*   Updated: 2024/10/30 16:46:04 by dacastil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strdup(const char *s)
{
	size_t	lenght;
	size_t	i;
	char	*dup;

	lenght = ft_strlen(s);
	dup = (char *)malloc(lenght + 1);
	if (!dup)
		return (NULL);
	i = 0;
	while (i < lenght)
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	ls1;
	size_t	ls2;
	size_t	i;
	size_t	j;
	char	*strresult;

	if (!s1 || !s2)
		return (NULL);
	ls1 = ft_strlen(s1);
	ls2 = ft_strlen(s2);
	i = 0;
	j = 0;
	strresult = ft_calloc((ls1 + ls2) + 1, sizeof(char));
	if (!strresult)
		return (NULL);
	while (s1[i] != '\0')
	{
		strresult[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
		strresult[i++] = s2[j++];
	return (strresult);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if ((char)c == s[i])
		{
			return ((char *)(s + i));
		}
		i++;
	}
	if ((char)c == '\0')
	{
		return ((char *)(s + i));
	}
	return (NULL);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	totalsz;
	char	*pr;
	size_t	i;

	i = 0;
	if (nmemb == 0 || size == 0)
		return (malloc(0));
	totalsz = (nmemb * size);
	if (totalsz / size != nmemb)
		return (NULL);
	pr = malloc(totalsz);
	if (!pr)
		return (NULL);
	while (i < totalsz)
	{
		pr[i] = 0;
		i++;
	}
	return (pr);
}

// void	*ft_realloc(void *str, size_t size)
// {
// 	char	*newstr;
// 	size_t	i;
// 	size_t	lngstr;
// 	size_t i_copy;

// 	i = 0;
// 	if (!str)
// 		return (malloc(size));
// 	lngstr = ft_strlen(str);
// 	newstr = malloc(size);
// 	if (!newstr)
// 		return (NULL);

// 	if (lngstr < size)
// 		i_copy = lngstr;
// 	else
// 		i_copy = size;
// 	while (i < i_copy)
// 	{
// 		newstr[i] = ((char *)str)[i];
// 		i++;
// 	}
// 	if (size > lngstr)
// 		newstr[i] = '\0';
// 	return (newstr);
// 	free(str);
// }
