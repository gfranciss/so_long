/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfrancis <gfrancis@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 10:09:48 by gfrancis          #+#    #+#             */
/*   Updated: 2023/09/01 14:08:02 by gfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

char	**create_matrix(t_list *list, int i)
{
	t_list	*tmp;
	char	**mtx;
	int		j;

	j = 0;
	tmp = list;
	mtx = malloc(sizeof(char *) * (i + 1));
	if (!mtx)
		return (0);
	while (tmp != 0)
	{
		mtx[j] = ft_strdup(tmp->content);
		tmp = tmp->next;
		j++;
	}
	mtx[j] = 0;
	return (mtx);
}

void	read_map(char *path, t_program *program)
{
	int				fd;
	int				index;
	t_list			*content;
	char			*line;
	int				size;

	index = 0;
	content = NULL;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		ft_error_program(program, 0);
	line = get_next_line(fd);
	if (!line)
		ft_error_program(program, 2);
	while (line != NULL) 
	{
		ft_lstadd_back(&content, ft_lstnew(line));
		line = get_next_line(fd);
	}
	program->map.map = create_matrix(content, ft_lstsize(content));
	program->map.map2 = create_matrix(content, ft_lstsize(content));
	size = ft_lstsize(content) - 1;
	ft_lstclear(&content, free);
	check_map(size, program, program->map.map2);
	close(fd);
}
