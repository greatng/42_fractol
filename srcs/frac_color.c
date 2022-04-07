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

int	get_color(int iter)
{
	static int	color[256];
	static int	i;

	while (i < 256)
	{
		color[i] = i * 65737;
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
	return (get_color(iter));
}
