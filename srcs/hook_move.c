/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smassand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/22 06:31:22 by smassand          #+#    #+#             */
/*   Updated: 2016/10/22 06:31:25 by smassand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

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
