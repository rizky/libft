/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_date.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <rnugroho@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 16:50:22 by rnugroho          #+#    #+#             */
/*   Updated: 2018/02/24 20:48:25 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static const long g_days_per_month[2][MOS_PER_YEAR] = {
	{ 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 },
	{ 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }
};

static const long g_days_per_year[2] = {
	365, 366
};

long long
	ft_datetoepoch(long date[6])
{
	long long epoch;
	long years;
	long leap_years;
	int		i;

	years = 0;
	leap_years = 0;
	i = EPOCH_YEAR - 1;
	while (++i < date[5])
		if (IS_LEAP_YEAR(i))
			leap_years++;
		else 
			years++;
	epoch = ((years*g_days_per_year[0]) + (leap_years*g_days_per_year[1])) * SEC_PER_DAY;
	long year_index = (IS_LEAP_YEAR( date[5] )) ? 1 : 0;
	i = -1;
	while (++i < date[4]-1)
		epoch += g_days_per_month[year_index][i] * SEC_PER_DAY;
	epoch += (date[3]-1) * SEC_PER_DAY + date[2] * SEC_PER_HOUR
	+ date[1] * SEC_PER_MIN + date[0];
	return (epoch);
}

long
	*ft_epochtodate(long long epoch)
{
	long *date;
	long long dayclock, dayno;
	long year;

	date = (long *)malloc(sizeof(long) * 6);
	dayclock =  epoch % SEC_PER_DAY;
	dayno = epoch / SEC_PER_DAY;

	date[0] = dayclock % 60;
	date[1] = (dayclock % 3600) / 60;
	date[2] = dayclock / 3600;
	year = EPOCH_YEAR;
	while (dayno >= YEARSIZE(year)) 
	{
			dayno -= YEARSIZE(year);
			year++;
	}
	date[5] = year;
	date[4] = 0;
    while (dayno >= g_days_per_month[IS_LEAP_YEAR(year)][date[4]])
    {
        dayno -= g_days_per_month[IS_LEAP_YEAR(year)][date[4]];
        date[4]++;
    }
	date[3] = dayno + 1;
	return date;
}