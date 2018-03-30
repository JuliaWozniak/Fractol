/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwozniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 10:39:53 by jwozniak          #+#    #+#             */
/*   Updated: 2018/03/10 10:39:55 by jwozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	draw(t_glob *gg)
{
	clear_image(gg);
	if ((ft_strequ(gg->name, "mandelbrot")))
		mandelbrot(gg);
	if ((ft_strequ(gg->name, "julia")))
		julia(gg);
	if ((ft_strequ(gg->name, "burningship")))
		ship(gg);
	mlx_put_image_to_window(gg->mlx->m_p, gg->mlx->w_p, gg->img->image, 0, 0);
}

int		main(int argc, char **argv)
{
	t_glob	*gg;

	if (argc == 1)
		print_possible();
	check_input(argv[1]);
	gg = init_glob(argv[1]);
	draw(gg);
	mlx_key_hook(gg->mlx->w_p, key_pressed, gg);
	mlx_mouse_hook(gg->mlx->w_p, mouse_zoom, gg);
	mlx_hook(gg->mlx->w_p, 6, 1L << 6, mouse_move, gg);
	mlx_loop(gg->mlx->m_p);
	return (0);
}
