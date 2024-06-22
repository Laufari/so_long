/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laufarin <laufarin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 15:26:15 by laufarin          #+#    #+#             */
/*   Updated: 2024/06/22 16:09:57 by laufarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"

char	*free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
	return (0);
}

int	error_exit(t_map_data *info)
{
	write(1, "Error\n", 7);
	free_map(info->map);
	mlx_destroy_window(info->mlx, info->window);
	exit (0);
}
void	*safe_malloc(size_t size)
{
	void	*ret;

	ret = malloc(size);
	if (!ret)
		ft_printf("Error with the malloc");
	return (ret);
}