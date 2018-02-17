#include "ft_array.h"
#include <stdlib.h>

/*
** Array::clear
** -
** Frees the underlying data, but leaves the array usable :
** one might still call the append function, the array was only
** emptied.
*/

void	fta_clear(t_array *self)
{
	if (self->max > 0)
	{
		free(self->data);
		self->size = 0;
		self->max = 0;
	}
}
