/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectibles.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocmarout <ocmarout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 19:56:30 by ocmarout          #+#    #+#             */
/*   Updated: 2021/11/17 15:11:36 by ocmarout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	count_collectibles(t_mlx *mlx)
{
	int	i;
	int	j;

	(mlx->collectibles) = 0;
	j = 0;
	while (mlx->map[j])
	{
		i = 0;
		while (mlx->map[j][i])
		{
			if (mlx->map[j][i] == 'C')
				(mlx->collectibles)++;
			i++;
		}
		j++;
	}
}

void	collectibles(t_mlx *mlx)
{
	if (mlx->map[mlx->y][mlx->x] == 'C')
	{
		mlx->map[mlx->y][mlx->x] = '0';
		(mlx->collectibles)--;
	}
	if (mlx->map[mlx->y][mlx->x] == 'E')
		if (mlx->collectibles == 0)
			mlx_loop_end(mlx->mlx);
}
