/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_extra.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laufarin <laufarin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 17:24:59 by laufarin          #+#    #+#             */
/*   Updated: 2024/06/29 22:20:34 by laufarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	player_pos(t_map_data *info)
{
	int	i;
	int	j;

	j = -1;
	while (info->map[++j])
	{
		i = 0;
		while (i < info->width)
		{
			if (info->map[j][i] == 'P')
			{
				info->player_x = j;
				info->player_y = i;
			}
			i++;
		}
	}
}

int	check_map_values(int player, int n_collect, int end)
{
	if (player != 1 || n_collect < 1 || end != 1)
	{
		ft_printf("ERROR\n Incorrect map values\n");
		exit(0);
	}
	return (1);
}
