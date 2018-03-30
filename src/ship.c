/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ship.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwozniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 10:40:14 by jwozniak          #+#    #+#             */
/*   Updated: 2018/03/10 10:40:16 by jwozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int		is_in_s(t_complex z, t_complex c, t_glob *gg)
{
	t_complex	tmp;
	int			i;

	i = 0;
	while (i < MAX_ITER)
	{
		z.r = fabs(z.r);
		z.i = fabs(z.i);
		tmp.r = z.r * z.r - z.i * z.i + c.r;
		tmp.i = z.r * z.i * 2 + c.i;
		if (z.r == tmp.r && z.i == tmp.i)
			return (0x000000);
		z.r = tmp.r;
		z.i = tmp.i;
		i++;
		if (z.r * z.r + z.i * z.i > 4.0)
			return (gg->colors[i % 10]);
	}
	return (0x000000);
}

void	ship(t_glob *gg)
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
				is_in_s(z, c, gg));
			x++;
		}
		y++;
	}
}
