/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usage.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboissel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 14:51:06 by tboissel          #+#    #+#             */
/*   Updated: 2018/04/16 11:32:20 by tboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fillit.h"

void	ft_usage()
{
	ft_putstr("Usage: Creates the smallest array \
with the tetrominos given in the file\n\n");
	ft_putstr("Use fillit with one file with 1 to 26 tetrominoes\n");
	ft_putstr("Tetromineos should be separated by one line\n");
	ft_putstr("and displayed in a 4x4 square of dots (.) and hashes (#)\n\n");
	ft_putstr("Example of a correct imput file:\n..##\n.##.\n....\n....\n\n");
	ft_putstr(".#..\n.#..\n.#..\n.#..\n");
}

void	ft_error()
{
	ft_putstr("error\n");
	exit(0);
}
