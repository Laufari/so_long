/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laufarin <laufarin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 17:36:26 by laufarin          #+#    #+#             */
/*   Updated: 2024/06/21 20:58:18 by laufarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_fill_map(t_checker *c, t_map_data *info, int i, int j)
{
	if (c->map_cpy[i][j] == '1' || c->collect_left == 0)
		return ;
	if ((c->map_cpy[i][j] == 'C') || (c->map_cpy[i][j] == 'E'))
		c->collect_left--;
	c->map_cpy[i][j] = '1';
	check_fill_map(c, info, i + 1, j);
	check_fill_map(c, info, i - 1, j);
	check_fill_map(c, info, i, j + 1);
	check_fill_map(c, info, i, j - 1);
}
