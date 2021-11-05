/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocmarout <ocmarout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 14:07:17 by ocmarout          #+#    #+#             */
/*   Updated: 2021/11/05 18:35:40 by ocmarout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
		printf("Moved RIGHT\n");
	}
	return (0);
}

int	handle_no_event(void *data)
{
	(void)data;
	return (0);
}

int	handle_keypress(int keysym, t_mlx *mlx)
{
	if (keysym == XK_Escape)
		mlx_destroy_window(mlx->mlx, mlx->win);
	else if (keysym == 97)
		printf("Move LEFT\n");
	else if (keysym == 100)
		move_right(mlx);
	else if (keysym == 115)
		printf("Move DOWN\n");
	else if (keysym == 119)
		printf("Move UP\n");
	else
		printf("Keypress: %d\n", keysym);
	return (0);
}

int	handle_keyrelease(int keysym, void *data)
{
	(void)keysym;
	(void)data;
	return (0);
}
