/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocmarout <ocmarout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 18:40:21 by ocmarout          #+#    #+#             */
/*   Updated: 2021/11/10 18:46:06 by ocmarout         ###   ########.fr       */
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
	return (counter);
}

int	move_up(t_mlx *mlx)
{
	if (mlx->map[mlx->y - 1][mlx->x] == '1')
		printf("can't move in a wall\n");
	else
	{
		draw_sprite(mlx->map, mlx->x, mlx->y, &(mlx->img), mlx->black);
		(mlx->y)--;
		draw_sprite(mlx->map, mlx->x, mlx->y, &(mlx->img), mlx->steve);
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.img, 0, 0);
		move_counter();
	}
	return (0);
}

int	move_down(t_mlx *mlx)
{
	if (mlx->map[mlx->y + 1][mlx->x] == '1')
		printf("can't move in a wall\n");
	else
	{
		draw_sprite(mlx->map, mlx->x, mlx->y, &(mlx->img), mlx->black);
		(mlx->y)++;
		draw_sprite(mlx->map, mlx->x, mlx->y, &(mlx->img), mlx->steve);
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.img, 0, 0);
		move_counter();
	}
	return (0);
}

int	move_left(t_mlx *mlx)
{
	if (mlx->map[mlx->y][mlx->x - 1] == '1')
		printf("can't move in a wall\n");
	else
	{
		draw_sprite(mlx->map, mlx->x, mlx->y, &(mlx->img), mlx->black);
		(mlx->x)--;
		draw_sprite(mlx->map, mlx->x, mlx->y, &(mlx->img), mlx->steve);
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.img, 0, 0);
		move_counter();
	}
	return (0);
}

int	move_right(t_mlx *mlx)
{
	if (mlx->map[mlx->y][mlx->x + 1] == '1')	
		printf("can't move in a wall\n");
	else
	{
		draw_sprite(mlx->map, mlx->x, mlx->y, &(mlx->img), mlx->black);
		(mlx->x)++;
		draw_sprite(mlx->map, mlx->x, mlx->y, &(mlx->img), mlx->steve);
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.img, 0, 0);
		move_counter();
	}
	return (0);
}
