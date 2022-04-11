/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frac_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pngamcha <pngamcha@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 23:32:43 by pngamcha          #+#    #+#             */
/*   Updated: 2022/04/10 21:10:36 by pngamcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static int	get_color(int iter, int type, int mode)
{
	static int	color[256];
	static int	i;
	static int	old_mode;

	if (mode != old_mode)
		i = 0;
	old_mode = mode;
	while (i < 256)
	{
		if (mode % 4 == 1)
			color[i] = i * pow(2, 18);
		else if (mode % 4 == 2)
			color[i] = i * pow(2, 9);
		else if (mode % 4 == 3 || (i >= 190 && type == 2))
			color[i] = i * 65793;
		else if (type == 3)
			color[i] = i * pow(2, 3);
		else if (i < 85)
			color[i] = i * 3 + 1;
		else if (i < 190)
			color[i] = i * 256;
		i++;
	}
	return ((int)color[iter]);
}

int	frac_shape_color(t_fract m, double x, double y, int type)
{
	int			iter;

	if (type == 2)
		iter = julia(m, x, y);
	else if (type == 1)
		iter = mandelbrot(m, x, y);
	else if (type == 3)
		iter = burningship(m, x, y);
	return (get_color(iter, type, m.color));
}
