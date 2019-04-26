/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillsolve.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalpert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 16:55:26 by twalpert          #+#    #+#             */
/*   Updated: 2018/04/20 15:12:10 by twalpert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fillit.h"

void	ft_usage_error(int i)
{
	if (i)
	{
		write(1, "Usage: Creates the smallest array with the tetrominos ", 54);
		write(1, "given in the file\n\nUse fillit with one file depicting", 53);
		write(1, " 1 to 26 tetrominoes\nTetrominos should be separated by", 54);
		write(1, " one empty line and\ndisplayed in a 4x4 square of dots", 53);
		write(1, " (.) and hashes (#)\n\nExample of a correct imput file", 52);
		write(1, ":\n..##\n.##.\n....\n....\n\n.#..\n.#..\n.#..\n.#..\n", 43);
	}
	if (!i)
	{
		write(1, "error\n", 6);
		exit(0);
	}
}

t_fill	ft_read_check(int fd, t_fill t)
{
	char	buf;
	t_count i;

	i.l = 0;
	i.c = 0;
	while (read(fd, &buf, 1) && (buf == '.' || buf == '#' || buf == '\n'))
	{
		if (!i.l && !i.c && !(i.h = 0) && ++t.n > 25)
			ft_usage_error(0);
		if ((buf != '\n' && (i.l == 4 || i.c * 2 > 8)) || (i.l == 4 && i.h != 4)
				|| (buf == '#' && t.tet[t.n][i.l] && !(t.tet[t.n][i.l] / i.c))
				|| (i.l > 1 && t.tet[t.n][i.l] && !t.tet[t.n][i.l - 1] &&
					t.tet[t.n][i.l - 2]))
			ft_usage_error(0);
		if (i.l != 4 && (i.c = (i.c ? i.c * 2 : 1)) && buf == '#' && ++i.h)
			t.tet[t.n][i.l] += i.c;
		if (i.l == 4)
			i.l = 0;
		if (i.c > 8 && ((i.l && !(t.tet[t.n][i.l] & t.tet[t.n][i.l - 1]) &&
			t.tet[t.n][i.l - 1] && t.tet[t.n][i.l]) || (i.c = 0) || !(++i.l)))
			ft_usage_error(0);
	}
	if (i.l != 4 || !(++t.n) || buf != '\n' || i.h != 4)
		ft_usage_error(0);
	return (t);
}

t_fill	ft_prepare(t_fill t)
{
	t_count	i;

	t.mx = t.n / 2 + 5 - t.n / 10 - t.n / 16;
	t.dim = t.mx + 1;
	i.l = -1;
	if ((t.box = (unsigned int*)malloc(sizeof(*t.box) * t.mx)))
		while (++i.l < t.mx)
			t.box[i.l] = 15;
	t.pos = (int*)malloc(sizeof(*t.pos) * (t.n));
	if (i.l < t.mx || !t.box || !t.pos || !(i.h = t.n))
		ft_usage_error(0);
	while (i.h--)
	{
		while (!t.tet[i.h][0] && (i.c = -1))
			while (++i.c < 3 || (t.tet[i.h][i.c] = 0))
				t.tet[i.h][i.c] = t.tet[i.h][i.c + 1];
		while ((t.tet[i.h][0] & 15) && (i.c = -1))
			while (++i.c < 4)
				t.tet[i.h][i.c] <<= 1;
	}
	return (t);
}

int		ft_fillsolve(t_fill *t, int x, int p)
{
	t_count	i;

	i.c = 0;
	i.l = -1;
	i.h = 0;
	while (++i.l < t->mx && ((t->box[i.l] ^ 15 && (i.h = i.l + 1)) || t->mx))
		i.c |= t->box[i.l];
	while (i.l-- && (!(i.c & 16) || (i.h > t->mx - i.l || (i.h = t->mx - i.l))))
		i.c >>= 1;
	if (x == t->n && i.h < t->dim && i.h && (t->dim = i.h))
		return (1);
	while (++i.l < 4 && ((x != t->n && p < t->mx * t->dim) || (i.h = t->dim)))
		if (i.h >= t->dim || (t->tet[x][i.l] && p / t->mx + i.l > t->dim))
			return (0);
	while (i.l--)
		if (t->tet[x][i.l] << p % t->mx & t->box[p / t->mx + i.l])
			return (ft_fillsolve(t, x, p + 1));
	while (++i.l < 4)
		t->box[p / t->mx + i.l] |= t->tet[x][i.l] << p % t->mx;
	if ((i.h = ft_fillsolve(t, x + 1, 0)))
		if (((t->pos[x] = p) && !p) || (t->dim + 1) * (t->dim + 1) < t->n * 4)
			return (i.h);
	while (i.l--)
		t->box[p / t->mx + i.l] ^= t->tet[x][i.l] << p % t->mx;
	return (ft_fillsolve(t, x, p + 1) || i.h);
}

void	ft_fillprint(t_fill t)
{
	char	**b;
	t_count	i;
	int		k;

	i.l = 0;
	if (!(b = (char **)malloc(sizeof(*b) * t.dim)))
		ft_usage_error(0);
	while (!i.l || (b[i.l - 1][t.dim] = 0) || i.l < t.dim)
		if (!(b[i.l] = (char*)malloc(t.dim + 1)) || !(++i.l))
			ft_usage_error(0);
	while (i.l-- && (i.c = -1))
		while (++i.c < t.dim)
			b[i.l][i.c] = '.';
	k = -1;
	i.c = 0;
	while (!(i.l = 0) && ++k < t.n)
		while (i.c++ < 8 || (!(i.c = 0) && ++i.l < 4))
			if (t.tet[k][i.l] & 1 << i.c)
				b[t.pos[k] / t.mx + i.l][t.pos[k] % t.mx - 4 + i.c] = k + 'A';
	while (!i.l || (write(1, "\n", 1) && i.l < t.dim))
		write(1, b[i.l++], t.dim);
}
