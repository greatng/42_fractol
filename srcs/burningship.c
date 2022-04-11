/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pngamcha <pngamcha@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 10:43:01 by pngamcha          #+#    #+#             */
/*   Updated: 2022/04/11 10:43:25 by pngamcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	burningship(t_fract m, double x, double y)
{
	double		x0;
	double		y0;
	double		x2;
	double		y2;
	static int	i;

	if ((int)(x + y) % 2)
		return (i / 1.8);
	x0 = x_scale(m, x) - 0.5;
	y0 = y_scale(m, y);
	i = 0;
	x = x0;
	y = y0;
	x2 = pow(x, 2);
	y2 = pow(y, 2);
	while (x2 + y2 < 4 && ++i < 64)
	{
		y = fabs(2 * y * x) + y0;
		x = x2 - y2 + x0;
		x2 = pow(x, 2);
		y2 = pow(y, 2);
	}
	return (i);
}
