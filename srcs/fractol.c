/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smassand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 16:46:47 by smassand          #+#    #+#             */
/*   Updated: 2016/10/10 16:50:19 by smassand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int			main(int argc, char **argv)
{
	t_draw	draw;

	if (ft_strcmp(argv[1], "help") == 0)
		fract_help(&draw);
	if (fract_error(argc, argv, &draw) == 0)
	{
		fract_init(&draw, argv);
		ft_draw(&draw, argv[1]);
		mlx_hook(draw.win, 2, 64, keyboard_cat, &draw);
		mlx_mouse_hook(draw.win, mouse_chocolat, &draw);
		mlx_hook(draw.win, 6, 1L << 6, mykey_mouse, &draw);
		mlx_loop(draw.mlx);
		return (0);
	}
	return (-1);
}

void		ft_draw(t_draw *draw, char *s)
{
	if (ft_strcmp(s, "mandelbrot") == 0)
		mandelbrot(draw);
	else if (ft_strcmp(s, "julia") == 0)
		julia(draw);
	else if (ft_strcmp(s, "burnship") == 0)
		burning_ship(draw);
	else if (ft_strcmp(s, "powerbrot") == 0)
		powerbrot(draw);
	else if (ft_strcmp(s, "superjulia") == 0)
		superjulia(draw);
}
