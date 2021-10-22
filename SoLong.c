/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SoLong.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocmarout <ocmarout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 18:18:47 by ocmarout          #+#    #+#             */
/*   Updated: 2021/10/22 15:41:57 by ocmarout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keycode, int tmp)
{
	ft_printf("keycode = %d\n", keycode);
	return (tmp);
}

void	draw_map(t_img *img, t_img brick, char **map)
{
	int	x;
	int	y;
	int	i;
	int	j;
	int	cursor;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == '1')
			{
				cursor = (16 * ft_strlen(map[y]) * 16 * y) + (16 * x);
				j = 0;
				while (j < 16)
				{
					i = 0;
					while (i < 16)
					{
						(img->addr)[cursor + i] = (brick.addr)[16 * j + i];
						i++;
					}
					j++;
					cursor += 16 * ft_strlen(map[y]);
				}
			}
			x++;
		}
		y++;
	}
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
	map = map_parsing(argv[1]);
	if (!map)
		return (-1);
	set_window_size(map, &x, &y);
	mlx.mlx = mlx_init();
	if (!(mlx.mlx))
		return (1);
	mlx.win = mlx_new_window(mlx.mlx, x, y, argv[1]);
	if (!(mlx.win))
	{
		free(mlx.mlx);
		return (1);
	}
	img.img = mlx_new_image(mlx.mlx, x, y);
	img.addr = (unsigned int *)mlx_get_data_addr(img.img, &(img.bpp),
			&(img.len), &(img.endian));
	brick.img = mlx_xpm_file_to_image(mlx.mlx, "xpm/minecraft_brick.xpm", &x, &y);
	brick.addr = (unsigned int *)mlx_get_data_addr(brick.img, &(brick.bpp),
			&(brick.len), &(brick.endian));
	mlx_loop_hook(mlx.mlx, &handle_no_event, &mlx);
	mlx_hook(mlx.win, KeyPress, KeyPressMask, &handle_keypress, &mlx);
	mlx_hook(mlx.win, KeyRelease, KeyReleaseMask, &handle_keyrelease, &mlx);
	draw_map(&img, brick, map);
	mlx_put_image_to_window(mlx.mlx, mlx.win, img.img, 0, 0);
	mlx_key_hook(mlx.win, &key_hook, 0);
	mlx_loop(mlx.mlx);
	return (0);
}
