/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pngamcha <pngamcha@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 21:08:53 by pngamcha          #+#    #+#             */
/*   Updated: 2022/04/07 00:05:33 by pngamcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	julia(t_fract mlx, double x, double y)
{
	double	x0;
	double	y0;
	double	x2;
	double	y2;
	int		i;

	x = x_scale(mlx, x);
	y = y_scale(mlx, y);
	x0 = -0.4;
	y0 = 0.6;
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
