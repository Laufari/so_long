/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laufarin <laufarin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 15:48:28 by laufarin          #+#    #+#             */
/*   Updated: 2024/06/29 20:58:49 by laufarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libs/mlx/mlx.h"
# include "../libs/libft/libft.h"
# include <stdio.h>
# include <unistd.h>

# define KEY_ESC	65307
# define KEY_W		119
# define KEY_A		97
# define KEY_S		115
# define KEY_D		100  
# define KEY_RIGHT	6536
# define SIZE_IMG	64

# define X_EVENT_KEY_EXIT 17
# define X_EVENT_KEY_RELEASE 3

typedef struct s_images
{
	char	*img_p;
	int		bpp;
	int		len_p;
	int		endian;
	void	*collect;
	void	*empty;
	void	*exit;
	void	*player;
	void	*wall;
	void	*winner;
	int		i;
	int		j;
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
	int			player_x;
	int			player_y;
	int			player;
	int			n_collect;
	int			count_collect;
	int			n_moves;
	int			exit;
	int			exit_x;
	int			exit_y;
	int			fd;
	char		*big_str;
	void		*right;
	void		*left;
	void		*down;
	void		*up;
	void		*img;
	t_images	*images;
}	t_map_data;

// CHECKER_MAPS //

int			map_is_rect(t_map_data *info);
int			map_is_close(t_map_data *info);
int			map_size_max(t_map_data *info);
int			map_correct_char(char **map);
int			map_correct_objects(t_map_data *info);

//FILL_MAP
void		check_fill_map(t_checker *c, t_map_data *info, int i, int j);
//int			check_map_resolt(t_map_data *info, t_checker *check);

//CHECK_FILE

int			is_ber(char *str);
void		get_map(char *path, t_map_data *info);

//WINDOW_HANDLING

void		configure_images(t_map_data *info, t_images *img);
void		draw_background(t_map_data *info, t_images *img);
void		setup_game(t_map_data *info, t_images *img);
void		render_map_objects(t_map_data *info, t_images *img);

//PRESS_KEY

int			key_press(int keycode, t_map_data *info);
void		move_right(t_map_data *info, t_images *img);
void		move_left(t_map_data *info, t_images *img);
void		move_up(t_map_data *info, t_images *img);
void		move_down(t_map_data *info, t_images *img);

//MAIN

int			general_checker_maps(t_map_data *info);
int			so_long(int argc, char **argv, t_images *img, t_map_data *info);

//FREE_UTILS

char		*free_map(char **map);
int			exit_game(t_map_data *info);
void		clear_win_game(t_map_data *info);
int			error_exit(t_map_data *info);
void		*safe_malloc(size_t size);

//UTILS_EXTRA

void		player_pos(t_map_data *info);
int			check_map_values(int player, int n_collect, int end);

#endif
