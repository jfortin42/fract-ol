/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfortin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/08 18:20:56 by jfortin           #+#    #+#             */
/*   Updated: 2016/03/08 18:48:40 by jfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int ac, char **av)
{
	if (ac != 2)
		ft_error("Number of argument incorrect");
	if (ft_strcmp(av[1], "--julia") && ft_strcmp(av[1], "--mandelbrot"))
		ft_error("invalid parameter	usage : ./fractol --julia --mandelbrot");
	ft_putendl("good");
	return (0);
}
