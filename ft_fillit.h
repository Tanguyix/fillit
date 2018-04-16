/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalpert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 16:35:19 by twalpert          #+#    #+#             */
/*   Updated: 2018/04/16 11:33:48 by tboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILLIT_H
# define FT_FILLIT_H

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

typedef struct		s_fill
{
	unsigned char	**tet;
	int				n;
	unsigned char	*box;
	int				*tpos;
	int				dim;
}					t_fill;

t_fill				ft_read_check(int fd, t_fill tetroes);
void				ft_usage(void);
void				ft_error(void);
void				ft_putstr(char *str);
void				ft_putchar(char c);

#endif
