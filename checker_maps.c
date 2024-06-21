/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_maps.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laufarin <laufarin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 16:53:45 by laufarin          #+#    #+#             */
/*   Updated: 2024/06/21 20:38:00 by laufarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//comprobar que el mapa es rectangular
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
			ft_printf("ERROR: map is not rectangular\n");
			return (0);
		}
		i++;
	}
	return (1);
}

//comprobar que el mapa esta cerrado (o sea rodeado de 1)
int	map_is_close(t_map_data *info)
{
	int	i;

	i = 0;
	while (i < info->width)
	{
		if ((info->map[0][i] != '1') ||
			(info->map[info->height - 1][i] != '1'))
		{
			ft_printf("Error: First or last row error\n");
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
			ft_printf("Error en la fila %d\n", i + 1);
			return (0);
		}
		i++;
	}
	return (1);
}

//comprobar que el mapa no sea mas demasiado grande

int	map_size_max(t_map_data *info)
{
	if (info->height * info->width > 3040)
	{
		ft_printf("Error: map exceeds accepted dimensions");
		return (0);
	}
	return (1);
}

//comprbar que lo que hay en el mapa solo tenga 1, 0, P, E C
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
				ft_printf("ERROR Bad inputs\n");
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

//comprbar que lo que el mapa tenga un una sola P, una sola E y minimo una C
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
				info->x = j;
				info->y = i;
				printf("player esta en x: %d y:%d\n", j, i);
				info->player++;
			}
			if (info->map[j][i] == 'C')
				info->n_collect++;
			if (info->map[j][i] == 'E')
				end++;
			i++;
		}
	}
	if (info->player != 1 || info->n_collect < 1 || end != 1)
	{
		ft_printf("ERROR\n incorrect map values");
		return (0);
	}
	return (1);
}
