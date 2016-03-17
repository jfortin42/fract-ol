/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfortin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 14:38:48 by jfortin           #+#    #+#             */
/*   Updated: 2016/03/17 17:40:13 by jfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_ini_val_mandelbrot(t_env *e)
{
	e->x1 = -2.1;
	e->x2 = 0.6;
	e->y1 = -1.2;
	e->y2 = 1.2;
	e->zoom = 250;
	e->im_x = (e->x2 - e->x1) * e->zoom + 150 + WIN_X - IM_X;
	e->im_y = (e->y2 - e->y1) * e->zoom;
	e->iter_max = 90;
}

void	ft_print_mandel(t_env *e)
{
	e->x = -1;
	while (++e->x < e->im_x && e->x < IM_X)
	{
		e->y = -1;
		while (++e->y < e->im_y && e->y < WIN_Y)
		{
			e->c_r = e->x / e->zoom + e->x1;
			e->c_i = e->y / e->zoom + e->y1;
			e->z_r = 0;
			e->z_i = 0;
			e->i = 0;
			while (e->z_r * e->z_r + e->z_i * e->z_i < 4 && e->i < e->iter_max)
			{
				e->tmp = e->z_r;
				e->z_r = e->z_r * e->z_r - e->z_i * e->z_i + e->c_r;
				e->z_i = 2 * e->z_i * e->tmp + e->c_i;
				e->i++;
			}
			if (e->i == e->iter_max)
				ft_put_pixel(e, e->x, e->y, 0x000000);
			else
				ft_put_pixel(e, e->x, e->y, e->i * 1899750);
		}
	}
}
