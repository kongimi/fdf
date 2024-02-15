/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiyapan <npiyapan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 15:08:58 by npiyapan          #+#    #+#             */
/*   Updated: 2024/02/11 14:57:49 by npiyapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include "../lib/libft/include/libft.h"
# include "../lib/libft/include/get_next_line.h"

typedef struct s_monitor
{
	int	height;
	int	width;
}	t_monitor;

typedef struct s_position
{
	double	x1;
	double	y1;
	double	x2;
	double	y2;
	double	offset;
	double	del_x;
	double	del_y;
	double	angle;
	double	scale;
	double	z_scale;
	double	pi;
}	t_position;

typedef struct s_list_map
{
	int					x;
	int					y;
	int					z;
	int					color;
	int					min;
	int					max;
	struct s_list_map	*next;
}			t_listmap;

typedef struct m_map
{
	int			tmp;
	int			column;
	int			row;
	int			min;
	int			max;
	char		*raw_dat;
	char		*tmp_char;
	char		*gnl;
	char		**split;
	t_listmap	*lst_map;
}	t_map;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}	t_vars;

typedef struct s_mytmp
{
	int		i;
	int		j;
	double	x;
	double	y;
	double	z;
	double	x2;
	double	y2;
	double	z2;
	double	pos[2];
	double	del_x;
	double	del_y;
	int		ab_del_x;
	int		ab_del_y;
	int		step;
	int		row;
	int		column;
	int		color;
	int		color2;
}	t_mytmp;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_meta
{
	t_data		img;
	t_vars		vars;
	t_mytmp		my_tmp;
	t_map		map;
	int			**tab;
	int			**color;
	t_position	pos;
	t_monitor	monitor;
	int			*ptr;
	int			*ptr_color;
	int			len;
}	t_meta;

void	read_map(t_meta *meta, char *filename);
void	map_print(t_listmap *lst);
void	map_lstclear(t_listmap *lst);

t_mytmp	set_point(int x1, int y1, int x2, int y2);
t_mytmp	set_point_by_matrix(int x1, int y1, int x2, int y2);
t_mytmp	set_point_by_position(t_position *pos, double z1, double z2);
void	set_next_point(t_position *pos);
t_mytmp	set_point_from_lst(t_listmap **lmap, int column);
void	draw_line(t_data *data, t_mytmp *my_tmp, t_monitor monitor);
void	draw_rectangle(t_data *data, t_mytmp *tmp, int color);
int		ft_atoi_hex(char *str);

// int		close(int keycode, t_vars *vars);
int		close_win(void *param);
int		mouse_hook(int keycode, int x, int y, t_vars *vars);
int		key_hook(int keycode, t_meta *meta);

void	init_monitor(t_meta *meta);
void	init_table(t_meta *meta);
void	load_table(t_meta *meta);
void	init_position(t_meta *meta);

void	init_first_horizon(t_position *pos, int line);
void	init_first_vertical(t_position *pos, int line);
void	draw_horizon(t_meta *meta);
void	draw_vertical(t_meta *meta);
void	draw_map(t_meta *meta);

void	print_error(int err);
#endif
