/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfortin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/08 18:24:22 by jfortin           #+#    #+#             */
/*   Updated: 2016/03/11 18:09:54 by jfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define WIN_X 1000
# define WIN_Y 1000

# define KEYPRESS 2
# define KEYRELEASE 3
# define MOTIONNOTIFY 6
# define BUTTONPRESS 4
# define KEYPRESSMASK (1L<<0)
# define KEYRELEASEMASK (1L<<1)
# define POINTERMOTIONMASK (1L<<3)
# define BUTTONPRESSMASK (1L<<2)

# define LEFT 123
# define RIGHT 124
# define UP 126
# define DOWN 125
# define PLUS 69
# define MINUS 78
# define STAR 67
# define SLASH 75
# define PAGE_UP 116
# define PAGE_DOWN 121
# define ZERO 82
# define ONE 83
# define TWO 84
# define THREE 85
# define ESC 53

# define WELCOME "Welcome to FRACTOL by jfortin"
# define PRESS "Press any key to start"

# define CONTROLS "            CONTROLS"
# define H_UP "     move up    |    up"
# define H_DOWN "    move down   |   down"
# define H_LEFT "    move left   |   left"
# define H_RIGHT "   move right   |   right"
# define H_PLUS "    zoom in     |     +"
# define H_MINUS "    zoom out    |     -"
# define H_STAR "increase height |     *"
# define H_SLASH "decrease height |     /"
# define H_PAGE_UP "     add iter   | page up"
# define H_PAGE_DOWN "     sub iter   | page down"
# define H_ZERO "     reset      |     0"
# define H_ESC "  exit program  |    esc"

# include "mlx.h"
# include <fcntl.h>
# include <unistd.h>
# include "libft/includes/libft.h"

typedef struct		s_env
{
	char			**av;
	void			*mlx;
	void			*win;

	int				x;
	int				y;
	int				i;
	float			x1;
	float			x2;
	float			y1;
	float			y2;
	int				iter_max;
	int				im_x;
	int				im_y;
	float			c_r;
	float			c_i;
	float			z_r;
	float			z_i;
	float			tmp;

	float			zoom;
	int				col;

	int				c;
	int				itm;
	int				res;

	int				lr;
	int				ud;
	int				iter;
	int				z;
	int				height;
	int				contrast;

	void			*im;
	char			*imc;
	int				imlen;
	int				bpp;
	int				endi;
}					t_env;

void				ft_ini_val_mandel(t_env *e);
void				ft_ini_val_julia(t_env *e);
void				ft_print_mandel(t_env *e);
void				ft_print_julia(t_env *e);
void				ft_put_help(t_env e);
void				ft_put_pixel(t_env *e, int x, int y, int color);

#endif
