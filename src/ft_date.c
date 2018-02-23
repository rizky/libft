/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_date.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <rnugroho@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 16:50:22 by rnugroho          #+#    #+#             */
/*   Updated: 2018/02/23 17:28:33 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static const int g_days_per_month[2][MOS_PER_YEAR] = {
	{ 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 },
	{ 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }
};

static const int g_days_per_year[2] = {
	365, 366
};

uint32_t
	unix_time_in_seconds(uint8_t date[6])
{
	uint32_t	ts;
	uint8_t		i;
	uint8_t		j;
	uint8_t		y_k;

	y_k = EPOCH_YEAR - 1;
	while (y_k++ < date[5])
		if (IS_LEAP_YEAR(y_k))
			j++;
		else
			i++;
	ts += ((i * g_days_per_month[0]) +
		(j * g_days_per_month[1])) * SEC_PER_DAY;
	j = (IS_LEAP_YEAR(date[5])) ? 1 : 0;
	i = 0;
	while (i < (date[4] - 1))
	{
		ts += g_days_per_month[j][i] * SEC_PER_DAY;
		i++;
	}
	ts += (date[3] - 1) * SEC_PER_DAY;
	ts += date[2] * SEC_PER_HOUR;
	ts += date[1] * SEC_PER_MIN;
	ts += date[1];
	return (ts);
}
