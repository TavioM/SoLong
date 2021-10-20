/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocmarout <ocmarout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 16:08:38 by ocmarout          #+#    #+#             */
/*   Updated: 2021/10/20 19:30:26 by ocmarout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_filepath(char *filepath)
{
	int		i;
	int		fd;

	if (!filepath)
		return (-1);
	i = ft_strlen(filepath);
	if (i < 4 || filepath[i - 4] != '.' || filepath[i - 3] != 'b'
		|| filepath[i - 2] != 'e' || filepath[i - 1] != 'r')
	{
		ft_printf("Error\nThis is not a \".ber\" extention\n");
		return (-1);
	}
	fd = open(filepath, O_RDONLY);
	return (fd);
}

void	print(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		ft_printf("line %d:%p, ", i, map[i]);
		ft_printf("%s\n", map[i]);
		i++;
	}
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
}

char	**add_line(char **map, char *new)
{
	int		i;
	int		size;
	char	**tmp;

	if (!map)
	{
		tmp = malloc(sizeof(char *) * 2);
		if (!tmp)
			return (0);
		tmp[0] = new;
		tmp[1] = 0;
		return (tmp);
	}
	i = -1;
	size = 0;
	while (map[size])
		size++;
	tmp = malloc(sizeof(char *) * (size + 2));
	if (!tmp)
	{
		free_map(map);
		return (0);
	}
	while (++i < size)
		tmp[i] = map[i];
	tmp[i++] = new;
	tmp[i] = 0;
	free(map);
	return (tmp);
}

char	**map_parsing(char *filepath)
{
	int		i;
	int		j;
	int		fd;
	char	*tmp;
	char	**map;

	i = 1;
	map = 0;
	fd = check_filepath(filepath);
	if (fd == -1)
		return (0);
	j = get_next_line(fd, &tmp);
	while (j == 1)
	{
		map = add_line(map, tmp);
		if (!map)
		{
			return (0);
		}
		j = get_next_line(fd, &tmp);
	}
	ft_printf("test the map\n");
	if (check_map(map))
		return (0);
	print(map);
	return (map);
}
