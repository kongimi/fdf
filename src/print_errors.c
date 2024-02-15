/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_err.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiyapan <npiyapan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 11:42:58 by npiyapan          #+#    #+#             */
/*   Updated: 2024/02/11 11:43:38 by npiyapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/main.h"

void	print_error(int err)
{
	if (err == 1)
		ft_putendl_fd("File Error.", 2);
	else if (err == 2)
		ft_putendl_fd("Malloc Error.", 2);
	else if (err == 3)
		ft_putendl_fd("New List Error.", 2);
	exit(1);
}
