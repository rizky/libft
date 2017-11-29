/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 16:47:40 by rnugroho          #+#    #+#             */
/*   Updated: 2017/11/14 16:47:45 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*str;
	int		start;
	int		end;
	int		i;

	start = 0;
	if (!s)
		return (NULL);
	while ((ft_strchr(" \n\t", s[start]) != NULL) && (s[start] != '\0'))
		start++;
	end = ft_strlen(s) - 1;
	while ((ft_strchr(" \n\t", s[end]) != NULL) && (end > 0) && (end > start))
		end--;
	str = (char *)ft_memalloc(end - start + 2);
	if (!str)
		return (NULL);
	i = 0;
	while (start <= end)
	{
		str[i] = s[start];
		start++;
		i++;
	}
	str[i] = '\0';
	return (str);
}
