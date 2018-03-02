/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <rnugroho@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 18:00:11 by rnugroho          #+#    #+#             */
/*   Updated: 2018/03/01 22:05:29 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <unistd.h>
# include "libft.h"

# define BUFF_SIZE 1
# define ALLOCATED(x) if (!x) return (-1);
# define CONTENT(x) ((t_file*)((x->content)))->content
# define START(x) ((t_file*)((x->content)))->content_start

typedef struct	s_file
{
	int			fd;
	char		*content;
	char		*content_start;
}				t_file;

int				get_next_line(int fd, char **line);

#endif
