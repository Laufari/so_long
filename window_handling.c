/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_handling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laufarin <laufarin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 18:37:38 by laufarin          #+#    #+#             */
/*   Updated: 2024/06/22 19:28:05 by laufarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"

void    configure_images(t_map_data *info, t_images *image)
{
    image->empty = mlx_xpm_file_to_image(info->mlx,"imgs/empty.xml",
            &image->img_width, &image->img_heigth);
    if(image->empty == NULL)
        error_exit(info);
    image->wall = mlx_xpm_file_to_image(info->mlx,"imgs/wall.xml",
            &image->img_width, &image->img_heigth);
    if(image->wall == NULL)
        error_exit(info);
    image->collect = mlx_xpm_file_to_image(info->mlx,"imgs/collect.xml",
            &image->img_width, &image->img_heigth);
    if(image->collect == NULL)
        error_exit(info);
    image->player = mlx_xpm_file_to_image(info->mlx,"imgs/player.xml",
            &image->img_width, &image->img_heigth);
    if(image->player == NULL)
        error_exit(info);
    image->exit = mlx_xpm_file_to_image(info->mlx,"imgs/exit.xml",
            &image->img_width, &image->img_heigth);
    if(image->exit == NULL)
        error_exit(info);
}
void   draw_background(t_map_data *info, t_images *img)
{
    img->j = 0;
    while (info->map[img->j])
    {
        img->i = 0;
        while (info->map[img->j][img->i])
        {
            mlx_put_image_to_window(info->mlx, info->window, img->empty,\
                                img->i * img->img_width, img->j * img->img_heigth);
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
					img->i * img->img_width, img->j * img->img_heigth);
			if (info->map[img->j][img->i] == 'C')
				mlx_put_image_to_window(info->mlx, info->window, img->collect,
					img->i * img->img_width, img->j * img->img_heigth);
			if (info->map[img->j][img->i] == 'P')
				mlx_put_image_to_window(info->mlx, info->window, img->player,
					img->i * img->img_width, img->j * img->img_heigth);
			if (info->map[img->j][img->i] == 'E')
				mlx_put_image_to_window(info->mlx, info->window, img->exit,
					img->i * img->img_width, img->j * img->img_heigth);
			img->i++;
		}
		img->j++;
	}
}
void    setup_game(t_map_data *info, t_images *image)
{
    image->img_width = 32;
    image->img_heigth = 32;
    info->mlx = mlx_init();
    info->window = mlx_new_window(info->mlx, info->width * image->img_width,\
                   info->height * image->img_heigth, "welcome_to_so_long");

    info->img = mlx_new_image(info->mlx, info->width * image->img_width,\
                   info->height * image->img_heigth);
    mlx_get_data_addr(&image->img_p, &image->bpp, &image->len_p, &image->endian);
    configure_images(info, image);
}
 //mlx_put_image_to_window(info->mlx, info->window, info->img, 0, 0);
   // mlx_loop(info->mlx);            