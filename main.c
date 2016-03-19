/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfortin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/08 18:20:56 by jfortin           #+#    #+#             */
/*   Updated: 2016/03/18 22:34:05 by jfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_ini_fract(t_env *e)
{
	if (!(ft_strcmp(e->av, "mandelbrot")))
		ft_ini_val_mandelbrot(e);
	if (!(ft_strcmp(e->av, "julia")))
		ft_ini_val_julia(e);
	if (!(ft_strcmp(e->av, "burning")))
		ft_ini_val_bship(e);
	if (!(ft_strcmp(e->av, "mandelbis")))
		ft_ini_val_mandelbis(e);
}

void	ft_print_fract(t_env *e)
{
	if (!(ft_strcmp(e->av, "mandelbrot")))
		ft_print_mandel(e);
	if (!(ft_strcmp(e->av, "julia")))
		ft_print_julia(e);
	if (!(ft_strcmp(e->av, "burning")))
		ft_print_bship(e);
	if (!(ft_strcmp(e->av, "mandelbis")))
		ft_print_mandelbis(e);
}

int		main(int ac, char **av)
{
	t_env e;

	e.check = 0;
	ac != 2 ? ft_arg_error() : (e.av = av[1]);
	if (ft_strcmp(av[1], "mandelbrot") && ft_strcmp(av[1], "julia")
			&& ft_strcmp(av[1], "burning") && ft_strcmp(av[1], "mandelbis"))
		ft_arg_error();
	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, WIN_X, WIN_Y, "fractol");
	e.im = mlx_new_image(e.mlx, IM_X, WIN_Y);
	e.imc = mlx_get_data_addr(e.im, &e.bpp, &e.imlen, &e.endi);
	mlx_string_put(e.mlx, e.win, 400, 250, 0xFF9933, WELCOME);
	mlx_string_put(e.mlx, e.win, 400, 279, 0xFF9933, PRESS);
	ft_ini_fract(&e);
	mlx_hook(e.win, MOTIONNOTIFY, POINTERMOTIONMASK, ft_julia_hook, &e);
	mlx_hook(e.win, KEYPRESS, KEYPRESSMASK, ft_key_hit, &e);
	mlx_hook(e.win, KEYRELEASE, KEYRELEASEMASK, ft_key_release, &e);
	mlx_mouse_hook(e.win, ft_mouse_hook, &e);
	mlx_loop_hook(e.mlx, ft_core, &e);
	mlx_loop(e.mlx);
	return (0);
}
