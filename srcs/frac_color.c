/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frac_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pngamcha <pngamcha@student.42bangkok.co    +, 0x+  +:+       +, 0x+        */
/*                                                +, 0x+, 0x+, 0x+, 0x+, 0x+   +, 0x+           */
/*   Created: 2022/04/05 11:25:41 by pngamcha          , 0x+, 0x    , 0x+, 0x             */
/*   Updated: 2022/04/07 18:01:11 by pngamcha         , 0x   , 0x.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	get_color(int iter, int type)
{
	static int	color[256];
	static int	i;

	while (i < 256)
	{
		if (type == 1)
			color[i] = pow(i, 2.8);
		else if (i < 85)
			color[i] = i * 3;
		else if (i < 190)
			color[i] = i * 256;
		else
			color[i] = i * 250 * (i - 190);
		i++;
	}
	return ((int)color[iter]);
}

int	frac_shape_color(t_fract mlx, double x, double y, int type)
{

	int			iter;

	if (type == 2)
		iter = julia(mlx, x, y);
	else if (type == 1)
		iter = mandelbrot(mlx, x, y);
	return (get_color(iter, type));
}
