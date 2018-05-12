/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchappon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 17:47:48 by lchappon          #+#    #+#             */
/*   Updated: 2018/05/11 20:33:42 by lchappon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		color(int keycode, t_fdf *key)
{
	if (keycode == 15 || keycode == 5 || keycode == 11)
	{
		mlx_clear_window(key->mlx, key->win);
		key->color = key->color == 0xFFFFFF ? 0x000000 : key->color;
		if (keycode == 15)
			key->color = (key->color | 0xFF0000) == key->color ?
				key->color & 0x00FFFF : key->color | 0xFF0000;
		else if (keycode == 5)
			key->color = (key->color | 0x00FF00) == key->color ?
				key->color & 0xFF00FF : key->color | 0x00FF00;
		else if (keycode == 11)
			key->color = (key->color | 0x0000FF) == key->color ?
				key->color & 0xFFFF00 : key->color | 0x0000FF;
		key->color = key->color == 0x000000 ? 0xFFFFFF : key->color;
		drawing(key);
	}
}

void		zoom(int keycode, t_fdf *key)
{
	if (keycode == 67 && key->sx * 2 <= 500 && key->sy * 2 <= 500)
	{
		mlx_clear_window(key->mlx, key->win);
		key->sx *= 2;
		key->sy *= 2;
		key->z *= 2;
		drawing(key);
	}
	else if (keycode == 75 && key->sx / 2 > 0 && key->sy / 2 > 0)
	{
		mlx_clear_window(key->mlx, key->win);
		if (key->z / 2 != 0)
		{
			key->sx /= 2;
			key->sy /= 2;
			key->z /= 2;
		}
		else if (key->z == 0)
		{
			key->sx /= 2;
			key->sy /= 2;
		}
		drawing(key);
	}
}

void		move(int keycode, t_fdf *key)
{
	if (keycode >= 123 && keycode <= 126)
	{
		mlx_clear_window(key->mlx, key->win);
		if (keycode == 123)
			key->dx -= 10;
		else if (keycode == 124)
			key->dx += 10;
		else if (keycode == 125)
			key->dy += 10;
		else if (keycode == 126)
			key->dy -= 10;
		drawing(key);
	}
}

int			keyboard(int keycode, t_fdf *key)
{
	if (keycode == 53)
		exit(0);
	else if (keycode == 34 || keycode == 35 || keycode == 71 ||
			keycode == 78 || keycode == 69)
	{
		mlx_clear_window(key->mlx, key->win);
		if (keycode == 34)
			key->info = key->info == 0 ? 1 : 0;
		else if (keycode == 35)
			key->proj = key->proj == 0 ? 1 : 0;
		else if (keycode == 71)
			key->init = 1;
		else if (keycode == 78)
			key->z--;
		else if (keycode == 69)
			key->z++;
		drawing(key);
	}
	move(keycode, key);
	zoom(keycode, key);
	color(keycode, key);
	return (0);
}
