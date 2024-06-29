/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laufarin <laufarin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 17:11:17 by laufarin          #+#    #+#             */
/*   Updated: 2024/06/29 22:23:17 by laufarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	main(int argc, char **argv)
{
	t_images	img;
	t_map_data	info;

	so_long(argc, argv, &img, ft_memset(&info, 0, sizeof(t_map_data)));
}

int	so_long(int argc, char **argv, t_images *img, t_map_data *info)
{
	t_checker	c;

	if (argc == 2)
		get_map(argv[1], info);
	else
	{
		ft_putstr_fd("ERROR:\nInvalid amount arg\n", 2);
		exit(EXIT_FAILURE);
	}
	c.map_cpy = ft_split(info->big_str, '\n');
	free(info->big_str);
	c.collect_left = info->n_collect + 1;
	check_fill_map(&c, info, info->player_y, info->player_x);
	if (c.collect_left != 0)
	{
		ft_printf("ERROR:\nThere is no possible solution for the game\n");
		exit(0);
	}
	else
		setup_game(info, img);
	return (0);
}
