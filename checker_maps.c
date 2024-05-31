/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_maps.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laufarin <laufarin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 16:53:45 by laufarin          #+#    #+#             */
/*   Updated: 2024/03/20 17:38:10 by laufarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//comprobar que el mapa es rectangular
int	map_no_rect()

//comprobar que el mapa esta cerrado (o sea rodeado de 1)
int	map_no_close()

// compronbar que el mapa no sea mas peque que 3x5
int	map_size_min()

// comprobar que el mapa no sea mas grande que     
int	map_size_max()

//comprbar que que haya solo una P, una E  una C
int	map_correct_char()

//chequear que el mapa cumpla con las condiciones que pide el subjects

int	checker_maps(ya miro que le paso)
{
	if (!map_no_rect(paso mapa))
		return (0);
	if (!map_no_close(mapa))
		return (0);
	if (!map_size_min())
		return (0);
	if (!map_size_max())
		return (0);
	if (!map_correct_char())
		return (0);
	return (1);
}
