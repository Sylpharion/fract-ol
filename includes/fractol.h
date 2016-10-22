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
	char	**argv_cpy;
	long double	x1;
	long double	x2;
	long double	y1;
	long double	y2;
	long double	image_x;
	long double	image_y;
	long double	iteration_max;
	long double	zoom_x;
	long double	zoom_y;
	long double	x;
	long double	y;
	long double	c_r;
	long double	c_i;
	long double	z_r;
	long double	z_i;
	long double	i;
	long double	tmp;
	long double	r;
	long double	g;
	long double	b;
	long double	z;
	long double	mouse_x;
	long double	mouse_y;
	long double	zoomove_x;
	long double	zoomove_y;
	long double iter;
	long double	stop;
	long double m_x;
	long double m_y;
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

void		fract_init(t_draw *draw, char **argv);

int			keyboard_cat(int keycode, t_draw *draw);
int			mykey_mouse(/*int	keycode, */int x, int y, t_draw *draw);
int			mouse_chocolat(int keycode, int x, int y, t_draw *draw);
void		red_move(int keycode, t_draw *draw);
void		green_move(int keycode, t_draw *draw);
void		blue_move(int keycode, t_draw *draw);
void		iter_move(int keycode, t_draw *draw);
void		momove(int keycode, t_draw *draw);
void		ft_draw(t_draw *draw, char *s);


int			fract_error(int argc, char **argv, t_draw *draw);
void		mandelbrot(t_draw *draw);
void		julia(t_draw *draw);
void		burning_ship(t_draw *draw);
void		powerbrot(t_draw *draw);

#endif
