/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchappon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 21:25:32 by lchappon          #+#    #+#             */
/*   Updated: 2018/05/09 21:40:54 by lchappon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		vertical(t_fdf *draw, int *x, int *y, int *xy)
{
	int		i;
	int		e;

	i = 0;
	e = y[0] / 2;
	while (i < y[0])
	{
		xy[1] += y[1];
		e += x[0];
		if (e >= y[0])
		{
			e -= y[0];
			xy[0] += x[1];
		}
		mlx_pixel_put(draw->mlx, draw->win, xy[0], xy[1], draw->color);
		i++;
	}
}

void		horizontal(t_fdf *draw, int *x, int *y, int *xy)
{
	int		i;
	int		e;

	i = 0;
	e = x[0] / 2;
	while (i < x[0])
	{
		xy[0] += x[1];
		e += y[0];
		if (e >= x[0])
		{
			e -= x[0];
			xy[1] += y[1];
		}
		mlx_pixel_put(draw->mlx, draw->win, xy[0], xy[1], draw->color);
		i++;
	}
}

void		bresenham(t_fdf *draw, int *tabxy, int x2, int y2)
{
	int		xy[2];
	int		x[2];
	int		y[2];

	xy[0] = tabxy[0];
	xy[1] = tabxy[1];
	x[0] = ft_abs(x2 - xy[0]);
	y[0] = ft_abs(y2 - xy[1]);
	x[1] = xy[0] < x2 ? 1 : -1;
	y[1] = xy[1] < y2 ? 1 : -1;
	mlx_pixel_put(draw->mlx, draw->win, xy[0], xy[1], draw->color);
	if (x[0] > y[0])
		horizontal(draw, x, y, xy);
	else
		vertical(draw, x, y, xy);
}
