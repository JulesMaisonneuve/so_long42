#include "../so_long.h"

int	init_comp(t_vars *vars)
{
	t_img	img;

	img.wall_path = "./img/bricksx34.xpm";
	img.mario_path = "./img/mario64px.xpm";
	img.collectible_path = "./img/goldcoin64px.xpm";
	img.exit_path = "./img/exit.xpm";
	vars->wall = mlx_xpm_file_to_image(vars->mlx, img.wall_path,
			&img.wall_width, &img.wall_height);
	if (!vars->wall)
		return (-1);
	vars->mario = mlx_xpm_file_to_image(vars->mlx, img.mario_path,
			&img.mario_width, &img.mario_height);
	if (!vars->mario)
		return (-1);
	vars->exit = mlx_xpm_file_to_image(vars->mlx, img.exit_path,
			&img.exit_width, &img.exit_height);
	if (!vars->exit)
		return (-1);
	vars->collectible = mlx_xpm_file_to_image(vars->mlx, img.collectible_path,
			&img.collectible_width, &img.collectible_height);
	if (!vars->collectible)
		return (-1);
	return (0);
}

void	put_comps(t_vars *vars)
{
	vars->y = -1;
	while (++vars->y < vars->map_height)
	{
		vars->x = 0;
		while (vars->map[vars->y][vars->x] != '\0')
		{
			if (vars->map[vars->y][vars->x] == '1')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->wall,
					vars->x * 64, vars->y * 64);
			else if (vars->map[vars->y][vars->x] == 'P')
			{
				mlx_put_image_to_window(vars->mlx, vars->win,
					vars->mario, vars->x * 64, vars->y * 64);
				vars->player_x = vars->x;
				vars->player_y = vars->y;
			}
			else if (vars->map[vars->y][vars->x] == 'C')
				mlx_put_image_to_window(vars->mlx, vars->win,
					vars->collectible, vars->x * 64, vars->y * 64);
			else if (vars->map[vars->y][vars->x] == 'E')
				mlx_put_image_to_window(vars->mlx, vars->win,
					vars->exit, vars->x * 64, vars->y * 64);
			vars->x++;
		}
	}
}
