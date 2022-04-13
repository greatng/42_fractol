/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frac_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pngamcha <pngamcha@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 11:25:06 by pngamcha          #+#    #+#             */
/*   Updated: 2022/04/13 16:57:03 by pngamcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

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
		if (x < WIDTH / 2)
			m->o.x += ((WIDTH / 2) - (double)x);
		else
			m->o.x -= ((double)x - (WIDTH / 2));
		if (y < HEIGHT / 2)
			m->o.y += ((HEIGHT / 2) - (double)y);
		else
			m->o.y -= ((double)y - (HEIGHT / 2));
	}
	else if (mousecode == MOUSE_R && y >= 0)
		zoom(m, 'z');
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
	m->o.x = WIDTH / 2;
	m->o.y = HEIGHT / 2;
	m->off.x = 0;
	m->off.y = 0;
}
