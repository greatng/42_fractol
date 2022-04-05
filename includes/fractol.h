/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pngamcha <pngamcha@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 23:57:36 by pngamcha          #+#    #+#             */
/*   Updated: 2022/04/05 13:10:04 by pngamcha         ###   ########.fr       */
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


#define X_EVENT_KEY_PRESS

# define KEY_ESC		53
# define KEY_Q			12
# define KEY_W			13
# define KEY_E			14
# define KEY_R			15
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2
# define KEY_Z			6

typedef struct	s_fract
{
	void	*mlx;
	void	*win;
	void	*image;
	int	width;
	int	height;
	int	color;
	int	p_color;
	int	pixelb;
	int	lineb;
	int	endian;
	char	*buffer;
	char	frac[20];
	double	zoom;
}	t_fract;

void	frac_plot(t_fract mlx);
int	mandelbrot(t_fract mlx, double x, double y);
int	keyhook(int keycode, t_fract *mlx);
int	frac_shape_color(t_fract mlx, double x, double y, int type);
double	x_scale(t_fract mlx, double *x);
double	y_scale(t_fract mlx, double *s);

#endif