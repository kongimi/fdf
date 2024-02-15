/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiyapan <npiyapan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 12:55:03 by npiyapan          #+#    #+#             */
/*   Updated: 2024/02/15 11:02:32 by npiyapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/minilibx-linux/mlx.h"
#include "../inc/main.h"

int	check_file_name(char *filename)
{
	size_t	len;

	len = ft_strlen(filename);
	if (len < 4)
		return (1);
	if (ft_strncmp(&filename[len - 4], ".fdf", 4))
		return (1);
	return (0);
}

int	check_input(int argc, char **argv)
{
	int	fd;

	if (argc != 2)
		return (ft_putstr_fd("Usage: ./fdf <map_path>\n", 2), 1);
	if (check_file_name(argv[1]))
		return (ft_putstr_fd("Invalid *.fdf\n", 2), 1);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		close (fd);
		return (ft_putstr_fd("Invalid filename.\n", 2), 1);
	}
	close (fd);
	return (0);
}

int	main(int argc, char **argv)
{
	t_meta		meta;

	ft_bzero(&meta, sizeof(t_meta));
	if (check_input(argc, argv))
		return (1);
	read_map(&meta, argv[1]);
	init_monitor(&meta);
	init_table(&meta);
	draw_map(&meta);
	mlx_put_image_to_window(meta.vars.mlx, meta.vars.win, meta.img.img, 0, 0);
	mlx_key_hook(meta.vars.win, key_hook, &meta);
	mlx_hook(meta.vars.win, 17, 0L, close_win, &meta);
	mlx_loop(meta.vars.mlx);
	exit (0);
}
