/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchappon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 17:50:54 by lchappon          #+#    #+#             */
/*   Updated: 2018/05/08 18:00:44 by lchappon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		info_box(t_fdf *draw)
{
	int		x;
	int		y;

	x = 10;
	y = 10;
	while (x <= 180)
		mlx_pixel_put(draw->mlx, draw->win, x++, y, 0xFFFFFF);
	while (y <= 180)
		mlx_pixel_put(draw->mlx, draw->win, x, y++, 0xFFFFFF);
	while (x >= 10)
		mlx_pixel_put(draw->mlx, draw->win, x--, y, 0xFFFFFF);
	while (y >= 10)
		mlx_pixel_put(draw->mlx, draw->win, x, y--, 0xFFFFFF);
}

void		info(t_fdf *draw)
{
	if (draw->info == 0)
		mlx_string_put(draw->mlx, draw->win, 0, 0, 0xFFFFFF,
				"[i]");
	else
	{
		info_box(draw);
		mlx_string_put(draw->mlx, draw->win, 20, 20, 0xFFFFFF,
				"MOVE = ^ v < >");
		mlx_string_put(draw->mlx, draw->win, 20, 40, 0xFFFFFF,
				"ZOOM = / *");
		mlx_string_put(draw->mlx, draw->win, 20, 60, 0xFFFFFF,
				"ALTITUDE = - +");
		mlx_string_put(draw->mlx, draw->win, 20, 80, 0xFFFFFF,
				"COLOR = R G B");
		mlx_string_put(draw->mlx, draw->win, 20, 100, 0xFFFFFF,
				"PROJECTION = P");
		mlx_string_put(draw->mlx, draw->win, 20, 120, 0xFFFFFF,
				"RESTART = clear");
		mlx_string_put(draw->mlx, draw->win, 20, 150, 0xFFFFFF,
				"QUIT = esc");
	}
}

void		draw_init(t_fdf *draw)
{
	if (draw->init == 1)
	{
		draw->info = 0;
		draw->z = -5;
		draw->dx = WIDTH * 0.4;
		draw->dy = HEIGHT * 0.2;
		if (draw->chars >= draw->lines)
		{
			draw->sx = draw->chars * 2 > WIDTH ? 1 :
				(WIDTH * 0.5) / draw->chars;
			draw->sy = draw->sx;
		}
		else
		{
			draw->sy = draw->lines * 2 > HEIGHT ? 1 :
				(HEIGHT * 0.5) / draw->lines;
			draw->sx = draw->sy;
		}
		draw->color = 0xFFFFFF;
	}
	draw->init = 0;
}

void		drawing(t_fdf *draw)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	draw_init(draw);
	while (x / draw->sx < draw->chars || y / draw->sy < draw->lines - 1)
	{
		if (x / draw->sx == draw->chars)
		{
			x = 0;
			y += draw->sy;
		}
		projection(draw, x, y);
		x += draw->sx;
	}
	if (WIDTH >= 190 && HEIGHT >= 190)
		info(draw);
}
