/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frac_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pngamcha <pngamcha@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 10:43:40 by pngamcha          #+#    #+#             */
/*   Updated: 2022/04/10 21:10:21 by pngamcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	close_win(t_fract *m)
{
	mlx_destroy_image(m->mlx, m->image);
	mlx_destroy_window(m->mlx, m->win);
	exit(0);
}
