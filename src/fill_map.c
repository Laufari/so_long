/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laufarin <laufarin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 17:36:26 by laufarin          #+#    #+#             */
/*   Updated: 2024/06/29 19:37:19 by laufarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	check_fill_map(t_checker *c, t_map_data *info, int j, int i)
{
	if (c->map_cpy[i][j] == '1' || c->collect_left == 0)
		return ;
	if ((c->map_cpy[i][j] == 'C') || (c->map_cpy[i][j] == 'E'))
		c->collect_left--;
	c->map_cpy[i][j] = '1';
	check_fill_map(c, info, j + 1, i);
	check_fill_map(c, info, j - 1, i);
	check_fill_map(c, info, j, i + 1);
	check_fill_map(c, info, j, i - 1);
}
