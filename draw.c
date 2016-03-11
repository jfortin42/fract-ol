/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfortin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/20 17:33:10 by jfortin           #+#    #+#             */
/*   Updated: 2016/03/10 12:45:26 by jfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_put_pixel(t_env *e, int x, int y, int color)
{
	int	*tmp;

	if (y >= WIN_Y || x >= WIN_X || x < 0 || y < 0)
		return ;
	tmp = (int *)&e->imc[(y * e->imlen) + (x * (e->bpp / 8))];
	*tmp = color;
}

void	ft_put_help(t_env e)
{
	int	m_y;

	m_y = 0;
	mlx_string_put(e.mlx, e.win, 0, m_y, 0xDDDDDD, CONTROLS);
	mlx_string_put(e.mlx, e.win, 0, m_y + 16, 0xDDDDDD, H_UP);
	mlx_string_put(e.mlx, e.win, 0, m_y + 32, 0xDDDDDD, H_DOWN);
	mlx_string_put(e.mlx, e.win, 0, m_y + 48, 0xDDDDDD, H_LEFT);
	mlx_string_put(e.mlx, e.win, 0, m_y + 64, 0xDDDDDD, H_RIGHT);
	mlx_string_put(e.mlx, e.win, 0, m_y + 80, 0xDDDDDD, H_PLUS);
	mlx_string_put(e.mlx, e.win, 0, m_y + 96, 0xDDDDDD, H_MINUS);
	mlx_string_put(e.mlx, e.win, 0, m_y + 112, 0xDDDDDD, H_STAR);
	mlx_string_put(e.mlx, e.win, 0, m_y + 128, 0xDDDDDD, H_SLASH);
	mlx_string_put(e.mlx, e.win, 0, m_y + 144, 0xDDDDDD, H_PAGE_UP);
	mlx_string_put(e.mlx, e.win, 0, m_y + 160, 0xDDDDDD, H_PAGE_DOWN);
	mlx_string_put(e.mlx, e.win, 0, m_y + 176, 0xDDDDDD, H_ZERO);
	mlx_string_put(e.mlx, e.win, 0, m_y + 192, 0xDDDDDD, H_ESC);
}
