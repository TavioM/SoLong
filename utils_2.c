/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocmarout <ocmarout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 17:19:16 by ocmarout          #+#    #+#             */
/*   Updated: 2021/11/17 17:27:34 by ocmarout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	destroy_mlx(t_mlx *mlx)
{
	free_map(mlx->map);
	mlx_destroy_window(mlx->mlx, mlx->win);
	mlx_destroy_image(mlx->mlx, mlx->img.img);
	mlx_destroy_image(mlx->mlx, mlx->brick.img);
	mlx_destroy_image(mlx->mlx, mlx->diamond.img);
	mlx_destroy_image(mlx->mlx, mlx->portal.img);
	mlx_destroy_image(mlx->mlx, mlx->steve.img);
	mlx_destroy_image(mlx->mlx, mlx->black.img);
}
