/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frac_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pngamcha <pngamcha@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 11:25:41 by pngamcha          #+#    #+#             */
/*   Updated: 2022/04/05 12:52:16 by pngamcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	frac_shape_color(t_fract mlx, double x, double y, int type)
{
	if (type == 1)
		return (pow(mandelbrot(mlx, x, y), 2.5));
	return (mlx.color + (mandelbrot(mlx, x, y) * 5));
}
