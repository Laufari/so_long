/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_checker_maps.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laufarin <laufarin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 15:39:29 by laufarin          #+#    #+#             */
/*   Updated: 2024/06/29 21:14:39 by laufarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	general_checker_maps(t_map_data *info)
{
	if (!map_is_rect(info))
		return (0);
	if (!map_is_close(info))
		return (0);
	if (!map_size_max(info))
		return (0);
	if (!map_correct_char(info->map))
		return (0);
	if (!map_correct_objects(info))
		return (0);
	return (1);
}
