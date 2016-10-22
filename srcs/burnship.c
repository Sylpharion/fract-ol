/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burnship.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smassand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/21 21:48:38 by smassand          #+#    #+#             */
/*   Updated: 2016/10/21 21:48:41 by smassand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void		burning_ship(t_draw *draw)
{
/*
** définit la zone dessiné
*/
	draw->x1 = -2.1; 		/* gauche */
	draw->x2 = 0.6;  		/* droite */
	draw->y1 = -1.2; 		/*  haut  */
	draw->y2 = 1.2;  		/*  bas   */
	draw->image_x = 1200;
	draw->image_y = 1200;
	draw->iteration_max = 50 + draw->iter;
/*
** calcule de la taille de l'image
*/
	draw->zoom_x = draw->image_x/(draw->x2 - draw->x1);
	draw->zoom_y = draw->image_y/(draw->y2 - draw->y1);
	draw->x = 0;
/*
** ta gueule c'est magique..
*/
	while (draw->x < draw->image_x)
	{
		draw->y = 0;
		while (draw->y < draw->image_y)
		{
			draw->c_r = (draw->zoomove_x + (draw->x - draw->mouse_x) /
						draw->z) / draw->zoom_x + draw->x1 + draw->m_x;
		    draw->c_i = (draw->zoomove_y + (draw->y - draw->mouse_y) /
		    			draw->z) / draw->zoom_y + draw->y1 + draw->m_y;
		    draw->z_r = 0;
		    draw->z_i = 0;
			draw->i = 0;
			while (draw->z_r * draw->z_r + draw->z_i * draw->z_i < 4 &&
					draw->i < draw->iteration_max)
			{
				draw->tmp = draw->z_r;
				draw->z_r = draw->z_r * draw->z_r - draw->z_i * draw->z_i +
							draw->c_r;
				draw->z_i = 2 * fabsl(draw->z_i * draw->tmp) + draw->c_i;
				draw->i++;
			}
			/*
			** dessine le pixel
			*/
            if (draw->i < draw->iteration_max)
            	mlx_pixel_put(draw->mlx, draw->win, draw->x, draw->y, ((draw->r * 65536) +
            					 (draw->g * 256) +
            					  draw->b) * draw->i);
// swaggy color : (draw->i * 18 * 255 / draw->iteration_max * 0x0000FF)
			draw->y++;
		}
		draw->x++;
	}
}