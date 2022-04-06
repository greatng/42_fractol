/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frac_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pngamcha <pngamcha@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 11:25:41 by pngamcha          #+#    #+#             */
/*   Updated: 2022/04/07 00:30:00 by pngamcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	frac_shape_color(t_fract mlx, double x, double y, int type)
{
	static int	color[256];
	static int	gen;
	int			ret_col;
	int			i;

	i = 0;
	if (gen == 0)
	{
		gen += 1;
		while (i++ < 255)
			color[i] = pow(i, 2) - 1;
	}
	if (!ft_strncmp(mlx.frac, "fractol : julia", 16))
	{
		ret_col = julia(mlx, x, y) * 65793;
		//ret_col = (mlx.color + color[julia(mlx, x, y)]) % 16777216;
	}
	else if (!ft_strncmp(mlx.frac, "fractol : mandelbrot", 21))
	{
		ret_col = mandelbrot(mlx, x, y) * 65793;
		//ret_col = (mlx.color + color[mandelbrot(mlx, x, y)]) % 16777216;
	}
	return (ret_col);
}
