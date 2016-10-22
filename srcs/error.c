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
						ft_strcmp(argv[1], "superjulia") != 0 &&
						ft_strcmp(argv[1], "powerbrot") != 0 &&
						ft_strcmp(argv[1], "burnship") != 0 &&
						ft_strcmp(argv[1], "help") != 0) || (argc < 2))
	{
		ft_putrainbow("LOL RTFM NOOB!!\n", RED);
		ft_putendl("usage :");
		ft_putendl(" - mandelbrot");
		ft_putendl(" - julia");
		ft_putendl(" - powerbrot");
		ft_putendl(" - burnship");
		ft_putendl(" - superjulia");
		ft_putendl(" - help");
		return (-1);
	}
	return (0);
}

void		fract_init(t_draw *draw, char **argv)
{
	draw->mlx = mlx_init();
	draw->win = mlx_new_window(draw->mlx, 1200, 1200, "fractol");
	draw->x1 = 0;
	draw->x2 = 0;
	draw->y1 = 0;
	draw->y2 = 0;
	draw->image_x = 0;
	draw->image_y = 0;
	draw->iteration_max = 0;
	draw->zoom_x = 0;
	draw->zoom_y = 0;
	draw->x = 0;
	draw->y = 0;
	draw->c_r = 0;
	draw->c_i = 0;
	draw->z_r = 0;
	draw->z_i = 0;
	draw->argv_cpy = argv;
	fract_init_return(draw);
}

void		fract_init_return(t_draw *draw)
{
	draw->i = 0;
	draw->tmp = 0;
	draw->r = 33;
	draw->g = 22;
	draw->b = 11;
	draw->z = 1;
	draw->mouse_x = 0;
	draw->mouse_y = 0;
	draw->zoomove_x = 0;
	draw->zoomove_y = 0;
	draw->iter = 1.1;
	draw->stop = 0;
	draw->m_x = 0;
	draw->m_y = 0;
}

void		fract_help(t_draw *draw)
{
	ft_putrainbow("7 et 9\t", GREEN);
	ft_putrainbow(": reduire / augmenter les nuances de rouge.\n", CYAN);
	ft_putrainbow("4 et 6\t", GREEN);
	ft_putrainbow(": reduire / augmenter les nuances de vert.\n", CYAN);
	ft_putrainbow("1 et 3\t", GREEN);
	ft_putrainbow(": reduire / augmenter les nuances de bleu.\n", CYAN);
	ft_putrainbow("0\t", GREEN);
	ft_putrainbow(": bloquer la fractale (mode julia seulement).\n", CYAN);
	ft_putrainbow("+ et -\t", GREEN);
	ft_putrainbow(": augmenter / reduire le nombre d'iteration.\n", CYAN);
	ft_putrainbow("Clique gauche / molette(avant) ", GREEN);
	ft_putrainbow(": zoomer.\n", CYAN);
	ft_putrainbow("Clique droit / molette(arriere) ", GREEN);
	ft_putrainbow(": dezoomer.\n", CYAN);
	ft_putrainbow("Esc\t", GREEN);
	ft_putrainbow(": quitter.\n", CYAN);
	exit(0);
}
