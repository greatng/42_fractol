/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frac_plot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pngamcha <pngamcha@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 12:50:48 by pngamcha          #+#    #+#             */
/*   Updated: 2022/04/18 12:45:46 by pngamcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	put_str_mlx(t_fract m, char *str)
{
	int		white;

	white = 0xFFFFFF;
	mlx_string_put(m.mlx, m.win, 10, 20, white, str);
	mlx_string_put(m.mlx, m.win, 10, HEIGHT - 30, white, "esc:\
		 exit, scroll wheel: zoom");
	mlx_string_put(m.mlx, m.win, 10, HEIGHT - 20, white, "left mouse: \
		move to position, right mouse: zoom");
	mlx_string_put(m.mlx, m.win, 10, HEIGHT - 10, white, \
		"z: zoom in, x: zoom out, \
		arrow: move, space: reset");
}

void	frac_plot(t_fract m)
{
	int	x;
	int	y;
	int	pixel;

	y = 0;
	while (y <= HEIGHT)
	{
		x = 0;
		while (x <= WIDTH)
		{
			if (x % (WIDTH / 2) == 0
				|| y % (HEIGHT / 2) == 0)
				m.p_color = 0x404040;
			else
				m.p_color = frac_shape_color(m, x, y, m.type);
			pixel = (y * m.win_mem.lineb) + (x * 4);
			m.buffer[pixel + 0] = (m.p_color) & 0xFF;
			m.buffer[pixel + 1] = (m.p_color >> 8) & 0xFF;
			m.buffer[pixel + 2] = (m.p_color >> 16) & 0xFF;
			m.buffer[pixel + 3] = (m.p_color >> 24);
			x++;
		}
		y++;
	}
}
