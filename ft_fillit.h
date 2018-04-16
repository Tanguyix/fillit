/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalpert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 16:35:19 by twalpert          #+#    #+#             */
/*   Updated: 2018/04/13 17:55:22 by twalpert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILLIT_H
# define FT_FILLIT_H

typedef struct	s_fill
{
	unsigned char	**tet;
	int				n;
	unsigned char	*box;
	int				*tpos;
	int				dim;
}				t_fill;

#endif
