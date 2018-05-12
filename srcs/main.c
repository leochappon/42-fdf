/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchappon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 17:03:51 by lchappon          #+#    #+#             */
/*   Updated: 2018/05/09 19:16:03 by lchappon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		mlx(t_fdf *start)
{
	start->init = 1;
	start->proj = 0;
	start->info = 0;
	start->mlx = mlx_init();
	start->win = mlx_new_window(start->mlx, WIDTH, HEIGHT, start->name);
	drawing(start);
	mlx_key_hook(start->win, keyboard, start);
	mlx_loop(start->mlx);
}

int			main(int argc, char **argv)
{
	t_fdf		start;

	if (argc == 2)
	{
		start.name = argv[1];
		if (open(argv[1], O_RDONLY) == -1)
		{
			ft_putstr("No file ");
			ft_putendl(argv[1]);
			return (-1);
		}
		else
		{
			if (parsing(&start) == -1)
				return (-1);
			mlx(&start);
		}
	}
	else
	{
		ft_putendl("Usage : ./fdf <filename>");
		return (-1);
	}
	return (0);
}
