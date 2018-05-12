/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchappon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 16:58:18 by lchappon          #+#    #+#             */
/*   Updated: 2018/05/08 17:57:36 by lchappon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/includes/libft.h"
# include <fcntl.h>
# include <mlx.h>

# define WIDTH 1500
# define HEIGHT 1000

typedef struct		s_fdf
{
	void			*mlx;
	void			*win;
	char			*name;
	int				**map;
	int				lines;
	int				chars;
	int				z;
	int				dx;
	int				dy;
	int				sx;
	int				sy;
	int				init;
	int				proj;
	int				info;
	int				fd;
	int				color;
}					t_fdf;

int					parsing(t_fdf *parse);
int					keyboard(int keycode, t_fdf *key);
void				drawing(t_fdf *draw);
void				projection(t_fdf *draw, int x, int y);
void				bresenham(t_fdf *draw, int *tabxy, int x2, int y2);

#endif
