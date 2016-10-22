/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smassand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/21 22:27:43 by smassand          #+#    #+#             */
/*   Updated: 2016/10/21 22:27:47 by smassand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void		red_move(int keycode, t_draw *draw)
{
	mlx_clear_window(draw->mlx, draw->win);
	if (keycode == 89 && draw->r > 20)
		draw->r -= 20;
	else if (keycode == 92 && draw->r < 200)
		draw->r += 20;
	ft_draw(draw, draw->argv_cpy[1]);
}

void		green_move(int keycode, t_draw *draw)
{
	mlx_clear_window(draw->mlx, draw->win);
	if (keycode == 86 && draw->g > 20)
		draw->g -= 20;
	else if (keycode == 88 && draw->g < 200)
		draw->g += 20;
	ft_draw(draw, draw->argv_cpy[1]);
}

void		blue_move(int keycode, t_draw *draw)
{
	mlx_clear_window(draw->mlx, draw->win);
	if (keycode == 83 && draw->b > 20)
		draw->b -= 20;
	else if (keycode == 85 && draw->b < 200)
		draw->b += 20;
	ft_draw(draw, draw->argv_cpy[1]);
}
