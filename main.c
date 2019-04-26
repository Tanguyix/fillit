/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboissel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 11:55:54 by tboissel          #+#    #+#             */
/*   Updated: 2018/04/19 10:40:25 by twalpert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fillit.h"

int			main(int ac, char **av)
{
	t_fill	tetroes;
	int		fd;
	int		i;

	if (ac != 2)
		ft_usage_error(1);
	else
	{
		fd = open(av[1], O_RDONLY);
		i = 0;
		while (i < 26)
			if (!(tetroes.tet[i++] = (unsigned char*)malloc(sizeof(char) * 4)))
				ft_usage_error(0);
		tetroes.n = -1;
		tetroes = ft_read_check(fd, tetroes);
		tetroes = ft_prepare(tetroes);
		if (ft_fillsolve(&tetroes, 0, 0))
			ft_fillprint(tetroes);
	}
	return (0);
}
