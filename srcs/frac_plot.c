/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frac_plot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pngamcha <pngamcha@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 12:50:48 by pngamcha          #+#    #+#             */
/*   Updated: 2022/04/05 12:52:00 by pngamcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static int	frac_type(char *frac)
{
	if (!ft_strncmp(frac, "fractol : mandelbrot", 21))
		return (1);
	return (1);
}

void	frac_plot(t_fract mlx)
{
	double	x;
	double	y;
	int	pixel;
	int	type;

	y = 0;
	type = frac_type(mlx.frac);
	while (y < mlx.height)
	{
		x = 0;
		while (x < mlx.width)
		{
			mlx.p_color = frac_shape_color(mlx, x, y, type);
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