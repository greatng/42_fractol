/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frac_hook1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pngamcha <pngamcha@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 11:25:06 by pngamcha          #+#    #+#             */
/*   Updated: 2022/04/07 23:02:59 by pngamcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	keyhook(int keycode, t_fract *mlx)
{
	if (keycode == KEY_ESC)
		exit(0);
	else if (keycode == KEY_Z)
		mlx->zoom *= 1.1;
	else if (keycode == KEY_X)
		mlx->zoom /= 1.1;
	else if (keycode == KEY_UP)
		mlx->pos_y += 0.25;
	else if (keycode == KEY_DOWN)
		mlx->pos_y -= 0.25;
	else if (keycode == KEY_RIGHT)
		mlx->pos_x -= 0.25;
	else if (keycode == KEY_LEFT)
		mlx->pos_x += 0.25;
	else if (keycode == KEY_SPACE)
		reset_pos_z(mlx);
	else if (keycode == KEY_C)
		mlx->julia += 1;
	else if (keycode == KEY_A)
		mlx->color += 1;
	return (0);
}

int	main_loop(t_fract *mlx)
{
	frac_plot(*mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->image, 0, 0);
	put_str_mlx(mlx->mlx, mlx->win, mlx->height, mlx->frac);
	return (0);
}

void	reset_pos_z(t_fract *mlx)
{
	mlx->zoom = 1;
	mlx->pos_x = 2;
	mlx->pos_y = 2;
}
