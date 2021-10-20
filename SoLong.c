/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SoLong.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocmarout <ocmarout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 18:18:47 by ocmarout          #+#    #+#             */
/*   Updated: 2021/10/20 16:35:32 by ocmarout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keycode, int tmp)
{
	ft_printf("keycode = %d\n", keycode);
	return (tmp);
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
	printf("Keypress: %d\n", keysym);
	return (0);
}

int	handle_keyrelease(int keysym, void *data)
{
	(void)data;
	printf("Keyrelease: %d\n", keysym);
	return (0);
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

//void	*mlx_xpm_file_to_image(void *mlx_ptr, char *filename, int *width, int *height);

int	main(int argc, char **argv)
{
	t_mlx	mlx;
	t_img	img;
	t_img	brick;
	int		x;
	int		y;
	char	**map;

	if (argc != 2)
	{
		ft_printf("Error\nExpected 2 arguments, got %d\n", argc);
		return (1);
	}
	x = 1600;
	y = 800;
	map = map_parsing(argv[1]);
	if (!map)
		return (-1);
	ft_printf("Got a map\n");
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
	mlx_loop_hook(mlx.mlx, &handle_no_event, &mlx);
	mlx_hook(mlx.win, KeyPress, KeyPressMask, &handle_keypress, &mlx);
	mlx_hook(mlx.win, KeyRelease, KeyReleaseMask, &handle_keyrelease, &mlx);
	draw_img(&img, x, y);
	mlx_put_image_to_window(mlx.mlx, mlx.win, img.img, 0, 0);
	brick.img = mlx_xpm_file_to_image(mlx.mlx, "xpm/minecraft_brick.xpm", &x, &y);
	mlx_put_image_to_window(mlx.mlx, mlx.win, brick.img, 50, 50);
	mlx_put_image_to_window(mlx.mlx, mlx.win, brick.img, 66, 50);
	mlx_put_image_to_window(mlx.mlx, mlx.win, brick.img, 150, 150);
	mlx_key_hook(mlx.win, &key_hook, 0);
	mlx_loop(mlx.mlx);
	return (0);
}
