/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwozniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 10:39:12 by jwozniak          #+#    #+#             */
/*   Updated: 2018/03/10 10:39:14 by jwozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	move_frame(int key, t_frame *f)
{
	double	w;
	double	h;

	w = (f->xmax - f->xmin) * f->zoom;
	h = (f->ymax - f->ymin) * f->zoom;
	if (key == 123)
		f->offx -= w * 0.05;
	else if (key == 125)
		f->offy += h * 0.05;
	else if (key == 124)
		f->offx += w * 0.05;
	else if (key == 126)
		f->offy -= h * 0.05;
}

int		key_pressed(int key, t_glob *gg)
{
	if (key == 53)
		exit(1);
	else if (key >= 123 && key <= 126)
		move_frame(key, gg->frame);
	else if (key == 18)
		gg->colors = get_palette(1);
	else if (key == 19)
		gg->colors = get_palette(2);
	else if (key == 20)
		gg->colors = get_palette(3);
	else
		return (0);
	draw(gg);
	return (0);
}

int		mouse_move(int x, int y, t_glob *gg)
{
	*(gg->mouse) = make_complex(x, y, gg->frame);
	draw(gg);
	return (0);
}

int		mouse_zoom(int button, int x, int y, t_glob *gg)
{
	if (button == 4)
		zoom(x, y, gg->frame, 1 / ZOOM);
	else if (button == 5)
		zoom(x, y, gg->frame, ZOOM);
	draw(gg);
	return (0);
}
