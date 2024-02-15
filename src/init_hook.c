/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiyapan <npiyapan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 13:58:54 by npiyapan          #+#    #+#             */
/*   Updated: 2024/02/13 11:42:14 by npiyapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/minilibx-linux/mlx.h"
#include "../inc/main.h"
#include <stdio.h>

int	close_win(void *param)
{
	t_meta	*meta;

	meta = (t_meta *)param;
	mlx_destroy_window(meta->vars.mlx, meta->vars.win);
	mlx_destroy_image(meta->vars.mlx, meta->img.img);
	exit(0);
}

int	mouse_hook(int keycode, int x, int y, t_vars *vars)
{
	(void)x;
	(void)y;
	if ((keycode == 1) || (keycode == 2) || (keycode == 3))
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit (0);
	}
	else if (keycode == 4)
		printf("scroll up\n");
	else if (keycode == 5)
		printf("scroll down\n");
	return (0);
}

int	key_hook(int keycode, t_meta *meta)
{
	if (keycode == 65307)
	{
		mlx_destroy_window(meta->vars.mlx, meta->vars.win);
		mlx_destroy_image(meta->vars.mlx, meta->img.img);
		exit (0);
	}
	return (0);
}
