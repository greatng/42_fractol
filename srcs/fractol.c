/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pngamcha <pngamcha@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 23:53:04 by pngamcha          #+#    #+#             */
/*   Updated: 2022/04/07 18:28:06 by pngamcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static t_fract	fractol_init(void)
{
	t_fract	mlx;
	
	mlx.width = 400;
	mlx.height = 400;
	mlx.mlx = mlx_init();
	if (!mlx.mlx)
		exit(1);
	mlx.win = mlx_new_window(mlx.mlx, mlx.width, mlx.height, "Frac_u");
	mlx.image = mlx_new_image(mlx.mlx, mlx.width, mlx.height);
	if (!mlx.image || !mlx.win)
		exit(1);
	mlx.buffer = mlx_get_data_addr(mlx.image, &mlx.pixelb, 
		&mlx.lineb, &mlx.endian);
	if (!mlx.buffer)
		exit(1);
	mlx.zoom = 1;
	mlx.pos_x = 2;
	mlx.pos_y = 2;
	return (mlx);
}

static void	frac_u(void)
{
	ft_printf("How to use :\n> ./fractol {fractol name}\n");
	ft_printf("1 : mandelbrot\n2 : julia {1 - 6}\n");
	ft_printf("ex : ./fractol julia 6\n");
	exit (1);
}

static void	arg_check(int argc, char **argv, t_fract *mlx)
{
	if (argc == 1 || argc > 3)
		frac_u();
	if (!ft_strncmp(argv[1], "mandelbrot", 11))
	{
		ft_strlcpy(mlx->frac, "fractol : mandelbrot", 21);
		mlx->type = 1;
	}
	else if (!ft_strncmp(argv[1], "julia", 6))
	{
		ft_strlcpy(mlx->frac, "fractol : julia", 16);
		mlx->type = 2;
	}
	else
		frac_u();
}

int	main(int argc, char **argv)
{
	t_fract	mlx;

	mlx = fractol_init();
	arg_check(argc, argv, &mlx);
	if (mlx.type == 2)
	{
		if (argc != 3)
			frac_u();
		mlx.julia = ft_atoi(argv[2]);
		if (!(mlx.julia >= 1 && mlx.julia <= 6))
			frac_u();
	}
	mlx_key_hook(mlx.win, &keyhook, &mlx);
	//mlx_mouse_hook(mlx.win, &close_win, &mlx);
	mlx_loop_hook(mlx.mlx, &main_loop, &mlx);
	mlx_loop(mlx.mlx);
}
