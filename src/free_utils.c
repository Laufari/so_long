/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laufarin <laufarin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 15:26:15 by laufarin          #+#    #+#             */
/*   Updated: 2024/06/29 22:26:16 by laufarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

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

void	clear_win_game(t_map_data *info)
{
	free_map(info->map);
	mlx_destroy_window(info->mlx, info->window);
	ft_printf("CONGRATS!! YOU WIN!!!\n");
	ft_printf("Let's play again? :D \n");
	exit(0);
}

int	exit_game(t_map_data *info)
{
	mlx_destroy_window(info->mlx, info->window);
	free_map(info->map);
	ft_printf("Ooopss!..you left the game\n");
	exit (0);
}

int	error_exit(t_map_data *info)
{
	ft_printf("ERROR:\n in error_exit");
	free_map(info->map);
	mlx_destroy_window(info->mlx, info->window);
	exit (0);
}

void	*safe_malloc(size_t size)
{
	void	*ret;

	ret = malloc(size);
	if (!ret)
		ft_printf("ERROR:\n some wrong with the malloc");
	return (ret);
}
