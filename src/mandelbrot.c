/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwozniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 10:40:05 by jwozniak          #+#    #+#             */
/*   Updated: 2018/03/10 10:40:07 by jwozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int		is_in_m(t_complex z, t_complex c, t_glob *gg)
{
	double	tmp;
	int		i;

	i = 0;
	while (i < MAX_ITER)
	{
		tmp = z.r * z.r - z.i * z.i + c.r;
		z.i *= 2 * z.r;
		z.i += c.i;
		z.r = tmp;
		if (z.r * z.r + z.i * z.i > 4.0)
			return (gg->colors[i % 10]);
		i++;
	}
	return (0xffffff);
}

void	mandelbrot(t_glob *gg)
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
			c = make_complex(x, y, gg->frame);
			set_pixel(gg->img->image, x, y,
				is_in_m(z, c, gg));
			x++;
		}
		y++;
	}
}
