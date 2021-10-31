/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocmarout <ocmarout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 18:30:34 by ocmarout          #+#    #+#             */
/*   Updated: 2021/10/31 18:53:41 by ocmarout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "GNL.h"
# include "sys/types.h"
# include "sys/stat.h"
# include "fcntl.h"
# include <mlx.h>
# include <X11/X.h>
# include <X11/keysym.h>

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
}				t_mlx;

typedef struct s_img
{
	void			*img;
	unsigned int	*addr;
	int				bpp;
	int				len;
	int				endian;
}				t_img;

typedef struct s_sprites
{
	struct s_img	brick;
	struct s_img	diamond;
	struct s_img	steve;
}				t_sprites;

char	**map_parsing(char *filepath);
int		check_map(char **map);
void	print(char **map);
void	free_map(char **map);
int		color(int alpha, int red, int green, int blue);
void	set_window_size(char **map, int *x, int *y);
int		handle_no_event(void *data);
int		handle_keypress(int keysym, t_mlx *mlx);
int		handle_keyrelease(int keysym, void *data);

#endif
