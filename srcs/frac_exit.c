/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frac_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pngamcha <pngamcha@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 10:43:40 by pngamcha          #+#    #+#             */
/*   Updated: 2022/04/07 10:43:52 by pngamcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	close_win(t_fract *mlx)
{
	mlx_destroy_image(mlx->mlx, mlx->image);
	mlx_destroy_window(mlx->mlx, mlx->win);
	exit(0);
}
