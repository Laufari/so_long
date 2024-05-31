/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laufarin <laufarin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 15:48:28 by laufarin          #+#    #+#             */
/*   Updated: 2024/03/20 17:40:05 by laufarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H


#include "./minilibx/mlx.h"
#include "./nombre de mi archivo/libft.h"
#include <stdio.h>
#include <unistd.h>

typedef struct s_vars
{
	void	*mlx;
	void	*window;
	char	**map;
	int		heigh;
	int		width;
	int		x;
	int		y;
	int		n_collect;
	int		n_moves;
}	t-vars;

typedef struct s_image
{
	char	*img;


}	t_image;

// CHECKER_MAPS //

int	checker_maps();
int	map_no_rect();
int	map_no_close();
int	map_size_min();
int	map_size_max();
int	map_correct_char()

#endif

