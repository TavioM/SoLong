/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocmarout <ocmarout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 18:40:21 by ocmarout          #+#    #+#             */
/*   Updated: 2021/11/12 22:05:07 by ocmarout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_counter(void)
{
	static int	counter = 0;

	counter++;
	if (counter > 1)
		ft_printf("Made %d moves so far\n", counter);
	else
		ft_printf("Made 1 move so far\n");
}

void	move_up(t_mlx *mlx)
{
	if (mlx->map[mlx->y - 1][mlx->x] == '1')
		printf("can't move in a wall\n");
	else
	{
		if (mlx->map[mlx->y][mlx->x] == 'E')
			draw_sprite(mlx, mlx->x, mlx->y, mlx->portal);
		else
			draw_sprite(mlx, mlx->x, mlx->y, mlx->black);
		(mlx->y)--;
		draw_sprite(mlx, mlx->x, mlx->y, mlx->steve);
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.img, 0, 0);
		move_counter();
		collectibles(mlx);
	}
}

void	move_down(t_mlx *mlx)
{
	if (mlx->map[mlx->y + 1][mlx->x] == '1')
		printf("can't move in a wall\n");
	else
	{
		if (mlx->map[mlx->y][mlx->x] == 'E')
			draw_sprite(mlx, mlx->x, mlx->y, mlx->portal);
		else
			draw_sprite(mlx, mlx->x, mlx->y, mlx->black);
		(mlx->y)++;
		draw_sprite(mlx, mlx->x, mlx->y, mlx->steve);
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.img, 0, 0);
		move_counter();
		collectibles(mlx);
	}
}

void	move_left(t_mlx *mlx)
{
	if (mlx->map[mlx->y][mlx->x - 1] == '1')
		printf("can't move in a wall\n");
	else
	{
		if (mlx->map[mlx->y][mlx->x] == 'E')
			draw_sprite(mlx, mlx->x, mlx->y, mlx->portal);
		else
			draw_sprite(mlx, mlx->x, mlx->y, mlx->black);
		(mlx->x)--;
		draw_sprite(mlx, mlx->x, mlx->y, mlx->steve);
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.img, 0, 0);
		move_counter();
		collectibles(mlx);
	}
}

void	move_right(t_mlx *mlx)
{
	if (mlx->map[mlx->y][mlx->x + 1] == '1')
		printf("can't move in a wall\n");
	else
	{
		if (mlx->map[mlx->y][mlx->x] == 'E')
			draw_sprite(mlx, mlx->x, mlx->y, mlx->portal);
		else
			draw_sprite(mlx, mlx->x, mlx->y, mlx->black);
		(mlx->x)++;
		draw_sprite(mlx, mlx->x, mlx->y, mlx->steve);
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.img, 0, 0);
		move_counter();
		collectibles(mlx);
	}
}
