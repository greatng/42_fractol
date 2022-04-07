/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frac_plot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pngamcha <pngamcha@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 12:50:48 by pngamcha          #+#    #+#             */
/*   Updated: 2022/04/07 18:34:48 by pngamcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	put_str_mlx(void *m, void *w, int h, char *str)
{
	int		white;

	white = 0xFFFFFF;
	mlx_string_put(m, w, 10, 20, white, str);
	mlx_string_put(m, w, 10, h - 20, white, "esc: exit, scroll wheel: zoom");
	mlx_string_put(m, w, 10, h - 10, white, "z: zoom in, x: zoom out, "
		"arrow: move, space: reset");
}

void	frac_plot(t_fract mlx)
{
	double	x;
	double	y;
	int		pixel;

	y = 0;
	while (y < mlx.height)
	{
		x = 0;
		while (x < mlx.width)
		{
			mlx.p_color = frac_shape_color(mlx, x, y, mlx.type);
			pixel = (y * mlx.lineb) + (x * 4);
			mlx.buffer[pixel + 0] = (mlx.p_color) & 0xFF;
			mlx.buffer[pixel + 1] = (mlx.p_color >> 8) & 0xFF;
			mlx.buffer[pixel + 2] = (mlx.p_color >> 16) & 0xFF;
			mlx.buffer[pixel + 3] = (mlx.p_color >> 24);
			x += 1;
		}
		y += 1;
	}
}
