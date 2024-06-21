/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laufarin <laufarin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 15:48:28 by laufarin          #+#    #+#             */
/*   Updated: 2024/06/21 21:19:07 by laufarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./minilibx-linux/mlx.h"
# include "./libft/libft.h"
# include <stdio.h>
# include <unistd.h>

typedef struct s_images
{
	char	*img;
	void	*collect;
	void	*empty;
	void	*exit;
	void	*player;
	void	*wall;
	void	*winner;
	int		img_width;
	int		img_heigth;	
}	t_images;

typedef struct s_checker
{
	char	**map_cpy;
	int		collect_left;
}	t_checker;

typedef struct s_map_data
{
	void		*mlx;
	void		*window;
	char		**map;
	int			height;
	int			width;
	int			x;
	int			y;
	int			player;
	int			n_collect;
	int			n_moves;
	int			fd;
	char		*big_str;
	void		*right;
	void		*left;
	void		*down;
	void		*up;
	t_images	*images;
}	t_map_data;

// CHECKER_MAPS //

int			map_is_rect(t_map_data *info);
int			map_is_close(t_map_data *info);
int			map_size_max(t_map_data *info);
int			map_correct_char(char **map);
int			map_correct_objects(t_map_data *info);
void		check_fill_map(t_checker *c, t_map_data *info, int i, int j);
t_checker	*cpy_map(t_checker *c, t_map_data *info);

//CHEC_FILE

int			is_ber(char *str);
void		get_miap(char *path, t_map_data *info);

//MAIN

int			general_checker_maps(t_map_data *info);

//FUNCIONES EXTRAS

void		*safe_malloc(size_t size);

#endif
