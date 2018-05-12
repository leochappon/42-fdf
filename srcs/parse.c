/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchappon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 17:46:40 by lchappon          #+#    #+#             */
/*   Updated: 2018/05/12 20:03:31 by lchappon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			alloc_chars(t_fdf *parse, char *line, int y)
{
	int		x;
	char	**tab;

	x = 0;
	tab = ft_strsplit(line, ' ');
	if (!(parse->map[y] = ft_memalloc(sizeof(int) * parse->chars)))
		return (-1);
	while (tab[x])
	{
		parse->map[y][x] = ft_atoi(tab[x]);
		free(tab[x]);
		x++;
	}
	free(line);
	free(tab);
	return (0);
}

int			check_lines_length(t_fdf *parse, char *line)
{
	int		x;
	char	**tab;

	x = 0;
	tab = ft_strsplit(line, ' ');
	while (tab[x])
	{
		free(tab[x]);
		x++;
	}
	free(line);
	free(tab);
	if (parse->lines == 0)
		parse->chars = x;
	else if (x != parse->chars)
	{
		ft_putendl("Found wrong line length. Exiting.");
		return (-1);
	}
	parse->lines++;
	return (0);
}

int			alloc_lines(t_fdf *parse)
{
	char	*line;

	parse->lines = 0;
	parse->chars = 0;
	parse->fd = open(parse->name, O_RDONLY);
	while (get_next_line(parse->fd, &line) > 0)
	{
		if (check_lines_length(parse, line) == -1)
			return (-1);
	}
	if (!(parse->map = ft_memalloc(sizeof(int *) * parse->lines)))
		return (-1);
	close(parse->fd);
	return (0);
}

int			check_empty_file(t_fdf *parse)
{
	char	*line;

	parse->fd = open(parse->name, O_RDONLY);
	if (get_next_line(parse->fd, &line) <= 0)
	{
		ft_putendl("No data found.");
		return (-1);
	}
	free(line);
	return (0);
}

int			parsing(t_fdf *parse)
{
	char	*line;
	int		y;
	int		ret;

	y = 0;
	if (check_empty_file(parse) == -1)
		return (-1);
	if (alloc_lines(parse) == -1)
		return (-1);
	parse->fd = open(parse->name, O_RDONLY);
	while ((ret = get_next_line(parse->fd, &line)) > 0)
	{
		if (alloc_chars(parse, line, y) == -1)
			return (-1);
		y++;
	}
	close(parse->fd);
	return ((ret == -1) ? -1 : 0);
}
