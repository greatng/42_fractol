/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pngamcha <pngamcha@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 10:43:01 by pngamcha          #+#    #+#             */
/*   Updated: 2022/04/18 12:54:27 by pngamcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	mandelbrot(t_fract m, double x, double y)
{
	double		x0;
	double		y0;
	double		x2;
	double		y2;
	static int	i;

	x0 = x_scale(&m, x);
	y0 = y_scale(&m, y);
	i = 0;
	x = 0;
	y = 0;
	x2 = 0;
	y2 = 0;
	while (x2 + y2 <= 4 && ++i < 190)
	{
		y = 2 * x * y + y0;
		x = x2 - y2 + x0;
		x2 = pow(x, 2);
		y2 = pow(y, 2);
	}
	return (i);
}
