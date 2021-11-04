/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SoLong.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocmarout <ocmarout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 18:18:47 by ocmarout          #+#    #+#             */
/*   Updated: 2021/11/04 17:38:10 by ocmarout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_sprite(char **map, int x, int y, t_img *img, t_img brick)
{
	int i;
	int j;
	int cursor;

	j = 0;
	cursor = (16 * ft_strlen(map[y]) * 16 * y) + (16 * x);
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

void	draw_map(t_img *img, t_sprites sprites, char **map)
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
				draw_sprite(map, x, y, img, sprites.brick);
			}
			else if (map[y][x] == 'C')
			{
				draw_sprite(map, x, y, img, sprites.diamond);
			}
			else if (map[y][x] == 'E')
			{
				draw_sprite(map, x, y, img, sprites.diamond);
			}
			else if (map[y][x] == 'P')
			{
				cursor = (16 * ft_strlen(map[y]) * 16 * y) + (16 * x);
				j = 0;
				while (j < 16)
				{
					i = 0;
					while (i < 16)
					{
						(img->addr)[cursor + i] = color(0, 0, 64, 128);
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

int	main(int argc, char **argv)
{
	t_mlx		mlx;
	t_img		img;
	t_sprites	sprites;
	int			x;
	int			y;
	char		**map;

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
	sprites.brick.img = mlx_xpm_file_to_image(mlx.mlx, "xpm/brick.xpm", &x, &y);
	sprites.brick.addr = (unsigned int *)mlx_get_data_addr(sprites.brick.img,
			&(sprites.brick.bpp), &(sprites.brick.len), &(sprites.brick.endian));
	sprites.diamond.img = mlx_xpm_file_to_image(mlx.mlx, "xpm/diamond.xpm", &x, &y);
	sprites.diamond.addr = (unsigned int *)mlx_get_data_addr(sprites.diamond.img,
			&(sprites.diamond.bpp), &(sprites.diamond.len), &(sprites.diamond.endian));
	sprites.portal.img = mlx_xpm_file_to_image(mlx.mlx, "xpm/diamond(1).xpm", &x, &y);
	sprites.portal.addr = (unsigned int *)mlx_get_data_addr(sprites.portal.img,
			&(sprites.portal.bpp), &(sprites.portal.len), &(sprites.portal.endian));
	mlx_loop_hook(mlx.mlx, &handle_no_event, &mlx);
	mlx_hook(mlx.win, KeyPress, KeyPressMask, &handle_keypress, &mlx);
	mlx_hook(mlx.win, KeyRelease, KeyReleaseMask, &handle_keyrelease, &mlx);
	draw_map(&img, sprites, map);
	mlx_put_image_to_window(mlx.mlx, mlx.win, img.img, 0, 0);
	mlx_loop(mlx.mlx);
	return (0);
}

//void	*mlx_xpm_file_to_image(void *mlx_ptr, char *filename, int *width, int *height);
