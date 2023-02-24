#include "mlx.h"
#include "so_long.h"

int draw_map(char **map)
{

    void *mlx = mlx_init();
    int square_size = 32;
    int x;
    int y;

    y = ft_count_colums(map);
    x = ft_strlen(map[0]);
    void *win = mlx_new_window(mlx, x * square_size, y * square_size, "My Map");
    int width;
    int height;
    void *exit = mlx_xpm_file_to_image(mlx, "assets/exit.xpm", &width, &height);
    void *empty = mlx_xpm_file_to_image(mlx, "assets/empty.xpm", &width, &height);
    void *col = mlx_xpm_file_to_image(mlx, "assets/col.xpm", &width, &height);
    void *wall = mlx_xpm_file_to_image(mlx, "assets/wall.xpm", &width, &height);
    void *player = mlx_xpm_file_to_image(mlx, "assets/player.xpm", &width, &height);

    int i = 0;
    int j;
    while (i < y)
    {
        j = 0;
        while (j < x)
        {
            if (map[i][j] == '1')
            {
                mlx_put_image_to_window(mlx, win, wall, square_size * j, square_size * i);
            }
            if (map[i][j] == '0')
                mlx_put_image_to_window(mlx, win, empty, square_size * j, square_size * i);
            if (map[i][j] == 'C')
            {
                mlx_put_image_to_window(mlx, win, empty, square_size * j, square_size * i);
                mlx_put_image_to_window(mlx, win, col, square_size * j + square_size / 4, square_size * i + square_size / 4);
            }
            if (map[i][j] == 'E')
            {
                mlx_put_image_to_window(mlx, win, empty, square_size * j, square_size * i);
                mlx_put_image_to_window(mlx, win, exit, square_size * j, square_size * i);
            }
            if (map[i][j] == 'P')
            {
                mlx_put_image_to_window(mlx, win, empty, square_size * j, square_size * i);
                mlx_put_image_to_window(mlx, win, player, square_size * j, square_size * i);
            }
            j++;
        }
        i++;
    }

    mlx_loop(mlx);

    return 0;
}