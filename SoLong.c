/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SoLong.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocmarout <ocmarout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 18:18:47 by ocmarout          #+#    #+#             */
/*   Updated: 2021/09/28 22:40:48 by ocmarout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keycode, int tmp)
{
	ft_printf("keycode = %d\n", keycode);
	return (tmp);
}

int	color(int alpha, int red, int green, int blue)
{
	return (alpha << 24 | red << 16 | green << 8 | blue);
}

int	draw_img(t_img *img, int width, int height)
{
	int	i;
	int	j;

	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			if (j == width / 3)
				(img->addr)[(i * width) + j] = color(0, 255, 0, 0);
			else
				(img->addr)[(i * width) + j]
					= color(0, 255, 255, 0);
			j++;
		}
		i++;
	}
	ft_printf("bpp = %d, len = %d, endian %d\n",
		img->bpp, img->len, img->endian);
	return (0);
}

int	main(void)
{
	t_mlx	mlx;
	t_img	img;
	int		x;
	int		y;

	x = 1600;
	y = 800;
	mlx.mlx = mlx_init();
	if (!(mlx.mlx))
		return (1);
	mlx.win = mlx_new_window(mlx.mlx, x, y, "Test");
	if (!(mlx.win))
	{
		free(mlx.mlx);
		return (1);
	}
	img.img = mlx_new_image(mlx.mlx, x, y);
	img.addr = (unsigned int *)mlx_get_data_addr(img.img, &(img.bpp),
			&(img.len), &(img.endian));
	draw_img(&img, x, y);
	mlx_put_image_to_window(mlx.mlx, mlx.win, img.img, 0, 0);
	mlx_key_hook(mlx.win, &key_hook, 0);
	mlx_loop(mlx.mlx);
	return (0);
}
