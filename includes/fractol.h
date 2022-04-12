/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pngamcha <pngamcha@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 23:57:36 by pngamcha          #+#    #+#             */
/*   Updated: 2022/04/12 22:57:48 by pngamcha         ###   ########.fr       */
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

//Event name. Used in "type field"
//Keyboard
# define KEYPRESS		2
# define KEYRELEASE		3
# define DESTROY_WINDOW		17

//Mouse
# define BUTTONPRESS		4
# define BUTTONRELEASE		5

//Mousecode
# define MOUSE_L		1
# define MOUSE_UP		4
# define MOUSE_DOWN		5
# define MOUSE_MID		3

//Keyboard code
# define KEY_ESC		53
# define KEY_A			0
# define KEY_C			8
# define KEY_Z			6
# define KEY_X			7
# define KEY_LEFT		123
# define KEY_RIGHT		124
# define KEY_UP			126
# define KEY_DOWN		125
# define KEY_SPACE		49

//Windows size
# define WIDTH			500
# define HEIGHT			500
// 1 unit = 100 pixel
# define SCALE			200

//Offset
typedef struct s_offset
{
	int	x;
	int	y;
}	t_offset;

//Image Stuff
typedef struct	s_win
{
	int	pixelb;
	int	lineb;
	int	endian;
}	t_win;

//Mlx content
typedef struct	s_fract
{
	void	*mlx;
	void	*win;
	void	*image;
	int	p_color;
	int	color;
	int	julia;
	int	type;
	char	*buffer;
	char	frac[25];
	double	zoom;
	double	x_o;
	double	y_o;
	t_win		win_mem;
	t_offset	off;
}	t_fract;

//Prototypes
void	frac_plot(t_fract m);
void	reset_pos_z(t_fract *m);
void	put_str_mlx(t_fract m, char *str);
int	burningship(t_fract m, double x, double y);
int	mandelbrot(t_fract m, double x, double y);
int	julia(t_fract m, double x, double y);
int	keyhook(int keycode, t_fract *m);
int	mousehook(int mousecode, int x, int y, t_fract *m);
int	frac_shape_color(t_fract m, double x, double y, int type);
int	close_win(t_fract *m);
int	main_loop(t_fract *m);
double	x_scale(t_fract *m, int x);
double	y_scale(t_fract *m, int y);

#endif