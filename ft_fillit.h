/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalpert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 16:35:19 by twalpert          #+#    #+#             */
/*   Updated: 2018/04/20 15:41:04 by tboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILLIT_H
# define FT_FILLIT_H

# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct		s_fill
{
	unsigned char	*tet[26];
	int				n;
	unsigned int	*box;
	int				*pos;
	int				dim;
	int				mx;
}					t_fill;

typedef struct		s_count
{
	int				l;
	int				c;
	int				h;
}					t_count;

t_fill				ft_read_check(int fd, t_fill tetroes);
void				ft_usage_error(int i);
t_fill				ft_prepare(t_fill t);
int					ft_fillsolve(t_fill *t, int x, int p);
void				ft_fillprint(t_fill t);

#endif
