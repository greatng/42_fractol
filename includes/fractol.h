/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pngamcha <pngamcha@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 23:57:36 by pngamcha          #+#    #+#             */
/*   Updated: 2022/04/08 00:37:15 by pngamcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "../mlx/mlx.h"
# include "../libft/libft.h"

# define KEY_ESC		53
# define KEY_Q			12
# define KEY_W			13
# define KEY_E			14
# define KEY_R			15
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2
# define KEY_C			8
# define KEY_Z			6
# define KEY_X			7
# define KEY_LEFT		123
# define KEY_RIGHT		124
# define KEY_UP			126
# define KEY_DOWN		125
# define KEY_SPACE		49

typedef struct	s_fract
{
	void	*mlx;
	void	*win;
	void	*image;
	int	width;
	int	height;
	int	p_color;
	int	color;
	int	pixelb;
	int	lineb;
	int	endian;
	int	julia;
	int	type;
	char	*buffer;
	char	frac[20];
	double	zoom;
	double	pos_x;
	double	pos_y;
}	t_fract;

typedef struct	s_color
{
	int	a;
	int	r;
	int	g;
	int	b;
}	t_color;

void	frac_plot(t_fract mlx);
void	reset_pos_z(t_fract *mlx);
void	put_str_mlx(void *m, void *w, int h, char *str);
int	burningship(t_fract mlx, double x, double y);
int	mandelbrot(t_fract mlx, double x, double y);
int	julia(t_fract mlx, double x, double y);
int	keyhook(int keycode, t_fract *mlx);
int	frac_shape_color(t_fract mlx, double x, double y, int type);
int	close_win(t_fract *mlx);
int	main_loop(t_fract *mlx);
double	x_scale(t_fract mlx, double x);
double	y_scale(t_fract mlx, double s);

#endif