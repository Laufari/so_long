/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laufarin <laufarin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 17:11:17 by laufarin          #+#    #+#             */
/*   Updated: 2024/06/22 18:41:06 by laufarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_images	*img;
	t_map_data *info;
	t_checker	c;

	img = malloc(sizeof(t_images));
	if(img == NULL)
		return(EXIT_FAILURE);
	info = (t_map_data *)malloc(sizeof(t_map_data));
	if (info == NULL) 
	{
    	perror("Error allocating memory");
    	return (free(img), EXIT_FAILURE);
	}
	info = ft_memset(info, 0, sizeof(t_map_data));
	if (argc == 2)
	{
		printf("hola son dos\n");
		printf("%d\n", is_ber(argv[1]));
		get_map(argv[1],info); //lee el fd con el
		printf("hola aqui 2\n");
	}
	else
		ft_putstr_fd("no valido cantidad arg", 2);
	c.map_cpy = ft_split(info->big_str, '\n');
	c.collect_left = info->n_collect + 1;

	check_fill_map(&c, info, info->y , info->x);
	if (c.collect_left == 0)
		printf("map is valid\n");
	else 
		printf("issue with map\n");
	setup_game(info, img);
	free(info);	
	return (0);
}
