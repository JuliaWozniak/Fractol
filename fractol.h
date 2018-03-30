/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwozniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 10:46:07 by jwozniak          #+#    #+#             */
/*   Updated: 2018/03/10 10:46:12 by jwozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include "./libft/includes/libft.h"
# include <math.h>

# define SIZE 950
# define MAX_ITER 40
# define WIDTH 950
# define HEIGHT 750
# define ZOOM 1.1

typedef struct	s_img
{
	void	*image;
	char	*ptr;
	int		bpp;
	int		strd;
	int		endn;
}				t_img;

typedef struct	s_frame
{
	double	xmax;
	double	xmin;
	double	ymax;
	double	ymin;
	double	zoom;
	double	offx;
	double	offy;
}				t_frame;

typedef struct	s_mlx
{
	void	*m_p;
	void	*w_p;
}				t_mlx;

typedef struct	s_complex
{
	double	r;
	double	i;
}				t_complex;

typedef struct	s_glob
{
	t_mlx		*mlx;
	t_img		*img;
	t_frame		*frame;
	int			*colors;
	char		*name;
	t_complex	*mouse;

}				t_glob;

void			check_input(char *input);
void			print_possible(void);
int				mouse_zoom(int button, int x, int y, t_glob *gg);
int				mouse_move(int x, int y, t_glob *gg);
int				key_pressed(int key, t_glob *gg);
t_glob			*init_glob();
t_complex		make_complex(int x, int y, t_frame *f);
void			set_pixel(t_img *img, int x, int y, int color);
void			clear_image(t_glob *gg);
int				*get_palette(int type);
void			zoom(int x, int y, t_frame *f, double z);
void			draw(t_glob *gg);
void			julia(t_glob *gg);
void			mandelbrot(t_glob *gg);
void			ship(t_glob *gg);

#endif
