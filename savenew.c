/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_error_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboissel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 13:31:24 by tboissel          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2018/04/16 11:06:40 by twalpert         ###   ########.fr       */
=======
/*   Updated: 2018/04/16 09:46:18 by tboissel         ###   ########.fr       */
>>>>>>> 113d07ce943c5d5b0e5a7a5d9e559871704331f5
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
void	ft_putstr(char *str);
void	ft_putchar(char c);

<<<<<<< HEAD
t_tetro		ft_read_check(int fd, t_tetro tetroes)
=======
void		ft_make_char(char c, t_tetro *tetroes, int char_count, int line, int n)
{
	int		valeur;

	valeur = 8;
	if (c != '.' && c != '#')
		ft_error_exit();
	if (c == '#')
	{
		while (char_count--)
			valeur = valeur /2;
		tetroes->tet[n][line_count] += valeur;
	}
}

t_tetro		ft_read_check(int fd, t_tetro *tetroes)
>>>>>>> 113d07ce943c5d5b0e5a7a5d9e559871704331f5
{
	char	buf;
	int		i[4];

	i[0] = 1;		/*line_count*/
	i[1] = 16;		/*char_count i[2] = # count*/
	while (read(fd, &buf, 1) && (buf == '.' || buf == '#' || buf == '\n'))
	{
<<<<<<< HEAD
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
			
=======
		if (line_count == 0)
			tetroes->n++;
		if (char_count < 4 && line_count != 4)
			ft_make_char(buf, tetroes, char_count, line_count, tetroes->n);
		if (line_count == 4)
		{
			if (buf != '\n')
				ft_error_exit();
			line_count = 0;
		}
		if (char_count == 4)
		{
			if (buf != '\n')
				ft_error_exit();
			line_count++;
			char_count = -1;
		}
			char_count++;
>>>>>>> 113d07ce943c5d5b0e5a7a5d9e559871704331f5
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
