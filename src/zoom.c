/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwozniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 10:40:27 by jwozniak          #+#    #+#             */
/*   Updated: 2018/03/10 10:40:30 by jwozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void		zoom(int x, int y, t_frame *f, double z)
{
	double	w;
	double	h;
	double	new_w;
	double	new_h;

	w = (f->xmax - f->xmin) * (f->zoom);
	h = (f->ymax - f->ymin) * (f->zoom);
	new_w = (f->xmax - f->xmin) * (f->zoom * z);
	new_h = (f->ymax - f->ymin) * (f->zoom * z);
	f->zoom *= z;
	f->offx -= ((double)x / WIDTH) * (new_w - w);
	f->offy -= ((double)y / HEIGHT) * (new_h - h);
}

t_complex	make_complex(int x, int y, t_frame *f)
{
	t_complex	c;

	c.r = ((double)x / WIDTH) * (f->xmax - f->xmin) * f->zoom
		+ f->xmin + f->offx;
	c.i = ((double)y / HEIGHT) * (f->ymax - f->ymin) * f->zoom
		+ f->ymin + f->offy;
	return (c);
}
