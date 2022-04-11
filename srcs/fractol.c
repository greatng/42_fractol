/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pngamcha <pngamcha@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 23:53:04 by pngamcha          #+#    #+#             */
/*   Updated: 2022/04/11 15:05:25 by pngamcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static t_fract	fractol_init(void)
{
	t_fract	m;

	m.mlx = mlx_init();
	if (!m.mlx)
		exit(1);
	m.win = mlx_new_window(m.mlx, WIDTH, HEIGHT, "Frac_u");
	m.image = mlx_new_image(m.mlx, WIDTH, HEIGHT);
	if (!m.image || !m.win)
		exit(1);
	m.buffer = mlx_get_data_addr(m.image, &m.win_mem.pixelb,
			&m.win_mem.lineb, &m.win_mem.endian);
	if (!m.buffer)
		exit(1);
	m.zoom = SCALE;
	m.x_o = WIDTH / 2;
	m.y_o = HEIGHT / 2;
	m.color = 0;
	return (m);
}

static void	frac_u(void)
{
	ft_printf("How to use :\n> ./fractol {fractol name}\n");
	ft_printf("1 : mandelbrot\n2 : julia {1 - 6}\n3 : burningship\n");
	ft_printf("ex : ./fractol julia 6\n");
	exit (1);
}

static void	arg_check(int argc, char **argv, t_fract *m)
{
	if (argc == 1 || argc > 3)
		frac_u();
	if (!ft_strncmp(argv[1], "mandelbrot", 11) && argc == 2)
	{
		ft_strlcpy(m->frac, "fractol : mandelbrot", 21);
		m->type = 1;
	}
	else if (!ft_strncmp(argv[1], "julia", 6) && argc == 3)
	{
		ft_strlcpy(m->frac, "fractol : julia", 16);
		m->type = 2;
	}
	else if (!ft_strncmp(argv[1], "burningship", 12) && argc == 2)
	{
		ft_strlcpy(m->frac, "fractol : burningship", 22);
		m->type = 3;
	}
	else
		frac_u();
}

int	main(int argc, char **argv)
{
	t_fract	m;

	m = fractol_init();
	arg_check(argc, argv, &m);
	if (m.type == 2)
	{
		if (argc != 3)
			frac_u();
		m.julia = ft_atoi(argv[2]);
		if (!(m.julia >= 1 && m.julia <= 6))
			frac_u();
	}
	mlx_hook(m.win, KEYPRESS, 0, &keyhook, &m);
	mlx_hook(m.win, BUTTONPRESS, 0, &mousehook, &m);
	mlx_hook(m.win, DESTROY_WINDOW, 0, &close_win, &m);
	mlx_loop_hook(m.mlx, &main_loop, &m);
	mlx_loop(m.mlx);
}
