/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faydin <42istanbul.com.tr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 10:30:21 by faydin            #+#    #+#             */
/*   Updated: 2022/06/01 10:30:23 by faydin           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"
#include <stdio.h>
#include "so_long.h"

void	put_image(t_map *map, void *item, int x, int y)
{
	mlx_put_image_to_window(map->mlx, map->window, item, x * 64, y * 64);
}

void	count_metarials(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->heigth)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->lines[y][x] == 'C')
				map->collectibles += 1;
			else if (map->lines[y][x] == 'E')
				map->exits += 1;
			else if (map->lines[y][x] == 'P')
			{
				map->players += 1;
				map->player_x = x;
				map->player_y = y;
			}
			x++;
		}
		y++;
	}
	check_materials(map);
}

void	detect_components(t_map *map)
{
	int	y;
	int	x;

	y = 0;
	while (y < map->heigth)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->lines[y][x] == 'C')
				map->collectibles += 1;
			else if (map->lines[y][x] == 'E')
				map->exits += 1;
			else if (map->lines[y][x] == 'P')
			{
				map->players += 1;
				map->player_x = x;
				map->player_y = y;
			}
			x++;
		}
		y++;
	}
	check_materials(map);
}

void	imgs(t_map *imgs)
{
	int	w;
	int	h;

	imgs->img = malloc(sizeof(t_image));
	imgs->img->wall = mlx_xpm_file_to_image(imgs->mlx, WALL, &w, &h);
	imgs->img->player = mlx_xpm_file_to_image(imgs->mlx, PLAYER, &w, &h);
	imgs->img->collectible = mlx_xpm_file_to_image(imgs->mlx, COLLECT, &w, &h);
	imgs->img->exit = mlx_xpm_file_to_image(imgs->mlx, EXIT, &w, &h);
}

void	print_components(t_map *map, int x, int y)
{
	if (map->movecount > 0)
		ft_printf("%d\n", map->movecount);
	while (y < map->heigth)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->lines[y][x] == '1')
				put_image(map, map->img->wall, x, y);
			else if (map->lines[y][x] == 'P')
				put_image(map, map->img->player, x, y);
			else if (map->lines[y][x] == 'C')
				put_image(map, map->img->collectible, x, y);
			else if (map->lines[y][x] == 'E')
				put_image(map, map->img->exit, x, y);
			else if (map->lines[y][x] == '0')
				;
			else
				exit_game(map, 1);
			x++;
		}
		y++;
	}
	map->movecount++;
}
