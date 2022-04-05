/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frac_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pngamcha <pngamcha@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 11:25:06 by pngamcha          #+#    #+#             */
/*   Updated: 2022/04/05 13:13:21 by pngamcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	keyhook(int keycode, t_fract *mlx)
{
	if (keycode == KEY_ESC)
		exit(0);
	if (keycode == KEY_Z)
		mlx->zoom += 0.25;
	printf("zoom %fx\n", mlx->zoom);
	return (0);
}