/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smassand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 20:25:38 by smassand          #+#    #+#             */
/*   Updated: 2016/10/12 20:25:41 by smassand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void		julia(void *mlx, void *win)
{
	double x1;
	double x2;
	double y1;
	double y2;
	double image_x;
	double image_y;
	double iteration_max;
	double zoom;
	double zoom_x;
	double zoom_y;
	double x;
	double y;
	double c_r;
    double c_i;
    double z_r;
    double z_i;
    double i;
    double tmp;

/*
** définit la zone que dessiné
*/

	x1 = -1; /* gauche */
	x2 = 1;  /* droite */
	y1 = -1.0; /*  haut  */
	y2 = 1.0;  /*  bas   */
	zoom = 600;
	image_x = (x2 - x1) * zoom;
	image_y = (y2 - y1) * zoom;
	iteration_max = 150;
	

/*
** calcule de la taille de l'image
*/
	
	zoom_x = image_x/(x2 - x1);
	zoom_y = image_y/(y2 - y1);
	x = 0;
	y = 0;

/*
** ta gueule c'est magique..
*/

	while (x < image_x)
	{
		y = 0;
		while (y < image_y)
		{
			c_r = 0.285;
		    c_i = 0.01;
		    z_r = x / zoom + x1;
		    z_i = y / zoom + y1;
			i = 0;
			while (z_r * z_r + z_i * z_i < 4 && i < iteration_max)
			{
				tmp = z_r;
				z_r = z_r * z_r - z_i * z_i + c_r;
				z_i = 2 * z_i * tmp + c_i;
				i++;
			}
			/*
			** dessine le pixel
			*/
			if (i == iteration_max)
            	mlx_pixel_put(mlx, win, x, y, 0x000000);
            else
            	mlx_pixel_put(mlx, win, x, y, (i * 18 * 255 / iteration_max *
            													0x0000FF));
			y++;
		}
		x++;
	}
}
