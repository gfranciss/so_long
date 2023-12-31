/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfrancis <gfrancis@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 11:12:06 by gfrancis          #+#    #+#             */
/*   Updated: 2023/09/01 14:37:19 by gfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/inc/libft.h"
# include "minilibx-linux/mlx.h"

# define PLAYER "./images/mike_first.xpm"
# define PLAYER_RIGHT "./images/mike_right.xpm"
# define PLAYER_LEFT "./images/mike_left.xpm"
# define PLAYER_UP "./images/mike_up.xpm"
# define PLAYER_DOWN "./images/mike_down.xpm"

# define WALL "./images/wall.xpm"
# define EXIT "./images/exit.xpm"
# define EXIT_2 "./images/exit2.xpm"
# define GROUND "./images/ground.xpm"
# define COLLECTIBLE "./images/cilindro_grito.xpm"

# define ENEMY "./images/boo_down.xpm"
# define ENEMY_RIGHT "./images/boo_right.xpm"
# define ENEMY_LEFT "./images/boo_left.xpm"
# define ENEMY_UP "./images/boo_up.xpm"
# define ENEMY_DOWN "./images/boo_down.xpm"

typedef struct s_player
{
	int					x;
	int					y;
	int					qtd;
	int					steps;
	int					flag;
	void				*image;
	void				*img_r;
	void				*img_l;
	void				*img_u;
	void				*img_d;
}							t_player;

typedef struct s_exit
{
	int					qtd;
	void				*image_open;
	void				*image;
	int					flag;
}							t_exit;

typedef struct s_collectible
{
	int					qtd;
	void				*image;
}							t_collectile;

typedef struct s_map
{
	t_player			player;
	void				*wall;
	t_collectile		collectible;
	void				*ground;
	t_exit				exit;
	char				**map;
	char				**map2;
	int					height;
	int					width;
	void				*enemy;
}							t_map;

typedef struct s_program 
{
	void				*mlx;
	void				*win;
	t_map				map;
}							t_program;

/*/______________________________KEYS________________________________/*/
enum e_keys
{
	KEY_ESC		= 65307,
	KEY_A		= 97,
	KEY_S		= 115,
	KEY_D		= 100,
	KEY_W		= 119,
};
int			key_hook(int keycode, t_program *program);
int			x_press(t_program *program);
void		move(t_program *program, int x, int y);
/*/__________________________________________________________________/*/

/*/________________________________DATA______________________________/*/
int			ft_data(char *path, t_program *program);
void		ft_init_screen(t_program *program);
/*/__________________________________________________________________/*/

/*/____________________________ERROR/FREE____________________________/*/
void		ft_error_program(t_program *program, int erro);
int			ft_free_program(t_program *program);
void		ft_error_map(t_program *program, char **map, int erro);
void		ft_free_map(char **map);
void		ft_free_img(t_program *program);
/*/__________________________________________________________________/*/

/*/________________________________MAP_______________________________/*/
void		move_d(t_program *program);
void		check_map_extension(char *map_extension, t_program *program);
void		read_map(char *path, t_program *program);
char		**create_matrix(t_list *list, int i);
void		check_first_last_line(t_program *program, int line, int size);
void		check_map(int line, t_program *program, char **map);
void		check_body(t_program *program, char **map, int x, int y);
/*/__________________________________________________________________/*/

/*/________________________________PATH______________________________/*/
void		flood_fill(int x, int y, int *flag, t_program *program);
int			check_collec(char **map);
int			fill_flood(t_program *program);
/*/__________________________________________________________________/*/

/*/______________________________IMAGENS_____________________________/*/

void		make_window(t_program *program);
void		reset_img(t_program *program);

/*/__________________________________________________________________/*/

int			main(int argc, char **argv);

#endif