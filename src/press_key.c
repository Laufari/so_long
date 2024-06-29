/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laufarin <laufarin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 16:47:30 by laufarin          #+#    #+#             */
/*   Updated: 2024/06/29 22:20:20 by laufarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	move_right(t_map_data *info, t_images *img)
{
	int	x;
	int	y;

	x = info->player_x;
	y = info->player_y;
	if (y - 1 >= 0 && info->map[x][y + 1] != '1')
	{
		if (info->map[x][y + 1] == 'E' &&
			info->count_collect != info->n_collect)
			return ;
		if (info->map[x][y + 1] == 'E' &&
			info->count_collect == info->n_collect)
			clear_win_game(info);
		if (info->map[x][y + 1] == 'C')
			info->count_collect++;
		info->map[x][y] = '0';
		info->map[x][y + 1] = 'P';
		info->n_moves++;
		info->player_y++;
		ft_printf("Total kisses: %d\n", info->count_collect);
		ft_printf("Num. moves player: %d\n", info->n_moves);
		draw_background(info, img);
		render_map_objects(info, img);
	}
}

void	move_left(t_map_data *info, t_images *img)
{
	int	x;
	int	y;

	x = info->player_x;
	y = info->player_y;
	if (y - 1 >= 0 && info->map[x][y - 1] != '1')
	{
		if (info->map[x][y - 1] == 'E' &&
			info->count_collect != info->n_collect)
			return ;
		if (info->map[x][y - 1] == 'E' &&
			info->count_collect == info->n_collect)
			clear_win_game(info);
		if (info->map[x][y - 1] == 'C')
			info->count_collect++;
		info->map[x][y] = '0';
		info->map[x][y - 1] = 'P';
		info->n_moves++;
		info->player_y--;
		ft_printf("Total kisses: %d\n", info->count_collect);
		ft_printf("Num. moves player: %d\n", info->n_moves);
		draw_background(info, img);
		render_map_objects(info, img);
	}
}

void	move_down(t_map_data *info, t_images *img)
{
	int	x;
	int	y;

	x = info->player_x;
	y = info->player_y;
	if (x - 1 >= 0 && info->map[x + 1][y] != '1')
	{
		if (info->map[x + 1][y] == 'E' &&
			info->count_collect != info->n_collect)
			return ;
		if (info->map[x + 1][y] == 'E' &&
			info->count_collect == info->n_collect)
			clear_win_game(info);
		if (info->map[x + 1][y] == 'C')
			info->count_collect++;
		info->map[x][y] = '0';
		info->map[x + 1][y] = 'P';
		info->n_moves++;
		info->player_x++;
		ft_printf("Total kisses: %d\n", info->count_collect);
		ft_printf("Num. moves player: %d\n", info->n_moves);
		draw_background(info, img);
		render_map_objects(info, img);
	}
}

void	move_up(t_map_data *info, t_images *img)
{
	int	x;
	int	y;

	x = info->player_x;
	y = info->player_y;
	if (x - 1 >= 0 && info->map[x - 1][y] != '1')
	{
		if (info->map[x - 1][y] == 'E' &&
			info->count_collect != info->n_collect)
			return ;
		if (info->map[x - 1][y] == 'E' &&
			info->count_collect == info->n_collect)
			clear_win_game(info);
		if (info->map[x - 1][y] == 'C')
			info->count_collect++;
		info->map[x][y] = '0';
		info->map[x - 1][y] = 'P';
		info->n_moves++;
		info->player_x--;
		ft_printf("Total kisses: %d\n", info->count_collect);
		ft_printf("Num. moves player: %d\n", info->n_moves);
		draw_background(info, img);
		render_map_objects(info, img);
	}
}

int	key_press(int keycode, t_map_data *info)
{
	if (keycode == 65307)
		exit_game(info);
	else if (keycode == KEY_W || keycode == 65362)
		move_up(info, info->images);
	else if (keycode == KEY_S || keycode == 65364)
		move_down(info, info->images);
	else if (keycode == KEY_D || keycode == 65363)
		move_right(info, info->images);
	else if (keycode == KEY_A || keycode == 65361)
		move_left(info, info->images);
	return (0);
}
