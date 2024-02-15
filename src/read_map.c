/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiyapan <npiyapan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 10:07:09 by npiyapan          #+#    #+#             */
/*   Updated: 2024/02/11 13:12:15 by npiyapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/minilibx-linux/mlx.h"
#include "../inc/main.h"

void	map_lstadd_back(t_listmap **lst, t_listmap *new)
{
	t_listmap	*tmp;

	tmp = *lst;
	if (!tmp)
		*lst = new;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

void	map_lstclear(t_listmap *lst)
{
	t_listmap	*tmp;

	if (!lst)
		return ;
	while (lst)
	{
		tmp = (lst)->next;
		free (lst);
		lst = tmp;
	}
	lst = NULL;
}

int	find_color(char *color)
{
	if (color)
		return (ft_atoi_hex(color));
	return (0x00FFFFFF);
}

void	map_to_lst(t_meta *meta, t_mytmp *tmp)
{
	t_listmap	*newlst;
	char		**z_color;

	meta->map.split = ft_split(meta->map.gnl, ' ');
	meta->map.max = 0;
	meta->map.min = 0;
	while (meta->map.split[tmp->i])
	{
		newlst = (t_listmap *)malloc(sizeof(t_listmap));
		if (!newlst)
			print_error(3);
		newlst->x = tmp->i;
		newlst->y = tmp->y;
		z_color = ft_split(meta->map.split[tmp->i], ',');
		newlst->z = ft_atoi(z_color[0]);
		if (newlst->z > meta->map.max)
			meta->map.max = newlst->z;
		newlst->color = find_color(z_color[1]);
		ft_free_split(z_color);
		newlst->next = NULL;
		map_lstadd_back(&meta->map.lst_map, newlst);
		tmp->i++;
	}
	meta->map.column = tmp->i;
}

void	read_map(t_meta *meta, char *filename)
{
	int			fd;
	t_mytmp		tmp;

	ft_bzero(&tmp, sizeof(t_mytmp));
	fd = open(filename, O_RDONLY);
	meta->map.lst_map = NULL;
	while (1)
	{
		meta->map.gnl = get_next_line(fd);
		if (!meta->map.gnl)
			break ;
		map_to_lst(meta, &tmp);
		tmp.y++;
		tmp.i = 0;
		free (meta->map.gnl);
		ft_free_split(meta->map.split);
	}
	meta->map.row = tmp.y;
	close(fd);
}
