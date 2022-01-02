#include "../so_long.h"

int	player_move_left(t_vars *vars)
{
	if (vars->map[vars->player_y][vars->player_x - 1] == '0'
		|| vars->map[vars->player_y][vars->player_x - 1] == 'C')
	{
		if (vars->map[vars->player_y][vars->player_x - 1] == 'C')
			vars->collectible_picked++;
		vars->map[vars->player_y][vars->player_x - 1] = 'P';
		vars->map[vars->player_y][vars->player_x] = '0';
		vars->nb_moves++;
		printf("Moves: %d\n", vars->nb_moves);
	}
	else if (vars->map[vars->player_y][vars->player_x - 1] == 'E')
	{
		if (vars->collectible_picked != vars->collectible_count)
			printf("You need to pick up all the collectibles\n");
		else
		{
			vars->map[vars->player_y][vars->player_x - 1] = 'P';
			vars->map[vars->player_y][vars->player_x] = '0';
			vars->nb_moves++;
			printf("Moves: %d\n", vars->nb_moves);
			printf("You win the game\n");
			close_win(vars);
		}
	}
	return (0);
}

int	player_move_right(t_vars *vars)
{
	if (vars->map[vars->player_y][vars->player_x + 1] == '0'
		|| vars->map[vars->player_y][vars->player_x + 1] == 'C')
	{
		if (vars->map[vars->player_y][vars->player_x + 1] == 'C')
			vars->collectible_picked++;
		vars->map[vars->player_y][vars->player_x + 1] = 'P';
		vars->map[vars->player_y][vars->player_x] = '0';
		vars->nb_moves++;
		printf("Moves: %d\n", vars->nb_moves);
	}
	else if (vars->map[vars->player_y][vars->player_x + 1] == 'E')
	{
		if (vars->collectible_picked != vars->collectible_count)
			printf("You need to pick up all the collectibles\n");
		else
		{
			vars->map[vars->player_y][vars->player_x + 1] = 'P';
			vars->map[vars->player_y][vars->player_x] = '0';
			vars->nb_moves++;
			printf("Moves: %d\n", vars->nb_moves);
			printf("You win the game\n");
			close_win(vars);
		}
	}
	return (0);
}

int	player_move_up(t_vars *vars)
{
	if (vars->map[vars->player_y - 1][vars->player_x] == '0'
		|| vars->map[vars->player_y - 1][vars->player_x] == 'C')
	{
		if (vars->map[vars->player_y - 1][vars->player_x] == 'C')
			vars->collectible_picked++;
		vars->map[vars->player_y - 1][vars->player_x] = 'P';
		vars->map[vars->player_y][vars->player_x] = '0';
		vars->nb_moves++;
		printf("Moves: %d\n", vars->nb_moves);
	}
	else if (vars->map[vars->player_y - 1][vars->player_x] == 'E')
	{
		if (vars->collectible_picked != vars->collectible_count)
			printf("You need to pick up all the collectibles\n");
		else
		{
			vars->map[vars->player_y - 1][vars->player_x] = 'P';
			vars->map[vars->player_y][vars->player_x] = '0';
			vars->nb_moves++;
			printf("Moves: %d\n", vars->nb_moves);
			printf("You win the game\n");
			close_win(vars);
		}
	}
	return (0);
}

int	player_move_down(t_vars *vars)
{
	if (vars->map[vars->player_y + 1][vars->player_x] == '0'
		|| vars->map[vars->player_y + 1][vars->player_x] == 'C')
	{
		if (vars->map[vars->player_y + 1][vars->player_x] == 'C')
			vars->collectible_picked++;
		vars->map[vars->player_y + 1][vars->player_x] = 'P';
		vars->map[vars->player_y][vars->player_x] = '0';
		vars->nb_moves++;
		printf("Moves: %d\n", vars->nb_moves);
	}
	else if (vars->map[vars->player_y + 1][vars->player_x] == 'E')
	{
		if (vars->collectible_picked != vars->collectible_count)
			printf("You need to pick up all the collectibles\n");
		else
		{
			vars->map[vars->player_y + 1][vars->player_x] = 'P';
			vars->map[vars->player_y][vars->player_x] = '0';
			vars->nb_moves++;
			printf("Moves: %d\n", vars->nb_moves);
			printf("You win the game\n");
			close_win(vars);
		}
	}
	return (0);
}
