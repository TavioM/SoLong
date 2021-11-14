/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SoLong.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocmarout <ocmarout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 18:18:47 by ocmarout          #+#    #+#             */
/*   Updated: 2021/11/12 21:32:16 by ocmarout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_sprite(t_mlx *mlx, int x, int y, t_img sprite)
{
	int	i;
	int	j;
	int	cursor;

	j = 0;
	cursor = (16 * ft_strlen(mlx->map[y]) * 16 * y) + (16 * x);
	while (j < 16)
	{
		i = 0;
		while (i < 16)
		{
			(mlx->img.addr)[cursor + i] = (sprite.addr)[16 * j + i];
			i++;
		}
		j++;
		cursor += 16 * ft_strlen(mlx->map[y]);
	}
}

void	draw_map(t_mlx *mlx)
{
	int	x;
	int	y;

	y = 0;
	while (mlx->map[y])
	{
		x = 0;
		while (mlx->map[y][x])
		{
			if (mlx->map[y][x] == '1')
				draw_sprite(mlx, x, y, mlx->brick);
			else if (mlx->map[y][x] == 'C')
				draw_sprite(mlx, x, y, mlx->diamond);
			else if (mlx->map[y][x] == 'E')
				draw_sprite(mlx, x, y, mlx->diamond);
			else if (mlx->map[y][x] == 'P')
				draw_sprite(mlx, x, y, mlx->steve);
			x++;
		}
		y++;
	}
}

void	setup(t_mlx *mlx)
{
	mlx->img.img = mlx_new_image(mlx->mlx, mlx->x, mlx->y);
	mlx->img.addr = (unsigned int *)mlx_get_data_addr(mlx->img.img,
			&(mlx->img.bpp), &(mlx->img.len), &(mlx->img.endian));
	mlx->brick.img = mlx_xpm_file_to_image(mlx->mlx, "xpm/brick.xpm",
			&(mlx->x), &(mlx->y));
	mlx->brick.addr = (unsigned int *)mlx_get_data_addr(mlx->brick.img,
			&(mlx->brick.bpp), &(mlx->brick.len), &(mlx->brick.endian));
	mlx->diamond.img = mlx_xpm_file_to_image(mlx->mlx, "xpm/diamond.xpm",
			&(mlx->x), &(mlx->y));
	mlx->diamond.addr = (unsigned int *)mlx_get_data_addr(mlx->diamond.img,
			&(mlx->diamond.bpp), &(mlx->diamond.len), &(mlx->diamond.endian));
	mlx->portal.img = mlx_xpm_file_to_image(mlx->mlx, "xpm/diamond(1).xpm",
			&(mlx->x), &(mlx->y));
	mlx->portal.addr = (unsigned int *)mlx_get_data_addr(mlx->portal.img,
			&(mlx->portal.bpp), &(mlx->portal.len), &(mlx->portal.endian));
	mlx->steve.img = mlx_xpm_file_to_image(mlx->mlx, "xpm/steve.xpm",
			&(mlx->x), &(mlx->y));
	mlx->steve.addr = (unsigned int *)mlx_get_data_addr(mlx->steve.img,
			&(mlx->steve.bpp), &(mlx->steve.len), &(mlx->steve.endian));
	mlx->black.img = mlx_xpm_file_to_image(mlx->mlx, "xpm/void.xpm",
			&(mlx->x), &(mlx->y));
	mlx->black.addr = (unsigned int *)mlx_get_data_addr(mlx->black.img,
			&(mlx->black.bpp), &(mlx->black.len), &(mlx->black.endian));
	count_collectibles(mlx);
}

int	main(int argc, char **argv)
{
	t_mlx		mlx;

	if (argc != 2)
	{
		ft_printf("Error\nExpected 2 arguments, got %d\n", argc);
		return (1);
	}
	mlx.map = map_parsing(argv[1]);
	if (!(mlx.map))
		return (-1);
	set_window_size(mlx.map, &(mlx.x), &(mlx.y));
	mlx.mlx = mlx_init();
	if (!(mlx.mlx))
		return (1);
	mlx.win = mlx_new_window(mlx.mlx, mlx.x, mlx.y, argv[1]);
	if (!(mlx.win))
	{
		free(mlx.mlx);
		return (1);
	}
	setup(&mlx);
	mlx_loop_hook(mlx.mlx, &handle_no_event, &mlx);
	mlx_hook(mlx.win, KeyPress, KeyPressMask, &handle_keypress, &mlx);
	mlx_hook(mlx.win, KeyRelease, KeyReleaseMask, &handle_keyrelease, &mlx);
	draw_map(&mlx);
	find_player(mlx.map, &(mlx.x), &(mlx.y));
	mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.img.img, 0, 0);
	mlx_loop(mlx.mlx);
	return (0);
}
