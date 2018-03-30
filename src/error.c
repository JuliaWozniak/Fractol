/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwozniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 10:39:01 by jwozniak          #+#    #+#             */
/*   Updated: 2018/03/10 10:39:03 by jwozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	show_error(char *reason)
{
	ft_putendl(reason);
	exit(1);
}

void	print_possible(void)
{
	ft_putendl("\nplease, select fractal");
	ft_putendl("possible fractals:");
	ft_putendl("mandelbrot");
	ft_putendl("julia");
	ft_putendl("burningship\n");
	exit(1);
}

void	check_input(char *input)
{
	if (ft_strequ(input, "mandelbrot"))
		return ;
	if (ft_strequ(input, "julia"))
		return ;
	if (ft_strequ(input, "burningship"))
		return ;
	print_possible();
}
