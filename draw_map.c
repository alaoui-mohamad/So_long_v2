#include "so_long.h"

void move_player(t_st *b, int x, int y)
{
    int i = 0;
    int j = 0;
    while (b->arr[i])
    {
        while (b->arr[i][j])
        {
            if (b->arr[i][j] == 'P')
            {
                if (b->arr[i + y][j + x] == 'E' && b->coins == 0)
                {
                    ft_putstr_fd("You win!", 1);
                    exit(0);
                }
                if (b->arr[i + y][j + x] == '1' || b->arr[i + y][j + x] == 'E')
                    return;
                if (b->arr[i + y][j + x] == 'C')
                    b->coins--;
                b->arr[i][j] = '0';
                b->arr[i + y][j + x] = 'P';
                return;
            }
            j++;
        }
        j = 0;
        i++;
    }
}
int read_key(int keycode, t_st *b)
{
    int i = 0;

    if (keycode == 53)
        exit(0);
    if (keycode == 0)
        move_player(b, -1, 0);
    if (keycode == 13)
        move_player(b, 0, -1);
    if (keycode == 2)
        move_player(b, 1, 0);
    if (keycode == 1)
        move_player(b, 0, 1);
    mlx_clear_window(b->mlx, b->win);
    draw_files(b);
    return (0);
}
void read_files(t_st *b)
{
    b->exit = mlx_xpm_file_to_image(b->mlx, "assets/exit.xpm", &b->width, &b->height);
    b->empty = mlx_xpm_file_to_image(b->mlx, "assets/empty.xpm", &b->width, &b->height);
    b->col = mlx_xpm_file_to_image(b->mlx, "assets/col.xpm", &b->width, &b->height);
    b->wall = mlx_xpm_file_to_image(b->mlx, "assets/wall.xpm", &b->width, &b->height);
    b->player = mlx_xpm_file_to_image(b->mlx, "assets/player.xpm", &b->width, &b->height);
}
void drow_player_exit(t_st *b)
{
    if (b->arr[b->i][b->j] == 'E')
    {
        mlx_put_image_to_window(b->mlx, b->win, b->empty, SQUARE_SIZE * b->j, SQUARE_SIZE * b->i);
        mlx_put_image_to_window(b->mlx, b->win, b->exit, SQUARE_SIZE * b->j, SQUARE_SIZE * b->i);
    }
    if (b->arr[b->i][b->j] == 'P')
    {
        mlx_put_image_to_window(b->mlx, b->win, b->empty, SQUARE_SIZE * b->j, SQUARE_SIZE * b->i);
        mlx_put_image_to_window(b->mlx, b->win, b->player, SQUARE_SIZE * b->j, SQUARE_SIZE * b->i);
    }
}

void draw_files(t_st *b)
{
    b->i = 0;
    while (b->i < b->y)
    {
        b->j = 0;
        while (b->j < b->x)
        {
            if (b->arr[b->i][b->j] == '1')
                mlx_put_image_to_window(b->mlx, b->win, b->wall, SQUARE_SIZE * b->j, SQUARE_SIZE * b->i);
            if (b->arr[b->i][b->j] == '0')
                mlx_put_image_to_window(b->mlx, b->win, b->empty, SQUARE_SIZE * b->j, SQUARE_SIZE * b->i);
            if (b->arr[b->i][b->j] == 'C')
            {
                mlx_put_image_to_window(b->mlx, b->win, b->empty, SQUARE_SIZE * b->j, SQUARE_SIZE * b->i);
                mlx_put_image_to_window(b->mlx, b->win, b->col, SQUARE_SIZE * b->j + SQUARE_SIZE / 4, SQUARE_SIZE * b->i + SQUARE_SIZE / 4);
            }
            drow_player_exit(b);
            b->j++;
        }
        b->i++;
    }
}
