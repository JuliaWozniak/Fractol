/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwozniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 10:39:40 by jwozniak          #+#    #+#             */
/*   Updated: 2018/03/10 10:39:42 by jwozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int		is_in_j(t_complex z, t_complex c, t_glob *gg)
{
	t_complex	tmp;
	int			i;

	i = 0;
	while (i < MAX_ITER)
	{
		tmp.r = z.r * z.r - z.i * z.i + c.r;
		tmp.i = z.r * z.i * 2 + c.i;
		if (z.r == tmp.r && z.i == tmp.i)
			return (0xffffff);
		z.r = tmp.r;
		z.i = tmp.i;
		if (z.r * z.r + z.i * z.i > 4.0)
			return (gg->colors[i % 10]);
		i++;
	}
	return (0xffffff);
}

void	julia(t_glob *gg)
{
	int			x;
	int			y;
	t_complex	z;
	t_complex	c;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			z = make_complex(x, y, gg->frame);
			c = *(gg->mouse);
			set_pixel(gg->img->image, x, y,
				is_in_j(z, c, gg));
			x++;
		}
		y++;
	}
}
