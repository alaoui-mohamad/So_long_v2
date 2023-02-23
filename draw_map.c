#include "mlx.h"

int main()
{

    void *mlx = mlx_init();
    int square_size = 64;
    void *win = mlx_new_window(mlx, 10 * square_size, 5 * square_size, "My Map");
    int width;
    int height;
    void *img = mlx_xpm_file_to_image(mlx, "myimage.xpm", &width, &height);

    int i = 0;
    int j;
    while (i < 5)
    {
        j = 0;
        while (j < 10)
        {
            mlx_put_image_to_window(mlx, win, img, square_size * j, square_size * i);
            j++;
        }
        i++;
    }

    mlx_loop(mlx);
    // Close the window and free resources

    return 0;
}