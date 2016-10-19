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

	if (fract_error(argc, argv, &draw) == 0)
	{
		fract_init(&draw);
		if (ft_strcmp(argv[1], "mandelbrot") == 0)
			mandelbrot(&draw);
		else if (ft_strcmp(argv[1], "julia") == 0)
			julia(&draw);
		mlx_hook(draw.win, 2, 64, keyboard_cat, &draw);
		mlx_mouse_hook(draw.win, mouse_chocolat, &draw);
		if (ft_strcmp(argv[1], "julia") == 0)
			mlx_hook(draw.win, 6, 1L<<6, mykey_mouse, &draw);
		mlx_loop(draw.mlx);
		return 0;
	}
	return (-1);
}

void		set_mouse_caramel(t_draw *draw, int x, int y)
{
	draw->zoomove_x += (x - draw->mouse_x) / draw->z;
	draw->zoomove_y += (y - draw->mouse_y) / draw->z;
}

int			mouse_chocolat(int keycode, int x, int y, t_draw *draw)
{
	if ((keycode == 1 || keycode == 2) && (x > 0 || y > 0 || x < 1200 || y < 1200))
	{
		set_mouse_caramel(draw, x, y);
		draw->mouse_x = x;
		draw->mouse_y = y;
		mlx_clear_window(draw->mlx, draw->win);
		if (keycode == 1)
			draw->z *= 1.1;
		else if (keycode == 2)
			draw->z /= 1.1;
		mandelbrot(draw);
		return (0);
	}
	return (0);
}

int			mykey_mouse(/*int keycode, */int x, int y, t_draw *draw)
{
	if (x < 0 || y < 0 || x > 1200 || y > 1200)
		return (0);
	printf("ta soeur x = %d\n", x);
	printf("ta mere  y = %d\n", y);
	// i_like_to_move_it(x, y, draw);
	return (0);
}

int			keyboard_cat(int keycode, t_draw *draw)
{
	/*	7	ou	9	*/
	if (keycode == 89 || keycode == 92)
		red_move(keycode, draw);
	/*	4	ou	6	*/
	else if (keycode == 86 || keycode == 88)
		green_move(keycode, draw);
	/*	1	ou	3	*/
	else if (keycode == 83 || keycode == 85)
		blue_move(keycode, draw);
	else if (keycode == 69 || keycode == 78)
		zoom(keycode, draw);
	/*		0		*/
	else if (keycode == 82)
		exit(0);
	/*		esc		*/
	else if (keycode == 53)
		exit(0);
	return (0);
}

int			i_like_to_move_it(int x, int y, t_draw *draw)
{
	// printf("ta soeur x = %d\n", x);
	// printf("ta mere  y = %d\n", y);
	// mlx_clear_window(draw->mlx, draw->win);
	//draw->r = (double)x;
	//draw->g = (double)y;
	// if (x % 2 == 0)
	// 	draw->b = x;
	// else
	// 	draw->b = y;
	// mandelbrot(draw);
	return (0);
}

void		red_move(int keycode, t_draw *draw)
{
	mlx_clear_window(draw->mlx, draw->win);
	if (keycode == 89 && draw->r > 50)
		draw->r -= 50;
	else if (keycode == 92 && draw->r < 200)
		draw->r += 50;
	mandelbrot(draw);
}

void		green_move(int keycode, t_draw *draw)
{
	mlx_clear_window(draw->mlx, draw->win);
	if (keycode == 86 && draw->g > 50)
		draw->g -= 50;
	else if (keycode == 88 && draw->g < 200)
		draw->g += 50;
	mandelbrot(draw);
}

void		blue_move(int keycode, t_draw *draw)
{
	mlx_clear_window(draw->mlx, draw->win);
	if (keycode == 83 && draw->b > 50)
		draw->b -= 50;
	else if (keycode == 85 && draw->b < 200)
		draw->b += 50;
	mandelbrot(draw);
}

void		zoom(int keycode, t_draw *draw)
{
	mlx_clear_window(draw->mlx, draw->win);
	if (keycode == 1 || keycode == 69)
		draw->z *= 1.3;
	else if (keycode == 2 || keycode == 78)
		draw->z /= 1.3;
	mandelbrot(draw);
}

void		fract_init(t_draw *draw)
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
	draw->i = 0;
	draw->tmp = 0;
	draw->r = 10;
	draw->g = 20;
	draw->b = 10;
	draw->z = 1;
	draw->mouse_x = 0;
	draw->mouse_y = 0;
	draw->zoomove_x = 0;
	draw->zoomove_y = 0; 
}

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
						ft_strcmp(argv[1], "tree") != 0) || (argc < 2))
	{
		ft_putrainbow("lol RTFM noob!\n", RED);
		ft_putendl("usage :");
		ft_putendl(" - mandelbrot");
		ft_putendl(" - julia");
		ft_putendl(" - sierpinski");
		ft_putendl(" - tree");
		return (-1);
	}
	return (0);
}

void		fract_menu(t_draw *draw)
{
	return ;
}