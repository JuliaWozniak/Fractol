/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwozniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 10:38:50 by jwozniak          #+#    #+#             */
/*   Updated: 2018/03/10 10:38:53 by jwozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int		*red_palette(void)
{
	static int arr[10];

	arr[0] = 0x000000;
	arr[1] = 0x330d00;
	arr[2] = 0x661a00;
	arr[3] = 0x992600;
	arr[4] = 0xcc3300;
	arr[5] = 0xff4000;
	arr[6] = 0xff6633;
	arr[7] = 0xff8c66;
	arr[8] = 0xffb399;
	arr[9] = 0x1a0600;
	return (arr);
}

int		*violet_palette(void)
{
	static int arr[10];

	arr[0] = 0x000000;
	arr[1] = 0x1a0033;
	arr[2] = 0x330066;
	arr[3] = 0x4d0099;
	arr[4] = 0x6600cc;
	arr[5] = 0x8000ff;
	arr[6] = 0x9933ff;
	arr[7] = 0xb366ff;
	arr[8] = 0xcc99ff;
	arr[9] = 0xe6ccff;
	return (arr);
}

int		*sun_palette(void)
{
	static int arr[10];

	arr[0] = 0xf00000;
	arr[1] = 0xfd1bff;
	arr[2] = 0x3ccdec;
	arr[3] = 0x2fff00;
	arr[4] = 0xe8ff29;
	arr[5] = 0xf00000;
	arr[6] = 0xfd1bff;
	arr[7] = 0x3ccdec;
	arr[8] = 0x2fff00;
	arr[9] = 0xe8ff29;
	return (arr);
}

int		*get_palette(int type)
{
	int *palette;

	if (type == 1)
		palette = red_palette();
	else if (type == 2)
		palette = violet_palette();
	else if (type == 3)
		palette = sun_palette();
	else
		palette = red_palette();
	return (palette);
}
