/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m-alaoui <m-alaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 22:25:28 by m-alaoui          #+#    #+#             */
/*   Updated: 2023/02/26 17:26:43 by m-alaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>
# include "mlx.h"
# include "../get_next_line/get_next_line_bonus.h"

# define SQUARE 32

typedef struct l_st
{
	void	*mlx;
	void	*win;
	void	*img;
	void	*exit;
	void	*empty;
	void	*col;
	void	*wall;
	void	*player;
	void	*enemy;
	int		coins;
	int		start;
	int		end;
	int		x;
	int		y;
	int		width;
	int		height;
	int		count_m;
	char	*count_m_c;
	char	**arr;
	char	*line;
	int		player_position;
	int		j;
	int		i;
}	t_st;

// read map
int		ft_strlen(const char *s);
char	*ft_itoa(int n);
char	*ft_strrchr(const char *s, int c);
void	ft_putstr_fd(char *s, int fd);
int		read_file(char *path);
char	**read_map(char **av);
int		ft_count_colums(char **line);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		check_map_rectangular(char **line);
int		check_wall_map(char **line);
void	complet_move_player(t_st *b, int x, int y);
int		ft_hieght(char **av);	
// chec	 map path if is valid
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*check_path_valid(char *line, int p, int n);
int		check_path(char *line);
char	*double_pointer_to_char(char **line);
int		player_position(char **line);
int		destory(t_st *b);
// check map if is valid
int		check_allowed_char(char **line);
char	**delete_backslash(char **line);
int		check_map_equal(char **line);
int		check_map_valid(char **line);
void	check_heads(char *line);
char	*get_next_line(int fd);
int		check_e_isblocked(char *line, int n);
// draw map
int		read_key(int keycode, t_st *b);
void	read_files(t_st *b);
int		draw_map(char **map, int coins);
void	move_player(t_st *b, int x, int y);
void	drow_player_exit(t_st *b);
void	draw_files(t_st *b);
int		count_collec(char **map);
//logs
void	print_error(t_st *b, char *str);
void	print_simple_error(char *str);
void	free_window(t_st *b);
void	free_map(char **map);
void	ft_putnbr_fd(int nb, int fd);
void	ft_putchar_fd(char c, int fd);
void	check_line_backslach(char *line);
void	draw_score(t_st *b);

#endif