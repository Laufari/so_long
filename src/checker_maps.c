/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_maps.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laufarin <laufarin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 16:53:45 by laufarin          #+#    #+#             */
/*   Updated: 2024/06/29 22:12:10 by laufarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	map_is_rect(t_map_data *info)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	info->width = ft_strlen(info->map[i]);
	while (info->map[j])
		j++;
	info->height = j;
	while (i < info->height)
	{
		if ((int)ft_strlen(info->map[i]) != info->width)
		{
			ft_printf("ERROR:\n map is not rectangular\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	map_is_close(t_map_data *info)
{
	int	i;

	i = 0;
	while (i < info->width)
	{
		if ((info->map[0][i] != '1') ||
			(info->map[info->height - 1][i] != '1'))
		{
			ft_printf("ERROR:\n the map is open First or last row error\n");
			return (0);
		}
		i++;
	}
	i = 0;
	while (i < info->height)
	{
		if ((info->map[i][0] != '1') ||
			(info->map[i][info->width - 1] != '1'))
		{
			ft_printf("ERROR:\n the map is open in row: %d\n", i + 1);
			return (0);
		}
		i++;
	}
	return (1);
}

int	map_size_max(t_map_data *info)
{
	if (info->height > 40 || info->width > 76)
	{
		ft_printf("ERROR:\n map exceeds accepted dimensions");
		return (0);
	}
	return (1);
}

int	map_correct_char(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '1' && map[i][j] != '0' && \
				map[i][j] != 'P' && map[i][j] != 'C' && \
				map[i][j] != 'E')
			{
				ft_printf("ERROR:\n Bad inputs\n");
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	map_correct_objects(t_map_data *info)
{
	int	i;
	int	j;
	int	end;

	j = -1;
	end = 0;
	while (info->map[++j])
	{
		i = 0;
		while (i < info->width)
		{
			if (info->map[j][i] == 'P')
			{
				player_pos(info);
				info->player++;
			}
			if (info->map[j][i] == 'C')
				info->n_collect++;
			if (info->map[j][i] == 'E')
				end++;
			i++;
		}
	}
	check_map_values(info->player, info->n_collect, end);
	return (1);
}
