/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smassand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 19:15:59 by smassand          #+#    #+#             */
/*   Updated: 2016/10/12 19:16:02 by smassand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int			fract_error(int argc, char **argv, t_draw *draw)
{
	if (argc > 2)
	{
		ft_putendl("too many argument");
		return (-1);
	}
	else if ((ft_strcmp(argv[1], "mandelbrot") != 0 &&
						ft_strcmp(argv[1], "julia") != 0 &&
						ft_strcmp(argv[1], "sierpinski") != 0 &&
						ft_strcmp(argv[1], "burnship") != 0 &&
						ft_strcmp(argv[1], "powerbrot") != 0) || (argc < 2))
	{
		ft_putrainbow("lol RTFM noob!\n", RED);
		ft_putendl("usage :");
		ft_putendl(" - mandelbrot");
		ft_putendl(" - julia");
		ft_putendl(" - powerbrot");
		ft_putendl(" - burnship");
		return (-1);
	}
	return (0);
}