/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_re_match_4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <rnugroho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 15:41:46 by rnugroho          #+#    #+#             */
/*   Updated: 2018/04/13 15:43:34 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_re.h"
#include "libft.h"

char
	*ft_re_match_capture(const char *pattern, const char *group, const char *text)
{
	int 	len;
	int		start;
	char 	*str;

	if (ft_re_match(pattern, text) == -1)
		return NULL;
	start = ft_re_match(group, text);
	text = text + start;
	len = ft_strlen(text);
	while (ft_re_matchn(group, text, len - 1) == 0)
		len--;
	str = ft_memalloc(len + 1 - 2);
	ft_memcpy(str, text + 1, len - 2);
	str[len] = '\0';
	return (str);
}

int
	ft_re_matchn(const char* pattern, const char* text, int len)
{
	char	*str;
	int		res;

	res = -1;
	str = ft_memalloc(len + 1);
	ft_memcpy(str, text, len);
	str[len] = '\0';
	res = ft_re_matchp(ft_re_compile(pattern), str);
	free(str);
	return (res);
}
