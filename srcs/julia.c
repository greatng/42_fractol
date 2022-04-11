/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pngamcha <pngamcha@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 21:08:53 by pngamcha          #+#    #+#             */
/*   Updated: 2022/04/11 14:37:15 by pngamcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static double	julia_x(t_fract m)
{
	int	type;

	type = m.julia % 6;
	if (type == 0)
		return (-0.4);
	else if (type == 1)
		return (0.285);
	else if (type == 2)
		return (-0.70176);
	else if (type == 3)
		return (-0.835);
	else if (type == 4)
		return (-0.8);
	else
		return (-0.7269);
}

static double	julia_y(t_fract m)
{
	int	type;

	type = m.julia % 6;
	if (type == 0)
		return (0.6);
	else if (type == 1)
		return (0.01);
	else if (type == 2)
		return (-0.3842);
	else if (type == 3)
		return (-0.2321);
	else if (type == 4)
		return (0.156);
	else
		return (0.1889);
}

int	julia(t_fract m, double x, double y)
{
	double		x0;
	double		y0;
	double		x2;
	double		y2;
	static int	i;

	if ((int)(x + y) % 2)
		return (i / 1.8);
	x = x_scale(m, x);
	y = y_scale(m, y);
	x0 = julia_x(m);
	y0 = julia_y(m);
	i = 0;
	x2 = pow(x, 2);
	y2 = pow(y, 2);
	while (x2 + y2 <= 4 && ++i < 256)
	{
		y = 2 * x * y + y0;
		x = x2 - y2 + x0;
		x2 = pow(x, 2);
		y2 = pow(y, 2);
	}
	return (i - 1);
}
