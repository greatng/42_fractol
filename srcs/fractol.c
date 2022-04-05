/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pngamcha <pngamcha@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 23:53:04 by pngamcha          #+#    #+#             */
/*   Updated: 2022/04/05 13:08:24 by pngamcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static t_fract	fractol_init()
{
	t_fract	mlx;
	int	pb;
	int	lb;
	int	end;

	mlx.width = 800;
	mlx.height = 800;
	mlx.mlx = mlx_init();
	if (!mlx.mlx)
		exit(1);
	mlx.win = mlx_new_window(mlx.mlx, mlx.width, mlx.height, "Frac_u");
	mlx.image = mlx_new_image(mlx.mlx, mlx.width, mlx.height );
	if (!mlx.image)
		exit(1);
	mlx.buffer = mlx_get_data_addr(mlx.image, &pb, &lb, &end);
	if (!mlx.buffer)
		exit(1);
	mlx.pixelb = pb;
	mlx.lineb = lb;
	mlx.endian = end;
	mlx.color = 0x000000;
	mlx.zoom = 1;
	return (mlx);
}

static void	put_str_mlx(t_fract mlx)
{
	int	white;
	char	str[20];

	white = 0xFFFFFF;
	mlx_string_put(mlx.mlx, mlx.win, 10, 30, white, mlx.frac);
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
	else frac_u();
}

int	main(int argc, char **argv)
{
	t_fract	mlx;

	mlx = fractol_init();
	arg_check(argc, argv, &mlx);
	mlx_key_hook(mlx.win, &keyhook, &mlx);
	frac_plot(mlx);
	mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.image, 0, 0);
	put_str_mlx(mlx);
	mlx_loop(mlx.mlx);
}