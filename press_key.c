/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laufarin <laufarin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 16:47:30 by laufarin          #+#    #+#             */
/*   Updated: 2024/06/25 17:58:26 by laufarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int key_press(int keycode,t_map_data *info)
{
    if (keycode == 65307)
        exit_game(info);
    else if (keycode == KEY_W || keycode == 65362)
        move_up(info);
    else if(keycode == KEY_S|| keycode == 65364)
        move_down(info);
    else if (keycode == KEY_D|| keycode == KEY_RIGHT)
        move_right(info);
    else if(keycode == KEY_A || keycode == 65361)
        move_left(info);
    return(0);
}
void    move_right(t_map_data *info)
{


}
void    move_left(t_map_data *info)
{}

void    move_up(t_map_data *info)
{}

void    move_down(t_map_data *info)
{}