/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fta_resize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <rnugroho@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 15:08:29 by rnugroho          #+#    #+#             */
/*   Updated: 2018/03/09 05:26:45 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_array.h"
#include "libft.h"
#include <stdlib.h>

/*
** Array::_resize
** No subtlety, just resizes the underlying array, no matter the consequences.
** However, in case of a malloc fail, the array is left untouched.
*/

int		fta_resize(t_array *self, size_t new_size)
{
	void	*tmp;

	tmp = malloc(new_size * self->type_size);
	if (tmp == NULL)
		return (1);
	if (self->size > new_size)
		self->size = new_size;
	ft_memcpy(tmp, self->data, self->size * self->type_size);
	free(self->data);
	self->data = tmp;
	self->max = new_size;
	return (0);
}
