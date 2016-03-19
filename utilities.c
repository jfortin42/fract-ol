/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfortin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 17:53:41 by jfortin           #+#    #+#             */
/*   Updated: 2016/03/18 22:33:11 by jfortin          ###   ########.fr       */
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

	m_y = 20;
	m_x = IM_X;
	mlx_string_put(e.mlx, e.win, m_x, m_y, 0xDDDDDD, CONTROLS);
	mlx_string_put(e.mlx, e.win, m_x, m_y + 36, 0xDDDDDD, H_L_CLICK);
	mlx_string_put(e.mlx, e.win, m_x, m_y + 53, 0xDDDDDD, H_R_CLICK);
	mlx_string_put(e.mlx, e.win, m_x, m_y + 70, 0xDDDDDD, H_PLUS);
	mlx_string_put(e.mlx, e.win, m_x, m_y + 87, 0xDDDDDD, H_MINUS);
	mlx_string_put(e.mlx, e.win, m_x, m_y + 104, 0xDDDDDD, H_ZERO);
	mlx_string_put(e.mlx, e.win, m_x, m_y + 121, 0xDDDDDD, H_NUM);
	mlx_string_put(e.mlx, e.win, m_x, m_y + 138, 0xDDDDDD, H_ESC);
	if (!(ft_strcmp(e.av, "julia")))
	{
		mlx_string_put(e.mlx, e.win, m_x, m_y + 155, 0xDDDDDD, H_SPACE1);
		mlx_string_put(e.mlx, e.win, m_x, m_y + 172, 0xDDDDDD, H_SPACE2);
		mlx_string_put(e.mlx, e.win, m_x, m_y + 189, 0xDDDDDD, H_SPACE3);
		mlx_string_put(e.mlx, e.win, m_x, m_y + 220, 0xDDDDDD, H_JULIA1);
		mlx_string_put(e.mlx, e.win, m_x, m_y + 237, 0xDDDDDD, H_JULIA2);
		mlx_string_put(e.mlx, e.win, m_x, m_y + 254, 0xDDDDDD, H_JULIA3);
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

void	ft_arg_error(void)
{
	ft_putendl_fd("Invalid argument", 2);
	ft_error("Usage : ./fractol julia, mandelbrot, burning or mandelbis");
}
