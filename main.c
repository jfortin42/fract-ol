/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfortin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/08 18:20:56 by jfortin           #+#    #+#             */
/*   Updated: 2016/03/11 19:02:47 by jfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

static void	ft_init(t_env *e)
{
	e->iter = 0;
	e->lr = 0;
	e->ud = 0;
	e->z = 0;
}

static void	ft_print(t_env *e)
{
	mlx_destroy_image(e->mlx, e->im);
	mlx_clear_window(e->mlx, e->win);
	e->im = mlx_new_image(e->mlx, WIN_X, WIN_Y);
	if (!(ft_strcmp(e->av[1], "--mandelbrot")))
	{
		ft_ini_val_mandel(e);
		ft_print_mandel(e);
	}
	else if (!(ft_strcmp(e->av[1], "--julia")))
	{
		ft_ini_val_julia(e);
		ft_print_julia(e);
	}
	mlx_put_image_to_window(e->mlx, e->win, 0, 0, e->ud);
	ft_put_help(*e);
}

static	int	ft_move_mouse(int x, int y, t_env *e)
{
	int	x1;
	int	y1;

	ft_ini_val_mandel(e);
	x1 = x - e->im_x;
	y1 = (y - e->im_y) * -1;
	printf("mouse : X %d\tY %d\n", x, y);
	return (0);
}


static int	ft_key_hit(int keycode, t_env *e)
{
	if (keycode == LEFT || keycode == RIGHT)
		e->lr += (keycode == LEFT ? 10 : -10);
	if (keycode == UP || keycode == DOWN)
		e->ud += (keycode == UP ? 10 : -10);
	if (keycode == PLUS || keycode == MINUS)
		e->z += (keycode == PLUS ? 10 : -10);
	if (keycode == PAGE_UP || keycode == PAGE_DOWN)
		e->iter += (keycode == PAGE_UP ? 10 : -10);
	if (keycode == ONE)
		e->av[1] = "--mandelbrot";
	if (keycode == TWO)
		e->av[1] = "--julia";
	if (keycode == ZERO)
		ft_init(e);
	if (keycode == ESC)
		exit(0);
	ft_print(e);
	printf("%d\niter : %d\n", keycode, e->iter);
	return (0);
}

int			main(int ac, char **av)
{
	t_env	e;
	int		m_x;
	int		m_y;

	m_x = WIN_X * 2 / 5;
	m_y = WIN_Y * 2 / 5;
	e.av = av;
	if (ac != 2)
		ft_error("Number of argument incorrect");
	if (ft_strcmp(av[1], "--julia") && ft_strcmp(av[1], "--mandelbrot"))
		ft_error("invalid parameter	usage : ./fractol --julia --mandelbrot");
	e.mlx = mlx_init();
	ft_init(&e);
	e.win = mlx_new_window(e.mlx, WIN_X, WIN_Y, "fractol");
	e.im = mlx_new_image(e.mlx, WIN_X, WIN_Y);
	e.imc = mlx_get_data_addr(e.im, &e.bpp, &e.imlen, &e.endi);
	mlx_string_put(e.mlx, e.win, m_x, m_y, 0xFF9933, WELCOME);
	mlx_string_put(e.mlx, e.win, m_x + 24, m_y + 20, 0xFF9933, PRESS);
	mlx_hook(e.win, KEYPRESS, KEYPRESSMASK, ft_key_hit, &e);
	mlx_hook(e.win, MOTIONNOTIFY, POINTERMOTIONMASK, ft_move_mouse, &e);
	mlx_loop(e.mlx);
	return (0);
}
