/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfrancis <gfrancis@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 10:09:48 by gfrancis          #+#    #+#             */
/*   Updated: 2023/07/06 14:58:20 by gfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	check_map_extension(char *map_extension, s_program *program)
{
	int	i;

	i = ft_strlen(map_extension);
	if (i > 2 && map_extension[i - 4] == '.' && map_extension[i - 3] == 'b'&& map_extension[i - 2] == 'e' && map_extension[i - 1] == 'r');
	else
	ft_error(program, 1);
}

char **read_map(char *path, s_program *program)
{
	int				fd;
	int				index;
	char			**map;
	t_list			*content;
	char 			*line;
	
	index = 0;
	content = NULL;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		ft_error(program, 0);
	while ((line = get_next_line(fd)) != NULL)
	{
    	ft_lstadd_back(&content, ft_lstnew(line));
    	index++;
	}
	map = create_matrix(content, index);
	index = 0;
	ft_lstclear(&content, 0);
	close(fd);
	return (map);
}
