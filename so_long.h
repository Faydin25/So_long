/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faydin <42istanbul.com.tr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 10:31:03 by faydin            #+#    #+#             */
/*   Updated: 2022/06/01 10:31:04 by faydin           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define BUFFER_SIZE 100
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdarg.h>
# include "./mlx/mlx.h"

typedef struct s_img
{
	void	*wall;
	void	*collectible;
	void	*player;
	void	*exit;
}	t_image;

typedef struct s_map
{
	char	**lines;
	char	*map;
	void	*mlx;
	void	*window;
	int		width;
	int		heigth;
	int		player_x;
	int		player_y;
	int		movecount;
	int		collectibles;
	int		exits;
	int		players;
	t_image	*img;
}	t_map;

void	check_ber(char *s);
void	check_materials(t_map *map);
void	exit_game(t_map *map, int img_loaded);
void	imgs(t_map *imgs);
void	count_materials(t_map *map);
void	check_first_last_wall(t_map *map);
void	check_other_walls(t_map *map);
void	check_length_width(t_map *map);
void	read_map(t_map *map, char *berfile);
void	print_components(t_map *map, int x, int y);
void	detect_components(t_map *map);
char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s1);
char	*get_next_line(int fd);
char	*update_buffer(char *buffer);
char	*next_line(char *buffer);
char	*ft_strjoin(char *s1, char *s2);
char	*next_line(char *buffer);
char	*update_buffer(char *buffer);
char	*ft_strchr(const char *s, int c);
int		isnlchar(char *buffer);
int		ft_strlen(char *s);
int		ft_printf(const char *str, ...);
int		ft_putchar_fd(char c, int fd);
int		ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd, int *count);

# define PLAYER "./img/Player.xpm"
# define COLLECT "./img/Collect.xpm"
# define EXIT "./img/Exit.xpm"
# define WALL "./img/Wall.xpm"

#endif
