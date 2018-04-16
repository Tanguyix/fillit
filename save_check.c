/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_error_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboissel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 13:31:24 by tboissel          #+#    #+#             */
/*   Updated: 2018/04/16 11:53:43 by tboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fillit.h"

t_fill		ft_read_check(int fd, t_fill tetroes)
{
	char	buf;
	t_count	ct;

	ct.line = 1;
	ct.ch = 16;
	while (read(fd, &buf, 1) && (buf == '.' || buf == '#' || buf == '\n'))
	{
		if (ct.line == 1 && !(ct.hash = 0))
			tetroes.n++;
		if (ct.line != 4 && (ct.ch /= 2))
			if (buf == '#' && ++ct.hash)
				tetroes.tet[tetroes.n][ct.line] += ct.ch;
		if (buf !='\n' && (ct.line == 4 || !ct.ch))
			ft_error();
		if (ct.line == 4)
			ct.line = 0;
		if (!ct.ch && ++ct.line && (ct.ch = 16))
			
	}
	if (ct.line != 0 || tetroes.n == 0 || buf != '\n')
		ft_error();
	return (tetroes);
}
