/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiyapan <npiyapan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 15:07:09 by npiyapan          #+#    #+#             */
/*   Updated: 2024/02/11 13:11:55 by npiyapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/minilibx-linux/mlx.h"
#include "../inc/main.h"
#include <stdio.h>

#define PI 3.141592654

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

void	draw_line(t_data *data, t_mytmp *tmp, t_monitor monitor)
{
	double	pos[2];
	int		tmp_color;

	tmp->step = tmp->ab_del_y;
	if (tmp->ab_del_x > tmp->ab_del_y)
		tmp->step = tmp->ab_del_x;
	pos[0] = tmp->x;
	pos[1] = tmp->y;
	tmp->i = 0;
	tmp_color = tmp->color;
	while (tmp->i < tmp->step)
	{
		tmp_color += (tmp->color2 - tmp->color) / tmp->step;
		if ((pos[1] < monitor.height) && (pos[0] < monitor.width))
			my_mlx_pixel_put(data, pos[0], pos[1], tmp_color);
		pos[0] += tmp->del_x / tmp->step;
		pos[1] += tmp->del_y / tmp->step;
		tmp->i++;
	}
}

// t_mytmp	set_point(int x1, int y1, int x2, int y2)
// {
// 	t_mytmp	tmp;

// 	tmp.x = x1;
// 	tmp.y = y1;
// 	tmp.x2 = x2;
// 	tmp.y2 = y2;
// 	tmp.del_x = tmp.x2 - tmp.x;
// 	tmp.del_y = tmp.y2 - tmp.y;
// 	tmp.ab_del_x = fabs(tmp.x2 - tmp.x);
// 	tmp.ab_del_y = fabs(tmp.y2 - tmp.y);
// 	return (tmp);
// }

void	set_next_point(t_position *pos)
{
	pos->x1 = pos->x2;
	pos->y1 = pos->y2;
	pos->x2 = pos->x1 + pos->del_x;
	pos->y2 = pos->y1 + pos->del_y;
	pos->del_x = pos->x2 - pos->x1;
	pos->del_y = pos->y2 - pos->y1;
}

t_mytmp	set_point_by_position(t_position *pos, double z1, double z2)
{
	t_mytmp		tmp;

	tmp.x = pos->x1;
	tmp.y = pos->y1 - (z1 * pos->z_scale);
	tmp.x2 = pos->x2;
	tmp.y2 = pos->y2 - (z2 * pos->z_scale);
	tmp.del_x = tmp.x2 - tmp.x;
	tmp.del_y = tmp.y2 - tmp.y;
	tmp.ab_del_x = fabs(tmp.x2 - tmp.x);
	tmp.ab_del_y = fabs(tmp.y2 - tmp.y);
	return (tmp);
}

t_mytmp	set_point_vertical(t_position *pos)
{
	t_mytmp		tmp;

	pos->x1 = pos->x2;
	pos->y1 = pos->y2;
	pos->x2 = pos->x1 - (pos->del_x * sin(pos->angle));
	pos->y2 = pos->y1 + (pos->del_x * cos(pos->angle));
	pos->del_x = pos->x2 - pos->x1;
	pos->del_y = pos->y2 - pos->y1;
	tmp.x = pos->x1;
	tmp.y = pos->y1;
	tmp.x2 = pos->x2;
	tmp.y2 = pos->y2;
	tmp.del_x = pos->del_x;
	tmp.del_y = pos->del_y;
	tmp.ab_del_x = fabs(tmp.x2 - tmp.x);
	tmp.ab_del_y = fabs(tmp.y2 - tmp.y);
	return (tmp);
}
