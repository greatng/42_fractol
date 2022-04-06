/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pngamcha <pngamcha@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 23:53:04 by pngamcha          #+#    #+#             */
/*   Updated: 2022/04/07 00:12:28 by pngamcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static t_fract	fractol_init(void)
{
	t_fract	mlx;
	int		pb;
	int		lb;
	int		end;

	mlx.width = 500;
	mlx.height = 500;
	mlx.mlx = mlx_init();
	if (!mlx.mlx)
		exit(1);
	mlx.win = mlx_new_window(mlx.mlx, mlx.width, mlx.height, "Frac_u");
	mlx.image = mlx_new_image(mlx.mlx, mlx.width, mlx.height);
	if (!mlx.image)
		exit(1);
	mlx.buffer = mlx_get_data_addr(mlx.image, &pb, &lb, &end);
	if (!mlx.buffer)
		exit(1);
	mlx.pixelb = pb;
	mlx.lineb = lb;
	mlx.endian = end;
	mlx.color = 0;
	mlx.zoom = 1;
	mlx.pos_x = 2;
	mlx.pos_y = 2;
	return (mlx);
}

static void	frac_u(void)
{
	ft_printf("How to use :\n> ./fractol {fractol name}\n");
	ft_printf("1 : mandelbrot\n2 : julia\n");
	ft_printf("ex : ./fractol mandelbrot\n");
	exit (1);
}

static void	arg_check(int argc, char **argv, t_fract *mlx)
{
	if (argc == 1 || argc > 3)
		frac_u();
	if (!ft_strncmp(argv[1], "mandelbrot", 11))
		ft_strlcpy(mlx->frac, "fractol : mandelbrot", 21);
	else if (!ft_strncmp(argv[1], "julia", 6))
		ft_strlcpy(mlx->frac, "fractol : julia", 16);
	else
		frac_u();
}

int	main(int argc, char **argv)
{
	t_fract	mlx;

	mlx = fractol_init();
	arg_check(argc, argv, &mlx);
	mlx_key_hook(mlx.win, &keyhook, &mlx);
	//mlx_mouse_hook(mlx.win, &close_win, &mlx);
	mlx_loop_hook(mlx.mlx, &main_loop, &mlx);
	mlx_loop(mlx.mlx);
}
