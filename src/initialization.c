/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwozniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 10:39:31 by jwozniak          #+#    #+#             */
/*   Updated: 2018/03/10 10:39:33 by jwozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

t_img		*create_image(void *mlx)
{
	t_img	*img;

	img = (t_img *)ft_memalloc(sizeof(t_img));
	img->image = mlx_new_image(mlx, WIDTH, HEIGHT);
	img->ptr = mlx_get_data_addr(img->image, &img->bpp, &img->strd, &img->endn);
	return (img);
}

t_mlx		*init_mlx(char *name)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)ft_memalloc(sizeof(t_mlx));
	mlx->m_p = mlx_init();
	mlx->w_p = mlx_new_window(mlx->m_p, WIDTH, HEIGHT, name);
	return (mlx);
}

t_frame		*init_frame(char *name)
{
	t_frame	*frame;

	frame = (t_frame *)malloc(sizeof(t_frame));
	frame->xmin = -2.0;
	frame->xmax = 1.0;
	frame->ymin = -1.5;
	frame->ymax = 1.5;
	if (ft_strequ("burningship", name))
	{
		frame->ymin = -2.0;
		frame->ymax = 1.0;
	}
	if (ft_strequ("julia", name))
	{
		frame->xmax = 2.0;
		frame->ymin = -2.0;
		frame->ymax = 2.0;
	}
	frame->zoom = 1.0;
	frame->offx = 0;
	frame->offy = 0;
	return (frame);
}

t_complex	*init_mouse(void)
{
	t_complex	*mouse;

	mouse = (t_complex *)ft_memalloc(sizeof(t_complex));
	mouse->r = 0;
	mouse->i = 0;
	return (mouse);
}

t_glob		*init_glob(char *name)
{
	t_glob	*gg;

	gg = (t_glob *)ft_memalloc(sizeof(t_glob));
	gg->mlx = init_mlx(name);
	gg->img = create_image(gg->mlx->m_p);
	gg->frame = init_frame(name);
	gg->name = ft_strdup(name);
	gg->colors = get_palette(2);
	gg->mouse = init_mouse();
	*(gg->mouse) = make_complex(0, 0, gg->frame);
	return (gg);
}
