/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchappon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 21:25:48 by lchappon          #+#    #+#             */
/*   Updated: 2018/05/05 15:22:18 by lchappon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		parallel(t_fdf *draw, int x, int y)
{
	int		tabxy[2];

	tabxy[0] = draw->dx + x +
		draw->map[y / draw->sy][x / draw->sx] * draw->z;
	tabxy[1] = draw->dy + y +
		draw->map[y / draw->sy][x / draw->sx] * draw->z;
	if (x / draw->sx < draw->chars - 1)
		bresenham(draw, tabxy, draw->dx + (x + draw->sx) +
			draw->map[y / draw->sx][x / draw->sx + 1] * draw->z,
			draw->dy + y +
			draw->map[y / draw->sy][x / draw->sx + 1] * draw->z);
	if (y / draw->sy < draw->lines - 1)
		bresenham(draw, tabxy, draw->dx + x +
			draw->map[y / draw->sy + 1][x / draw->sx] * draw->z,
			draw->dy + (y + draw->sy) +
			draw->map[y / draw->sy + 1][x / draw->sx] * draw->z);
}

void		isometric(t_fdf *draw, int x, int y)
{
	int		tabxy[2];

	tabxy[0] = draw->dx + (x - y);
	tabxy[1] = draw->dy + (x + y) / 2 +
		draw->map[y / draw->sy][x / draw->sx] * draw->z;
	if (x / draw->sx < draw->chars - 1)
		bresenham(draw, tabxy, draw->dx + ((x + draw->sx) - y),
			draw->dy + ((x + draw->sx) + y) / 2 +
			draw->map[y / draw->sy][x / draw->sx + 1] * draw->z);
	if (y / draw->sy < draw->lines - 1)
		bresenham(draw, tabxy, draw->dx + (x - (y + draw->sy)),
			draw->dy + (x + (y + draw->sy)) / 2 +
			draw->map[y / draw->sy + 1][x / draw->sx] * draw->z);
}

void		projection(t_fdf *draw, int x, int y)
{
	if (draw->proj == 0)
		isometric(draw, x, y);
	else if (draw->proj == 1)
		parallel(draw, x, y);
}
