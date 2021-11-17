/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocmarout <ocmarout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 14:07:17 by ocmarout          #+#    #+#             */
/*   Updated: 2021/11/14 19:37:03 by ocmarout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_no_event(void *data)
{
	(void)data;
	return (0);
}

int	handle_keypress(int keysym, t_mlx *mlx)
{
	if (keysym == XK_Escape)
	{
		free_map(mlx->map);
		mlx_destroy_window(mlx->mlx, mlx->win);
		mlx_destroy_image(mlx->mlx, mlx->img.img);
		mlx_destroy_image(mlx->mlx, mlx->brick.img);
		mlx_destroy_image(mlx->mlx, mlx->diamond.img);
		mlx_destroy_image(mlx->mlx, mlx->portal.img);
		mlx_destroy_image(mlx->mlx, mlx->steve.img);
		mlx_destroy_image(mlx->mlx, mlx->black.img);
		mlx_loop_end(mlx->mlx);
	}
	else if (keysym == 97)
		move_left(mlx);
	else if (keysym == 100)
		move_right(mlx);
	else if (keysym == 115)
		move_down(mlx);
	else if (keysym == 119)
		move_up(mlx);
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
