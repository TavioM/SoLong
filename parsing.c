/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocmarout <ocmarout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 16:08:38 by ocmarout          #+#    #+#             */
/*   Updated: 2021/10/19 15:33:43 by ocmarout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int		check_filepath(char *filepath)
{
	int		i;
	int		fd;

	if (!filepath)
		return (-1);
	i = ft_strlen(filepath);
	if (i < 4 || filepath[i - 4] != '.' || filepath[i - 3] != 'b'
		|| filepath[i - 2] != 'e' || filepath[i - 1] != 'r')
	{
		ft_printf("Error\nThis is not a \".ber\" extention\n");
		return (0);
	}
	fd = open(filepath, O_RDONLY);
	ft_printf("fd = %d", fd);
	return (-1);
}

char	**parsing(char *filepath)
{
//	int		i;
	int		fd;
	char	**map;

	fd = check_filepath(filepath);
	if (fd == -1)
		return (0);
	map = malloc(sizeof(char *) * 3);
	if (!map)
	{
		close(fd);
		return (0);
	}
	return (0);
}
