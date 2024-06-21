/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_handling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laufarin <laufarin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 18:37:38 by laufarin          #+#    #+#             */
/*   Updated: 2024/06/21 20:20:26 by laufarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"

configure_images(t_map_data *info, t_images *img)
{
    img->empty = mlx_xpm_file_to_image(info->mlx,"rutaimagen",
            &img->img_width, &img->img_heigth);
    if(img->empty == NULL)
        error_exit(img)




}
void    setup_game(t_map_data *info, t_images *img)
{
    img->img_width = 32;
    img->img_heigth = 32;
    info->mlx = mlx_init();
    info->window = mlx_new_window(info->mlx, info->width * img->img_width,\
                    info->height * img->img_heigth, "welcome_to_so_long");
    configure_images(info, img);                       


}