/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laufarin <laufarin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 15:58:06 by laufarin          #+#    #+#             */
/*   Updated: 2024/06/29 22:22:38 by laufarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

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

static int	is_open(const char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		perror("ERROR:\n failure opening file\n");
		exit (0);
	}
	return (fd);
}

void	get_map(char *path, t_map_data *info)
{
	char	*line;

	if (!is_ber(path))
	{
		ft_printf("ERROR\n");
		exit(0);
	}
	info->fd = is_open(path);
	line = get_next_line(info->fd);
	if (line == NULL)
	{
		ft_printf("ERROR\n");
		exit(0);
	}
	while (line)
	{
		info->big_str = ft_strjoin_gn(info->big_str, line);
		free(line);
		line = get_next_line(info->fd);
	}
	close(info->fd);
	info->map = ft_split(info->big_str, '\n');
	if (!general_checker_maps(info))
		exit(0);
}
