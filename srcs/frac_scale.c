/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frac_scale.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pngamcha <pngamcha@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 12:54:03 by pngamcha          #+#    #+#             */
/*   Updated: 2022/04/05 13:06:22 by pngamcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

double	x_scale(t_fract mlx, double *x)
{
	long double	ret;

	ret = (((*x / (mlx.width / 4)) - 2)) / mlx.zoom;
	*x = 0;
	return (ret);
}

double	y_scale(t_fract mlx, double *y)
{
	long double	ret;
	
	ret = ((2 + ((-1) * (*y /(mlx.height / 4)))) / mlx.zoom);
	*y = 0;
	return (ret);
}