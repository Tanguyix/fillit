/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboissel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 11:55:54 by tboissel          #+#    #+#             */
/*   Updated: 2018/04/16 15:12:24 by tboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fillit.h"

t_fill		ft_init_struct(void)
{
	t_fill	tetroes;
	int		i;

	i = 0;
	while (i < 26)
		if (!(tetroes.tet[i++] = (unsigned char*)malloc(sizeof(char) * 4)))
			ft_error();
	tetroes.n = -1;
	return (tetroes);
}

int			main(int ac, char **av)
{
	t_fill	tetroes;
	int		fd;

	tetroes = ft_init_struct();
	if (ac != 2)
		ft_usage();
	else
	{
		fd = open(av[1], O_RDONLY);
		ft_read_check(fd, tetroes);
	}
	return (0);
}
