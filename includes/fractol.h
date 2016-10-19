/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smassand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 16:41:39 by smassand          #+#    #+#             */
/*   Updated: 2016/10/10 16:46:21 by smassand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/libft.h"
# include "../minilibx_macos/mlx.h"
# include <math.h>

typedef	struct 	s_draw
{
	void	*mlx;
	void	*win;
	double	x1;
	double	x2;
	double	y1;
	double	y2;
	double	image_x;
	double	image_y;
	double	iteration_max;
	double	zoom_x;
	double	zoom_y;
	double	x;
	double	y;
	double	c_r;
	double	c_i;
	double	z_r;
	double	z_i;
	double	i;
	double	tmp;
	double	r;
	double	g;
	double	b;
	double	z;
	double	mouse_x;
	double	mouse_y;
	double	zoomove_x;
	double	zoomove_y;
}				t_draw;

/*
input :

haut ..: 126
bas ...: 125
gauche : 123
droite : 124
1......: 83 x
2 .....: 84
3 .....: 85 x
4 .....: 86 x
5 .....: 87
6 .....: 88 x
7 .....: 89 x
8 .....: 91
9 .....: 92 x
0 .....: 82
+ .....: 69
- .....: 78
* .....: 67
/ .....: 75
m .....: 46
! .....: 18
@ .....: 19
# .....: 20
$ .....: 21
% .....: 23
^ .....: 22
& .....: 26
* .....: 28
( .....: 25
) .....: 29
*/

void		fract_menu(t_draw *draw);
void		fract_init(t_draw *draw);

int			keyboard_cat(int keycode, t_draw *draw);
int			mykey_mouse(/*int	keycode, */int x, int y, t_draw *draw);
int			mouse_chocolat(int keycode, int x, int y, t_draw *draw);
void		red_move(int keycode, t_draw *draw);
void		green_move(int keycode, t_draw *draw);
void		blue_move(int keycode, t_draw *draw);
int			i_like_to_move_it(int x, int y, t_draw *draw);
void		zoom(int keycode, t_draw *draw);


int			fract_error(int argc, char **argv, t_draw *draw);
void		mandelbrot(t_draw *draw);
void		julia(t_draw *draw);

#endif
