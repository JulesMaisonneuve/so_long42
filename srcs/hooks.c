#include "../so_long.h"

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == ESC)
	{
		printf("You quit the game\n");
		close_win(vars);
	}
	if (keycode == 'a' || keycode == 's' || keycode == 'q' || keycode == 'd')
	{
		mlx_clear_window(vars->mlx, vars->win);
		if (keycode == 'a')
			player_move_up(vars);
		else if (keycode == 's')
			player_move_down(vars);
		else if (keycode == 'q')
			player_move_left(vars);
		else if (keycode == 'd')
			player_move_right(vars);
		put_comps(vars);
	}
	return (0);
}
