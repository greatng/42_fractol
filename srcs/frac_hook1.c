/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frac_hook1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pngamcha <pngamcha@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 11:25:06 by pngamcha          #+#    #+#             */
/*   Updated: 2022/04/12 23:13:13 by pngamcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	move(t_fract *m, char key)
{
	if (key == 'l')
		m->x_o += 25;
	else if (key == 'r')
		m->x_o -= 25;
	else if (key == 'u')
		m->y_o += 25;
	else if (key == 'd')
		m->y_o -= 25;
}

static void	zoom(t_fract *m, char key)
{
	double	start_x;
	double	start_y;

	start_x = WIDTH / 2;
	start_y = HEIGHT / 2;
	if (key == 'z')
	{
		m->off.x += (m->x_o - start_x) * (m->zoom / SCALE);
		m->off.y += (m->y_o - start_y) * (m->zoom / SCALE);
		m->zoom *= 2;
	}
	else if (key == 'x')
	{
		m->zoom /= 2;
		m->off.x -= (m->x_o - start_x) * (m->zoom / SCALE);
		m->off.y -= (m->y_o - start_y) * (m->zoom / SCALE);
	}
}

int	keyhook(int keycode, t_fract *m)
{
	if (keycode == KEY_ESC)
		close_win(m);
	else if (keycode == KEY_Z)
		zoom(m, 'z');
	else if (keycode == KEY_X)
		zoom(m, 'x');
	else if (keycode == KEY_UP)
		move(m, 'u');
	else if (keycode == KEY_DOWN)
		move(m, 'd');
	else if (keycode == KEY_RIGHT)
		move(m, 'r');
	else if (keycode == KEY_LEFT)
		move(m, 'l');
	else if (keycode == KEY_SPACE)
		reset_pos_z(m);
	else if (keycode == KEY_A)
		m->julia += 1;
	else if (keycode == KEY_C)
		m->color += 1;
	return (0);
}

int	mousehook(int mousecode, int x, int y, t_fract *m)
{
	if (mousecode == MOUSE_L && y >= 0)
	{
		if (x < m->x_o)
			m->x_o = m->x_o + ((WIDTH / 2) - (double)x);
		else
			m->x_o = m->x_o - ((double)x - (WIDTH / 2));
		if (y < m->y_o)
			m->y_o = m->y_o + ((HEIGHT / 2) - (double)y);
		else
			m->y_o = m->y_o - ((double)y - (HEIGHT / 2));
		
	}
	else if (mousecode == MOUSE_UP)
		zoom(m, 'z');
	else if (mousecode == MOUSE_DOWN)
		zoom(m, 'x');
	return (0);
}

int	main_loop(t_fract *m)
{
	frac_plot(*m);
	mlx_put_image_to_window(m->mlx, m->win, m->image, 0, 0);
	put_str_mlx(*m, m->frac);
	return (0);
}

void	reset_pos_z(t_fract *m)
{
	m->zoom = SCALE;
	m->x_o = WIDTH / 2;
	m->y_o = HEIGHT / 2;
	m->off.x = 0;
	m->off.y = 0;
}

double	x_scale(t_fract *m, int x)
{
	double	ret;

	ret = ((double)x / m->zoom) - ((m->x_o + m->off.x)/ m->zoom);
	return (ret);
}

double	y_scale(t_fract *m, int y)
{
	double	ret;

	ret = ((double)y / m->zoom) - ((m->y_o + m->off.y)/ m->zoom);
	return (ret);
}
