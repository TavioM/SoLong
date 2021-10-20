/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocmarout <ocmarout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 17:12:16 by ocmarout          #+#    #+#             */
/*   Updated: 2021/10/20 19:35:11 by ocmarout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_line(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '0' && str[i] != '1' && str[i] != 'C' && str[i] != 'E'
			&& str[i] != 'P')
		{
			ft_printf("Error\nInvalid character\n");
			return (1);
		}
		i++;
	}
	return (0);
}

static int	check_walls(char **map)
{
	int	i;
	int	last;

	i = 0;
	last = ft_strlen(map[0]) - 1;
	while (map[i])
	{
		if (map[i][0] != '1' || map[i][last] != '1')
			return (1);
		i++;
	}
	last = i - 1;
	i = 0;
	while (map[0][i])
	{
		if (map[0][i] != '1' || map[last][i] != '1')
			return (1);
		i++;
	}
	return (0);
}

static int	check_special(char **map)
{
	int	i;
	int	j;
	int	exit;
	int	player;
	int	collectible;

	j = 0;
	exit = 0;
	player = 0;
	collectible = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (map[j][i] == 'E')
				exit++;
			if (map[j][i] == 'P')
				player++;
			if (map[j][i++] == 'C')
				collectible++;
		}
		j++;
	}
	return (!exit + !player + !collectible);
}

int	check_map(char **map)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(map[0]);
	while (map[i])
	{
		if ((int)ft_strlen(map[i]) != len)
		{
			ft_printf("Error\nMap is not rectangular\n");
			return (1);
		}
		if (check_line(map[i]))
			return (1);
		i++;
	}
	if (check_walls(map))
	{
		ft_printf("Error\nMap is not surrounded by walls\n");
		return (1);
	}
	if (check_special(map))
		return (1);
	return (0);
}
