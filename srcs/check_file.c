#include "../so_long.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return (0);
	while (*s1 && *s2 && *s1 == *s2 && --n)
	{
		if (*s1 != *s2)
			return ((unsigned char)*s1 - (unsigned char)*s2);
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

int	is_valid_file(t_vars *vars)
{
	int	len;

	len = ft_strlen(vars->path);
	if (ft_strncmp(&vars->path[len - 4], ".ber", 4) != 0)
	{
		printf("Error\nInvalid file\n");
		return (-1);
	}
	return (0);
}
