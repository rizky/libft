/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <rnugroho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 21:10:55 by rnugroho          #+#    #+#             */
/*   Updated: 2018/05/14 21:13:29 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*_new;

	if ((_new = (t_list *)malloc(sizeof(*_new))) == NULL)
		return (NULL);
	if (content == NULL)
	{
		_new->content = NULL;
		_new->content_size = 0;
	}
	else
	{
		if ((_new->content = malloc(content_size)) == NULL)
		{
			free(_new);
			return (NULL);
		}
		ft_memcpy(_new->content, content, content_size);
		_new->content_size = content_size;
	}
	_new->next = NULL;
	return (_new);
}
