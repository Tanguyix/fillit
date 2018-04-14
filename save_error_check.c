/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_error_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboissel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 13:31:24 by tboissel          #+#    #+#             */
/*   Updated: 2018/04/14 13:43:51 by tboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
void	ft_putstr(char *str);
void	ft_putchar(char c);

void		ft_error_exit()
{
	ft_putstr("error\n");
	exit(0);
}

void		ft_make_char(char c, t_tetro)
{
	
}

void		ft_read_check(int fd)
{
	char	buf;
	int		line_count;
	int		char_count;

	line_count = 0;
	char_count = 0;
	while (read(fd, &buf, 1))
	{
		if (line_count == 0)
			ft_init_tetromino();
		if (char_count <= 4 && line_count != 5)
			ft_make_char(buf);
		if (char_count == 5)
		{	
			if (buf != '\n')
				ft_error_exit();
			line_count++;
		}
		if (line_count == 5)
		{
			if (buf != '\n')
				ft_error_exit();
			line_count = 0;
			char_count = -1;
		}
			char_count++;
	}		
}


int			main(int ac, char **av)
{
	int		fd;

	fd = open(av[1], O_RDONLY);
	ft_read_check(fd);
}
