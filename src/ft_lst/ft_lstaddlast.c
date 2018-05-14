/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddlast.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <rnugroho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 14:32:50 by rnugroho          #+#    #+#             */
/*   Updated: 2018/05/14 21:13:29 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstaddlast(t_list **alst, t_list *_new)
{
	t_list	*list_ptr;

	list_ptr = *alst;
	if (list_ptr)
	{
		while (list_ptr->next)
			list_ptr = list_ptr->next;
		list_ptr->next = _new;
	}
	else
		*alst = _new;
}
