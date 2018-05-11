/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getopt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <rnugroho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 03:43:02 by rnugroho          #+#    #+#             */
/*   Updated: 2018/05/11 03:50:58 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_getopt.h"

char *g_optarg;
int g_optind = 1;
int g_optopt;

static char *g_nextc;

static void
	opt_print_err(char *const *argv, const char *msg)
{
	ft_dprintf(2, "%s: %s -- %c\n", argv[0], msg, g_optopt);
}

int
	ft_getopt(int argc, char *const *argv, const char *opts)
{
	char *p;

	g_optarg = 0;
	if (*opts == '+')
		++opts;
	if (!g_optind)
	{
		g_nextc = 0;
		g_optind = 1;
	}
	if (!g_nextc || !*g_nextc)
	{
		if (g_optind >= argc)
			return (-1);
		if (argv[g_optind][0] != '-')
			return (-1);
		if (argv[g_optind][1] == '\0')
			return (-1);
		if (argv[g_optind][1] == '-' && argv[g_optind][2] == '\0')
		{
			++g_optind;
			return (-1);
		}
		g_nextc = argv[g_optind] + 1;
	}
	g_optopt = *g_nextc++;
	if (!*g_nextc)
		++g_optind;
	p = strchr(opts, g_optopt);
	if (!p || g_optopt == ':')
	{
		opt_print_err(argv, "illegal option");
		return (-1);
	}
	if (p[1] == ':')
	{
		if (*g_nextc)
		{
			g_optarg = g_nextc;
			g_nextc = NULL;
			++g_optind;
		}
		else if (p[2] != ':')
		{
			if (g_optind >= argc)
			{
				opt_print_err(argv, "option requires an argument");
				return (*opts == ':' ? ':' : -1);
			}
			else
				g_optarg = argv[g_optind++];
		}
	}
	return (g_optopt);
}
