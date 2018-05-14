/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <rnugroho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 21:07:38 by rnugroho          #+#    #+#             */
/*   Updated: 2018/05/14 21:13:29 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd(t_list **alst, t_list *_new)
{
	t_list	*list_ptr;

	if (*alst)
	{
		list_ptr = _new;
		if (list_ptr)
		{
			list_ptr->next = (*alst);
			(*alst) = list_ptr;
		}
	}
	else
		*alst = _new;
}
