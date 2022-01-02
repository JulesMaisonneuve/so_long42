#include "../so_long.h"

int	minimize_window(t_vars *vars)
{
	put_comps(vars);
	return (0);
}

int	init_window(t_vars *vars)
{
	vars->mlx = mlx_init();
	if (!vars->mlx)
		return (free_map(vars));
	vars->win = mlx_new_window(vars->mlx, vars->map_width * 64,
			vars->map_height * 64, "so_long");
	if (!vars->win)
		return (free_map(vars));
	if (init_comp(vars) == -1)
		return (free_map(vars));
	put_comps(vars);
	mlx_key_hook(vars->win, key_hook, vars);
	mlx_hook(vars->win, 33, 1L << 17, close_win, vars);
	mlx_hook(vars->win, 12, 1L << 15, minimize_window, vars);
	mlx_loop(vars->mlx);
	return (0);
}

int	close_win(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->wall);
	mlx_destroy_image(vars->mlx, vars->mario);
	mlx_destroy_image(vars->mlx, vars->exit);
	mlx_destroy_image(vars->mlx, vars->collectible);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	mlx_loop_end(vars->mlx);
	free(vars->mlx);
	free_map(vars);
	exit(0);
	return (0);
}
