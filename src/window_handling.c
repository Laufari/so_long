/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_handling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laufarin <laufarin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 18:37:38 by laufarin          #+#    #+#             */
/*   Updated: 2024/06/29 20:33:42 by laufarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	configure_images(t_map_data *info, t_images *image)
{
	int	img_width;
	int	img_height;

	image->empty = mlx_xpm_file_to_image(info->mlx, "./textures/pasto.xpm",
			&img_width, &img_height);
	if (image->empty == NULL)
		error_exit(info);
	image->wall = mlx_xpm_file_to_image(info->mlx, "./textures/arbol.xpm",
			&img_width, &img_height);
	if (image->wall == NULL)
		error_exit(info);
	image->collect = mlx_xpm_file_to_image(info->mlx, "./textures/beso.xpm",
			&img_width, &img_height);
	if (image->collect == NULL)
		error_exit(info);
	image->player = mlx_xpm_file_to_image(info->mlx, "./textures/sapito.xpm",
			&img_width, &img_height);
	if (image->player == NULL)
		error_exit(info);
	image->exit = mlx_xpm_file_to_image(info->mlx, "./textures/castillo.xpm",
			&img_width, &img_height);
	if (image->exit == NULL)
		error_exit(info);
}

void	draw_background(t_map_data *info, t_images *img)
{
	img->j = 0;
	while (info->map[img->j])
	{
		img->i = 0;
		while (info->map[img->j][img->i])
		{
			mlx_put_image_to_window(info->mlx, info->window,
				info->images->empty,
				info->images->i * SIZE_IMG, info->images->j * SIZE_IMG);
			img->i++;
		}
		img->j++;
	}
}

void	render_map_objects(t_map_data *info, t_images *img)
{
	img->j = 0;
	while (info->map[img->j])
	{
		img->i = 0;
		while (info->map[img->j][img->i])
		{
			if (info->map[img->j][img->i] == '1')
				mlx_put_image_to_window(info->mlx, info->window, img->wall,
					img->i * 64, img->j * 64);
			if (info->map[img->j][img->i] == 'C')
				mlx_put_image_to_window(info->mlx, info->window, img->collect,
					img->i * 64, img->j * 64);
			if (info->map[img->j][img->i] == 'P')
				mlx_put_image_to_window(info->mlx, info->window, img->player,
					img->i * 64, img->j * 64);
			if (info->map[img->j][img->i] == 'E')
				mlx_put_image_to_window(info->mlx, info->window, img->exit,
					img->i * 64, img->j * 64);
			img->i++;
		}
		img->j++;
	}
}

void	setup_game(t_map_data *info, t_images *image)
{
	info->mlx = mlx_init();
	info->window = mlx_new_window(info->mlx, info->width * SIZE_IMG,
			info->height * SIZE_IMG, "KISS THE PRINCE <3");
	configure_images(info, image);
	info->images = image;
	draw_background(info, info->images);
	render_map_objects(info, image);
	mlx_hook(info->window, 2, X_EVENT_KEY_RELEASE, &key_press, info);
	mlx_hook(info->window, X_EVENT_KEY_EXIT, 0, &exit_game, info);
	mlx_loop(info->mlx);
}
