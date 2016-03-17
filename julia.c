/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfortin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 14:51:47 by jfortin           #+#    #+#             */
/*   Updated: 2016/03/17 18:30:52 by jfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_ini_val_julia(t_env *e)
{
	e->x1 = -1.6;
	e->x2 = 1;
	e->y1 = -1.2;
	e->y2 = 1.2;
	e->zoom = 250;
	e->im_x = (e->x2 - e->x1) * e->zoom + 150;
	e->im_y = (e->y2 - e->y1) * e->zoom;
	e->iter_max = 90;
	e->c_r = 0.285;
	e->c_i = 0.01;
}

void	ft_print_julia(t_env *e)
{
	e->x = -1;
	while (++e->x < e->im_x)
	{
		e->y = -1;
		while (++e->y < e->im_y)
		{
			e->z_r = e->x / e->zoom + e->x1;
			e->z_i = e->y / e->zoom + e->y1;
			e->i = 0;
			while (e->z_r * e->z_r + e->z_i * e->z_i < 4 && e->i < e->iter_max)
			{
				e->tmp = e->z_r;
				e->z_r = e->z_r * e->z_r - e->z_i * e->z_i + e->c_r;
				e->z_i = 2 * e->z_i * e->tmp + e->c_i;
				e->i++;
			}
			if (e->i == e->iter_max)
				ft_put_pixel(e, e->x, e->y, 0xFFFFFF);
			else
				ft_put_pixel(e, e->x, e->y, e->i * 1899750);
		}
	}
}

int		ft_julia_hook(int x, int y, t_env *e)
{
	if (!(ft_strcmp(e->av, "julia")) &&
			x <= IM_X && y <= WIN_Y && x > 0 && y > 0 && e->bj == 0)
	{
		e->c_r = (float)(x + 400 - IM_X) / 300;
		e->c_i = (float)(y + 320 - WIN_Y) / 300;
	}
	return (0);
}
