/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfortin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 17:54:10 by jfortin           #+#    #+#             */
/*   Updated: 2016/03/19 13:44:12 by jfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_zoom_out(int x, int y, t_env *e)
{
	if (e->zoom > 250)
	{
		e->zoom /= 2;
		e->tmpx = e->x1 + x * (e->x2 - e->x1) / IM_X;
		e->tmpy = e->y1 + y * (e->y2 - e->y1) / WIN_Y;
		e->tmpx2 = e->x1;
		e->tmpy2 = e->y1;
		e->x1 = e->tmpx - (e->x2 - e->x1);
		e->x2 = e->tmpx + (e->x2 - e->tmpx2);
		e->y1 = e->tmpy - (e->y2 - e->y1);
		e->y2 = e->tmpy + (e->y2 - e->tmpy2);
	}
}

static void	ft_zoom_in(int x, int y, t_env *e)
{
	e->zoom *= 2;
	e->tmpx = e->x1 + x * (e->x2 - e->x1) / (IM_X - 50);
	e->tmpy = e->y1 + y * (e->y2 - e->y1) / (WIN_Y - 20);
	e->tmpx2 = e->x1;
	e->tmpy2 = e->y1;
	e->x1 = e->tmpx - (e->x2 - e->x1) / 4;
	e->x2 = e->tmpx + (e->x2 - e->tmpx2) / 4;
	e->y1 = e->tmpy - (e->y2 - e->y1) / 4;
	e->y2 = e->tmpy + (e->y2 - e->tmpy2) / 4;
}

int			ft_mouse_hook(int keycode, int x, int y, t_env *e)
{
	if (!e->check)
		ft_settings(e);
	e->check = 1;
	if (y > 0)
	{
		if ((keycode == 1 || keycode == 5) && x <= IM_X)
			ft_zoom_in(x, y, e);
		if ((keycode == 2 || keycode == 4) && x <= IM_X)
			ft_zoom_out(x, y, e);
	}
	return (0);
}
