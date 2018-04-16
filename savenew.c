/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_error_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboissel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 13:31:24 by tboissel          #+#    #+#             */
/*   Updated: 2018/04/16 11:26:09 by twalpert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
void	ft_putstr(char *str);
void	ft_putchar(char c);

t_tetro		ft_read_check(int fd, t_tetro tetroes)
{
	char	buf;
	int		i[4];

	i[0] = 1;		/*line_count*/
	i[1] = 16;		/*char_count i[2] = # count*/
	while (read(fd, &buf, 1) && (buf == '.' || buf == '#' || buf == '\n'))
	{
		if (i[0] == 1 && !(i[2] = 0))
			tetroes.n++;
		if (i[0] != 4 && (i[1] \= 2))
			if (c == '#' && ++i[2])
				tetroes.tet[n][i[0]] += i[1];
		if (buf !='\n' && (i[0] == 4 || !i[1]))
			ft_error_exit();
		if (i[0] == 4)
			i[0] = 0;
		if (!i[1] && ++i[0] && (i[1] = 16))
			
	}
	if (i[0] != 0 || tetroes.n == 0 || buf != '\n')
		ft_error_exit();
	return (tetroes);
}

int			main(int ac, char **av)
{
	int		fd;

	fd = open(av[1], O_RDONLY);
	ft_read_check(fd);
}
