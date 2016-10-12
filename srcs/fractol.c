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
	void   *mlx;
	void   *win;

	if (fract_error(argc, argv) == 0)
	{
		mlx = mlx_init();
		win = mlx_new_window(mlx, 1200, 1200, "fractol Test");
		if (ft_strcmp(argv[1], "mandelbrot") == 0)
			mandelbrot(mlx, win);
		else if (ft_strcmp(argv[1], "julia") == 0)
			julia(mlx, win);
		mlx_loop(mlx);
		return 0;
	}
	return (-1);
}

int			fract_error(int argc, char **argv)
{
	if (argc > 2)
	{
		ft_putendl("too many argument");
		return (-1);
	}
	else if (argc < 2)
	{
	 	fract_menu();
	 	return (-1);
	}
	else if (ft_strcmp(argv[1], "mandelbrot") != 0 &&
						ft_strcmp(argv[1], "julia") != 0 &&
						ft_strcmp(argv[1], "sierpinski") != 0 &&
						ft_strcmp(argv[1], "tree") != 0)
	{
		ft_putrainbow("fract'ol error!\n", RED);
		ft_putendl("usage :");
		ft_putendl(" - mandelbrot");
		ft_putendl(" - julia");
		ft_putendl(" - sierpinski");
		ft_putendl(" - tree");
		return (-1);
	}
	return (0);
}

void		fract_menu(void)
{
	return ;
}