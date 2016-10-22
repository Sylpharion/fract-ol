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
		fract_init(&draw, argv);
		ft_draw(&draw, argv[1]);
		mlx_hook(draw.win, 2, 64, keyboard_cat, &draw);
		mlx_mouse_hook(draw.win, mouse_chocolat, &draw);
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
	if ((keycode == 5 || keycode == 4 || keycode == 1 || keycode == 2) &&
		(x > 0 || y > 0 || x < 1200 || y < 1200))
	{
		set_mouse_caramel(draw, x, y);
		draw->mouse_x = x;
		draw->mouse_y = y;
		mlx_clear_window(draw->mlx, draw->win);
		if (keycode == 1 || keycode == 5)
			draw->z *= 1.2;
		else if (keycode == 2 || keycode == 4)
			draw->z /= 1.2;
		ft_draw(draw, draw->argv_cpy[1]);
		return (0);
	}
	return (0);
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
}

int			mykey_mouse(int x, int y, t_draw *draw)
{
	if (ft_strcmp(draw->argv_cpy[1], "julia") == 0 && draw->stop != 0)
	{
		if (x < 0 || y < 0 || x > 1200 || y > 1200)
			return (0);
		mlx_clear_window(draw->mlx, draw->win);
		draw->mouse_x = x;
		draw->mouse_y = y;
		ft_draw(draw, draw->argv_cpy[1]);
	}
	return (0);
}

int			keyboard_cat(int keycode, t_draw *draw)
{
	printf("key = %d\n", keycode);
	/*	7	ou	9	*/
	if (keycode == 89 || keycode == 92)
		red_move(keycode, draw);
	/*	4	ou	6	*/
	else if (keycode == 86 || keycode == 88)
		green_move(keycode, draw);
	/*	1	ou	3	*/
	else if (keycode == 83 || keycode == 85)
		blue_move(keycode, draw);
	/*		0		*/
	else if (keycode == 82 && ft_strcmp(draw->argv_cpy[1], "julia") == 0)
	{
		mlx_clear_window(draw->mlx, draw->win);
		if (draw->stop == 0)
			draw->stop++;
		else
		{
			draw->mouse_x = 0;
			draw->mouse_y = 0;
			draw->stop = 0;
		}
		ft_draw(draw, draw->argv_cpy[1]);
	}
	/*	+	ou	-	*/
	else if (keycode == 69 || keycode == 78)
		iter_move(keycode, draw);
	/*		fleche  */
	else if (keycode == 123 || keycode == 124 ||
				keycode == 125 || keycode == 126)
		momove(keycode, draw);
	/*		esc		*/
	else if (keycode == 53)
		exit(0);
	return (0);
}

void		iter_move(int keycode, t_draw *draw)
{
	if (keycode == 69)
		draw->iter += 5;
	else if (keycode == 78)
		draw->iter -= 5;
	mlx_clear_window(draw->mlx, draw->win);
	ft_draw(draw, draw->argv_cpy[1]);
}

void		momove(int keycode, t_draw *draw)
{
	if (keycode == 126)
		draw->m_y += 0.2;
	else if (keycode == 125)
		draw->m_y -= 0.2;
	else if (keycode == 124)
		draw->m_x -= 0.2;
	else if (keycode == 123)
		draw->m_x += 0.2;
	mlx_clear_window(draw->mlx, draw->win);
	ft_draw(draw, draw->argv_cpy[1]);
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
	draw->argv_cpy = argv;
}
