/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfortin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 17:53:41 by jfortin           #+#    #+#             */
/*   Updated: 2016/03/17 17:54:30 by jfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		ft_put_pixel(t_env *e, int x, int y, int color)
{
	int *tmp;

	if (y >= WIN_Y || x >= IM_X || x < 0 || y < 0)
		return ;
	tmp = (int *)&e->imc[(y * e->imlen) + (x * (e->bpp / 8))];
	*tmp = color;
}

static void	ft_put_help(t_env e)
{
	int	m_y;
	int	m_x;

	m_y = 0;
	m_x = IM_X;
	mlx_string_put(e.mlx, e.win, m_x, m_y, 0xDDDDDD, CONTROLS);
	mlx_string_put(e.mlx, e.win, m_x, m_y + 16, 0xDDDDDD, H_L_CLICK);
	mlx_string_put(e.mlx, e.win, m_x, m_y + 32, 0xDDDDDD, H_R_CLICK);
	mlx_string_put(e.mlx, e.win, m_x, m_y + 48, 0xDDDDDD, H_PLUS);
	mlx_string_put(e.mlx, e.win, m_x, m_y + 64, 0xDDDDDD, H_MINUS);
	mlx_string_put(e.mlx, e.win, m_x, m_y + 80, 0xDDDDDD, H_ZERO);
	mlx_string_put(e.mlx, e.win, m_x, m_y + 96, 0xDDDDDD, H_NUM);
	mlx_string_put(e.mlx, e.win, m_x, m_y + 112, 0xDDDDDD, H_ESC);
	if (!(ft_strcmp(e.av, "julia")))
	{
		mlx_string_put(e.mlx, e.win, m_x, m_y + 150, 0xDDDDDD, H_JULIA1);
		mlx_string_put(e.mlx, e.win, m_x, m_y + 166, 0xDDDDDD, H_JULIA2);
		mlx_string_put(e.mlx, e.win, m_x, m_y + 182, 0xDDDDDD, H_JULIA3);
	}
}

void		ft_settings(t_env *e)
{
	int	x;
	int	y;

	y = 0;
	while (y <= WIN_Y)
	{
		x = 0;
		while (x <= WIN_X - IM_X)
			ft_put_pixel(e, 0 + x++, y, 0x318CE7);
		++y;
	}
	mlx_put_image_to_window(e->mlx, e->win, e->im, IM_X, 0);
	ft_put_help(*e);
}
