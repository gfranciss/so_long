/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_imagens.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfrancis <gfrancis@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 14:02:34 by gfrancis          #+#    #+#             */
/*   Updated: 2023/07/17 16:27:30 by gfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	print_exit(t_program *program, int i, int j)
{
	i = i * 64;
	j = j * 64;
	mlx_put_image_to_window(program->mlx, program->win, program->map.exit.image, j, i);
	mlx_put_image_to_window(program->mlx, program->win, program->map.exit.image, j, i);
}

void	print_collectible(t_program *program, int i, int j)
{
	i = i * 64;
	j = j * 64;
	mlx_put_image_to_window(program->mlx, program->win, program->map.ground, j, i);
	mlx_put_image_to_window(program->mlx, program->win, program->map.collectible.image, j, i);
}

void	print_player(t_program *program, int i, int j)
{
	i = i * 64;
	j = j * 64;
	mlx_put_image_to_window(program->mlx, program->win, program->map.exit.image, j, i);
	mlx_put_image_to_window(program->mlx, program->win, program->map.player.image, j, i);
}

void	print_wall(t_program *program, int i, int j)
{
	i = i * 64;
	j = j * 64;
	mlx_put_image_to_window(program->mlx, program->win, program->map.wall, j, i);
}

void	print_ground(t_program *program, int i, int j)
{
	i = i * 64;
	j = j * 64;
	mlx_put_image_to_window(program->mlx, program->win, program->map.ground, j, i);
}

void	help_put_images(t_program *program, char **map, int i, int j)
{
	if (map[i][j] == '1')
		print_wall(program, i, j);
	if (map[i][j] == '0')
		print_ground(program, i, j);
	if (map[i][j] == 'P')
		print_player(program, i, j);
	if (map[i][j] == 'C')
		print_collectible(program, i, j);
	if (map[i][j] == 'E')
		print_exit(program, i, j);
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

int	reset_img(char **map, t_program *program)
{
	mlx_clear_window(program->mlx, program->win);
	put_images(program, map);
	return (0);
}

void	make_window(char **map, t_program *program)
{
	(void)map;
	program->map.ground = mlx_xpm_file_to_image(program->mlx, GROUND, &program->map.width, &program->map.height);
	program->map.wall = mlx_xpm_file_to_image(program->mlx, WALL, &program->map.width, &program->map.height);
	program->map.wall = mlx_xpm_file_to_image(program->mlx, PLAYER, &program->map.width, &program->map.height);
	program->map.exit.image = mlx_xpm_file_to_image(program->mlx, EXIT, &program->map.width, &program->map.height);
	program->map.collectible.image = mlx_xpm_file_to_image(program->mlx, COLLECTIBLE, &program->map.width, &program->map.height);
	mlx_hook(program->win, 17, 0, key_hook,(void *)"Did you give up? 😲​​\n");
	//mlx_loop_hook(program->mlx, reset_img, map);
	mlx_loop(program->mlx);
}

