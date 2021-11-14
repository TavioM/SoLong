/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocmarout <ocmarout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 19:22:37 by ocmarout          #+#    #+#             */
/*   Updated: 2021/11/12 20:41:32 by ocmarout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

int	color(int alpha, int red, int green, int blue)
{
	return (alpha << 24 | red << 16 | green << 8 | blue);
}

void	set_window_size(char **map, int *x, int *y)
{
	*x = ft_strlen(map[0]);
	*y = 0;
	while (map[*y])
		(*y)++;
	(*x) *= 16;
	(*y) *= 16;
}

void	find_player(char **map, int *x, int *y)
{
	int	i;
	int	j;

	j = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (map[j][i] == 'P')
			{
				*x = i;
				*y = j;
				map[j][i] = '0';
				return ;
			}
			i++;
		}
		j++;
	}
}
