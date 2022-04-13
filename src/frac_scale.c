/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frac_scale.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pngamcha <pngamcha@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 12:54:03 by pngamcha          #+#    #+#             */
/*   Updated: 2022/04/13 23:03:43 by pngamcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	move(t_fract *m, char key)
{
	if (key == 'l')
		m->off.x += 25;
	else if (key == 'r')
		m->off.x -= 25;
	else if (key == 'u')
		m->off.y += 25;
	else if (key == 'd')
		m->off.y -= 25;
}

void	zoom(t_fract *m, char key)
{
	double	start_x;
	double	start_y;

	start_x = WIDTH / 2;
	start_y = HEIGHT / 2;
	if (key == 'z')
	{
		m->off.x += (m->o.x - start_x) * (m->zoom / SCALE);
		m->off.y += (m->o.y - start_y) * (m->zoom / SCALE);
		m->zoom *= 2;
	}
	else if (key == 'x')
	{
		m->zoom /= 2;
		m->off.x -= (m->o.x - start_x) * (m->zoom / SCALE);
		m->off.y -= (m->o.y - start_y) * (m->zoom / SCALE);
	}
}

double	x_scale(t_fract *m, int x)
{
	double	ret;

	ret = ((double)x / m->zoom) - ((m->o.x + m->off.x) / m->zoom);
	return (ret);
}

double	y_scale(t_fract *m, int y)
{
	double	ret;

	ret = ((double)y / m->zoom) - ((m->o.y + m->off.y) / m->zoom);
	return (ret);
}
