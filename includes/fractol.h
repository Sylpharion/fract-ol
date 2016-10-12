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


void		fract_menu(void);
void		mandelbrot(void *mlx, void *win);
void		julia(void *mlx, void *win);
int			fract_error(int argc, char **argv);

#endif
