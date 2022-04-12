/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pngamcha <pngamcha@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 10:43:01 by pngamcha          #+#    #+#             */
/*   Updated: 2022/04/12 22:47:19 by pngamcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static int	log_color(int i, double x2, double y2)
{
	double	log_zn;
	double	n;

	if (i < 256)
	{
		log_zn = log(x2 + y2) / 2.0f;
		n = log(log_zn / log(2)) / log(2);
		i = i + 1 - n;
	}
	if (i < 0)
		i = 0;
	return (i);
}

int	mandelbrot(t_fract m, double x, double y)
{
	double		x0;
	double		y0;
	double		x2;
	double		y2;
	static int	i;

	if ((int)(x + y) % 2)
		return (i / 1.8);
	x0 = x_scale(&m, x);
	y0 = y_scale(&m, y);
	i = 0;
	x = 0;
	y = 0;
	x2 = 0;
	y2 = 0;
	while (x2 + y2 <= 4 && ++i < 256)
	{
		y = 2 * x * y + y0;
		x = x2 - y2 + x0;
		x2 = pow(x, 2);
		y2 = pow(y, 2);
	}
	return (log_color(i, x2, y2));
}
