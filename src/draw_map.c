/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiyapan <npiyapan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 11:21:15 by npiyapan          #+#    #+#             */
/*   Updated: 2024/02/11 15:35:48 by npiyapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/main.h"

void	init_first_horizon(t_position *pos, int line)
{
	pos->x1 = pos->offset - (sin(pos->angle) * line * pos->scale);
	pos->y1 = pos->offset + (cos(pos->angle) * line * pos->scale);
	pos->x2 = pos->x1 + pos->scale;
	pos->del_x = pos->x2 - pos->x1;
	pos->y2 = pos->y1;
	pos->del_y = pos->y2 - pos->y1;
	pos->x2 = pos->x1 + (pos->del_x * cos(pos->angle));
	pos->y2 = pos->y1 + (pos->del_x * sin(pos->angle));
	pos->del_x = pos->x2 - pos->x1;
	pos->del_y = pos->y2 - pos->y1;
}

void	init_first_vertical(t_position *pos, int line)
{
	pos->x1 = pos->offset + (cos(pos->angle) * line * pos->scale);
	pos->y1 = pos->offset + (sin(pos->angle) * line * pos->scale);
	pos->x2 = pos->x1 + pos->scale;
	pos->del_x = pos->x2 - pos->x1;
	pos->y2 = pos->y1;
	pos->del_y = pos->y2 - pos->y1;
	pos->x2 = pos->x1 - (pos->del_x * sin(pos->angle));
	pos->y2 = pos->y1 + (pos->del_x * cos(pos->angle));
	pos->del_x = pos->x2 - pos->x1;
	pos->del_y = pos->y2 - pos->y1;
}

void	draw_horizon(t_meta *meta)
{
	t_mytmp	mytmp;

	mytmp.row = -1;
	while (++mytmp.row < meta->map.row)
	{
		init_first_horizon(&meta->pos, mytmp.row);
		mytmp.column = 0;
		while (mytmp.column < (meta->map.column - 1))
		{
			mytmp.z = meta->tab[mytmp.row][mytmp.column];
			mytmp.z2 = meta->tab[mytmp.row][mytmp.column + 1];
			meta->my_tmp = set_point_by_position(&meta->pos, mytmp.z, mytmp.z2);
			meta->my_tmp.color = meta->color[mytmp.row][mytmp.column];
			meta->my_tmp.color2 = meta->color[mytmp.row][mytmp.column + 1];
			draw_line(&meta->img, &meta->my_tmp, meta->monitor);
			set_next_point(&meta->pos);
			mytmp.column++;
		}
	}
}

void	draw_vertical(t_meta *meta)
{
	t_mytmp	mytmp;

	mytmp.column = -1;
	while (++mytmp.column < meta->map.column)
	{
		init_first_vertical(&meta->pos, mytmp.column);
		mytmp.row = 0;
		while (mytmp.row < (meta->map.row - 1))
		{
			mytmp.z = meta->tab[mytmp.row][mytmp.column];
			mytmp.z2 = meta->tab[mytmp.row + 1][mytmp.column];
			meta->my_tmp = set_point_by_position(&meta->pos, mytmp.z, mytmp.z2);
			meta->my_tmp.color = meta->color[mytmp.row][mytmp.column];
			meta->my_tmp.color2 = meta->color[mytmp.row + 1][mytmp.column];
			draw_line(&meta->img, &meta->my_tmp, meta->monitor);
			set_next_point(&meta->pos);
			mytmp.row++;
		}
	}
}

void	draw_map(t_meta *meta)
{
	init_position(meta);
	draw_horizon(meta);
	draw_vertical(meta);
	free (meta->tab);
}
