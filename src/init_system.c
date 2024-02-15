/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_system.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiyapan <npiyapan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 11:16:09 by npiyapan          #+#    #+#             */
/*   Updated: 2024/02/15 10:50:13 by npiyapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/minilibx-linux/mlx.h"
#include "../inc/main.h"

void	init_monitor(t_meta *meta)
{
	meta->monitor.height = 1080;
	meta->monitor.width = 1920;
	meta->vars.mlx = mlx_init();
	meta->vars.win = mlx_new_window(meta->vars.mlx, meta->monitor.width, \
meta->monitor.height, "My window!");
	meta->img.img = mlx_new_image(meta->vars.mlx, 1920, 1080);
	meta->img.addr = mlx_get_data_addr(meta->img.img, &meta->img.bpp, \
&meta->img.line_length, &meta->img.endian);
}

void	init_table(t_meta *meta)
{
	int	row;
	int	column;

	row = meta->map.row;
	column = meta->map.column;
	meta->len = sizeof(int *) * row + sizeof(int) * column * (row);
	meta->tab = (int **)malloc(meta->len);
	meta->color = (int **)malloc(meta->len);
	meta->ptr = (int *)(meta->tab + meta->map.row);
	meta->ptr_color = (int *)(meta->color + meta->map.row);
	load_table(meta);
}

void	load_table(t_meta *meta)
{
	int			i;
	int			x;
	int			y;
	t_listmap	*listmap;

	i = -1;
	while (++i < meta->map.row)
	{
		meta->tab[i] = meta->ptr + (meta->map.column * i);
		meta->color[i] = meta->ptr_color + (meta->map.column * i);
	}
	while (meta->map.lst_map)
	{
		x = meta->map.lst_map->x;
		y = meta->map.lst_map->y;
		meta->tab[y][x] = meta->map.lst_map->z;
		meta->color[y][x] = meta->map.lst_map->color;
		listmap = meta->map.lst_map;
		meta->map.lst_map = meta->map.lst_map->next;
		free (listmap);
	}
}

void	init_position(t_meta *meta)
{
	int	height;

	height = meta->monitor.height;
	meta->pos.offset = 500;
	meta->pos.pi = 3.1415926536;
	meta->pos.angle = -30 * 0.0174532925;
	meta->pos.scale = meta->monitor.width / meta->map.column / 3;
	if (meta->pos.scale > 20)
		meta->pos.scale = 20;
	if (meta->map.max > 0)
	{
		meta->pos.z_scale = height / meta->map.max / meta->map.row / 2;
		if (meta->pos.z_scale > 20)
			meta->pos.z_scale = meta->pos.scale / 4;
		if (meta->pos.z_scale == 0)
			meta->pos.z_scale = 0.5;
	}
	else
		meta->pos.z_scale = 3;
}
