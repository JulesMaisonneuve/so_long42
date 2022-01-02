#ifndef SO_LONG_H
# define SO_LONG_H

# define ESC 0xff1b

# include "./mlx_linux/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "./getnl/get_next_line.h"

typedef struct s_vars {
	void	*mlx;
	void	*win;
	void	*mario;
	void	*wall;
	void	*collectible;
	void	*exit;
	int		fd;
	char	*path;
	char	c;
	int		x;
	int		y;
	int		actual_col_count;
	int		player;
	int		exits;
	int		player_x;
	int		player_y;
	int		map_height;
	int		map_width;
	int		nb_moves;
	int		collectible_count;
	int		collectible_picked;
	char	**map;

}				t_vars;

typedef struct s_errors {
	int	error1;
	int	error2;
	int	error3;
	int	error4;
	int	error5;
}				t_errors;

typedef struct s_img {
	int		wall_height;
	int		wall_width;
	char	*wall_path;
	int		mario_height;
	int		mario_width;
	char	*mario_path;
	int		collectible_height;
	int		collectible_width;
	char	*collectible_path;
	int		exit_height;
	int		exit_width;
	char	*exit_path;
}				t_img;

int		close_win(t_vars *vars);
int		player_move_up(t_vars *vars);
int		player_move_down(t_vars *vars);
int		player_move_left(t_vars *vars);
int		player_move_right(t_vars *vars);
int		init_comp(t_vars *vars);
void	put_comps(t_vars *vars);
int		ft_strchrr(const char *str, int c);
void	is_valid_map(int fd, t_vars *vars, t_errors *errors);
int		check_error(t_vars *vars, t_errors *errors);
int		print_error(t_errors *errors, t_vars *vars);
int		free_map(t_vars *vars);
int		is_valid_file(t_vars *vars);
int		key_hook(int keycode, t_vars *vars);
int		minimize_window(t_vars *vars);
int		init_window(t_vars *vars);

#endif