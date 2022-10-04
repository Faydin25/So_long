/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_check_and_read_map.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faydin <42istanbul.com.tr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 10:30:40 by faydin            #+#    #+#             */
/*   Updated: 2022/06/01 10:30:41 by faydin           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_game(t_map *map, int a)
{
	int	i;

	i = 0;
	ft_printf("Error");
	while (map->lines[i++])
		free(map->lines[i]);
	if (a)
	{
		mlx_destroy_image(map->mlx, map->img->collectible);
		mlx_destroy_image(map->mlx, map->img->wall);
		mlx_destroy_image(map->mlx, map->img->player);
		mlx_destroy_image(map->mlx, map->img->exit);
		free(map->img);
	}
	system("leaks so_long");
	free(map->lines);
	free(map);
	exit(0);
}

void	check_other_walls(t_map *map)
{
	int	x;
	int	len_length;
	int	i;

	x = 1;
	i = 0;
	while (map->lines[0][i] != '\0' && map->lines[0][i] != '\n')
		i++;
	len_length = i;
	while (x <= map->heigth - 1)
	{
		if (map->lines[x][0] != '1')
		{
			exit_game(map, 0);
		}
		x++;
	}
	x = 0;
	while (x != map->heigth - 1)
	{
		if (map->lines[x][len_length - 1] != '1')
			exit_game(map, 0);
		x++;
	}
	detect_components(map);
}

void	check_first_last_wall(t_map *map)
{
	int	x;
	int	y;
	int	len;

	x = 0;
	y = 0;
	len = 0;
	while (map->lines[0][x] != '\0')
	{
		if (map->lines[0][x] != '1')
			exit_game(map, 0);
		x++;
	}
	while (y <= map->heigth - 1)
	{
		if (map->lines[map->heigth - 1][y] != '1')
		{
			exit_game(map, 0);
		}
		y++;
	}
	check_other_walls(map);
}

void	count_length_width(t_map *map)
{
	int	i;
	int	line_count;
	int	line_length;

	line_count = 0;
	i = 0;
	while (map->lines[i])
		i++;
	line_count = i;
	i = 0;
	while (map->lines[0][i] != '\n' && map->lines[0][i] != '\0')
		i++;
	line_length = i;
	if (line_length == line_count)
		exit_game(map, 0);
	map->width = line_length;
	map->heigth = line_count;
	check_first_last_wall(map);
}

void	read_map(t_map *map, char *berfile)
{
	int		fd;
	char	*line;
	char	*result;

	check_ber(berfile);
	fd = open(berfile, O_RDONLY);
	if (fd < 0)
		exit(0);
	result = ft_strdup("");
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		result = ft_strjoin(result, line);
		free(line);
	}
	map->lines = ft_split(result, '\n');
	free(result);
	count_length_width(map);
}
