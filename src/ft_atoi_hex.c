/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiyapan <npiyapan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 15:28:41 by npiyapan          #+#    #+#             */
/*   Updated: 2024/02/08 15:30:44 by npiyapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/main.h"

int	is_hexa(char c)
{
	if (c == 'a' || c == 'A')
		return (10);
	else if (c == 'b' || c == 'B')
		return (11);
	else if (c == 'c' || c == 'C')
		return (12);
	else if (c == 'd' || c == 'D')
		return (13);
	else if (c == 'e' || c == 'E')
		return (14);
	else if (c == 'f' || c == 'F')
		return (15);
	return (c - 48);
}

int	ft_atoi_hex(char *str)
{
	int		i;
	int		result;

	i = 0;
	result = 0;
	while (str[i] == '0' || str[i] == 'x')
		i++;
	while (str[i])
	{
		result *= 16;
		result = result + is_hexa(str[i]);
		i++;
	}
	return (result);
}
