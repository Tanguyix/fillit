/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboissel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 11:55:54 by tboissel          #+#    #+#             */
/*   Updated: 2018/04/16 13:57:12 by tboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fillit.h"

int			main(int ac, char **av)
{
	t_fill	tetroes;
	int		fd;

	if (ac != 2)
		ft_usage();
	else
	{
		fd = open(av[1], O_RDONLY);
		ft_read_check(fd, tetroes);
	}
	return (0);
}
