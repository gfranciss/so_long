/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_imagens.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfrancis <gfrancis@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 14:02:34 by gfrancis          #+#    #+#             */
/*   Updated: 2023/09/01 14:12:20 by gfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	ft_print_image(t_program *program, void *image, int i, int j)
{
	i = i * 64;
	j = j * 64;
	mlx_put_image_to_window(program->mlx, program->win, image, j, i);
}

void	help_put_images(t_program *program, char **map, int i, int j)
{
	if (map[i][j] == '1')
		ft_print_image(program, program->map.wall, i, j);
	if (map[i][j] == '0')
		ft_print_image(program, program->map.ground, i, j);
	if (map[i][j] == 'P')
		ft_print_image(program, program->map.player.image, i, j);
	if (map[i][j] == 'C')
		ft_print_image(program, program->map.collectible.image, i, j);
	if (map[i][j] == 'E')
		ft_print_image(program, program->map.exit.image, i, j);
	if (map[i][j] == 'X')
		ft_print_image(program, program->map.enemy, i, j);
}

void	put_images(t_program *program, char **map)
{
	int		i;
	int		j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] && map[i][j] != '\n')
		{
			help_put_images(program, map, i, j);
			j++;
		}
		i++;
	}
}

void	reset_img(t_program *program)
{
	char	*step;

	if (!program->map.collectible.qtd && program->map.exit.flag++ == 0)
	{
		mlx_destroy_image(program->mlx, program->map.exit.image);
		program->map.exit.image = program->map.exit.image_open;
	}
	step = ft_itoa(program->map.player.steps);
	mlx_clear_window(program->mlx, program->win);
	put_images(program, program->map.map);
	mlx_string_put(program->mlx, program->win, 20, 22, 0x00FFFFFF, step);
	free(step);
}

void	make_window(t_program *program)
{
	program->map.ground = mlx_xpm_file_to_image(program->mlx, GROUND,
			&program->map.width, &program->map.height);
	program->map.wall = mlx_xpm_file_to_image(program->mlx, WALL,
			&program->map.width, &program->map.height);
	program->map.player.image = mlx_xpm_file_to_image(program->mlx, PLAYER,
			&program->map.width, &program->map.height);
	program->map.exit.image = mlx_xpm_file_to_image(program->mlx, EXIT,
			&program->map.width, &program->map.height);
	program->map.collectible.image = mlx_xpm_file_to_image(program->mlx,
			COLLECTIBLE, &program->map.width, &program->map.height);
	program->map.enemy = mlx_xpm_file_to_image(program->mlx, ENEMY,
			&program->map.width, &program->map.height);
	program->map.player.img_d = mlx_xpm_file_to_image(program->mlx, PLAYER_DOWN,
			&program->map.width, &program->map.height);
	program->map.player.img_u = mlx_xpm_file_to_image(program->mlx, PLAYER_UP,
			&program->map.width, &program->map.height);
	program->map.player.img_l = mlx_xpm_file_to_image(program->mlx, PLAYER_LEFT,
			&program->map.width, &program->map.height);
	program->map.player.img_r = mlx_xpm_file_to_image(program->mlx,
			PLAYER_RIGHT, &program->map.width, &program->map.height);
	program->map.exit.image_open = mlx_xpm_file_to_image(program->mlx, EXIT_2,
			&program->map.width, &program->map.height);
	reset_img(program);
	mlx_loop(program->mlx);
}
