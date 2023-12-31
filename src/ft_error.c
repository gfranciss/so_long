/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfrancis <gfrancis@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 10:13:42 by gfrancis          #+#    #+#             */
/*   Updated: 2023/09/01 14:39:07 by gfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	ft_error_program(t_program *program, int erro)
{
	if (erro == 0)
		ft_putstr_fd("ERROR\n", 2);
	if (erro == 1)
		ft_putstr_fd("Wrong map extension\n", 2);
	if (erro == 2)
		ft_putstr_fd("Don't have a map\n", 2);
	free(program);
	exit(0);
}

void	ft_error_map(t_program *program, char **map, int erro)
{
	if (erro == 0)
		ft_putstr_fd("ERROR\n", 2);
	if (erro == 1)
		ft_putstr_fd("Map not created\n", 2);
	if (erro == 2)
		ft_putstr_fd("Wrong walls at the map\n", 2);
	if (erro == 3)
		ft_putstr_fd("Do not satisfied the rules of the map\n", 2);
	if (erro == 4)
		ft_putstr_fd("Invalid map\n", 2);
	if (erro == 5)
		ft_putstr_fd("Invalid path\n", 2);
	ft_free_map (map);
	free(program);
	exit(0);
}
