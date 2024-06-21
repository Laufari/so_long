/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laufarin <laufarin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 16:06:17 by laufarin          #+#    #+#             */
/*   Updated: 2024/06/21 20:52:29 by laufarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_ber(char *str)
{
	int		len;
	char	*suffix;

	suffix = ".ber";
	len = ft_strlen(str);
	if (len < 4)
	{
		return (0);
	}
	return (ft_strncmp(str + len - 4, suffix, 5) == 0);
}
//intentar abrir //OPEN si me devuelve menor de cero es que ha fallado
//ERroR.i.. 
//al abrirlo me va a generrar un FD que es lo que lo que le pasare al Get_;
// Definición de la función is_open

static int	is_open(const char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file");
		return (0);
	}
	return (fd);
}

void	get_map(char *path, t_map_data *info)
{
	char	*line;

	info->fd = is_open(path);
	line = get_next_line(info->fd);
	if (line == NULL)
	{
		ft_printf("ERROR");
	}
	while (line)
	{
		info->big_str = ft_strjoin_gn(info->big_str, line);
		free(line);
		line = get_next_line(info->fd);
		printf("%s\n", line);
	}
	close(info->fd);
	info->map = ft_split(info->big_str, '\n');
	if (!general_checker_maps(info))
	{
		return (ft_putstr_fd("map error", 2));
	}
}
