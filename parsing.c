/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocmarout <ocmarout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 16:08:38 by ocmarout          #+#    #+#             */
/*   Updated: 2021/10/19 17:44:45 by ocmarout         ###   ########.fr       */
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
		return (0);
	}
	fd = open(filepath, O_RDONLY);
	return (fd);
}

static void	add_line_to_map(char ***map, int size)
{
	int		i;
	char	**tmp;

	tmp = malloc(sizeof(char *) * size);
	if (!tmp)
		return ()
}

char	**parsing(char *filepath)
{
	int		i;
	int		j;
	int		fd;
	char	**map;

	fd = check_filepath(filepath);
	if (fd == -1)
		return (0);
	map = malloc(sizeof(char *));
	if (!map)
	{
		ft_printf("Error\nmalloc failed\n");
		close(fd);
		return (0);
	}
	i = 0;
	j = get_next_line(fd, &(map[i++]));
	while (j == 1)
	{
		if (add_line_to_map(&map, i))
		{
			ft_printf("Error\nFailed malloc\n")
			return (0);
		}
		j = get_next_line(fd, &(map[i++]));
	}
	return (0);
}
