/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_error_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboissel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 13:31:24 by tboissel          #+#    #+#             */
/*   Updated: 2018/04/16 13:19:32 by twalpert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fillit.h"

t_fill		ft_read_check(int fd, t_fill t)
{
	char	buf;
	t_count	i;

	i.l = 1;
	i.c = 16;
	while (read(fd, &buf, 1) && (buf == '.' || buf == '#' || buf == '\n'))
	{
		if (!i.l && !(i.h = 0))
			t.n++;
		if ((buf != '\n' && (i.l == 4 || !(i.c / 2))) || (i.l == 4 && i.h != 4)
				|| (buf = '#' && t.tet[t.n][i.l] && !((t.tet[t.n][i.l]) % i.c)))
			ft_error();
		if (i.l != 4 && (i.c /= 2) && buf == '#' && ++i.h)
				t.tet[t.n][i.l] += i.c;
		if (i.l == 4)
			i.l = 0;
		if (!i.c && ++i.l && (i.c = 16) && i.l > 1 && t.tet[t.n][i.l - 1] &&
				t.tet[t.n][i.l] && !(t.tet[t.n][i.l] & t.tet[t.n][i.l - 1]))
			ft_error();
	}
	if (ct.line != 0 || tetroes.n == 0 || buf != '\n')
		ft_error();
	return (tetroes);
}
