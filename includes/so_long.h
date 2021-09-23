/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocmarout <ocmarout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 18:30:34 by ocmarout          #+#    #+#             */
/*   Updated: 2021/09/23 17:29:43 by ocmarout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include <mlx.h>

typedef struct s_img
{
	void			*img;
	unsigned int	*addr;
	int				bpp;
	int				len;
	int				endian;
}				t_img;

#endif
