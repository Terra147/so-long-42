#include "so_long.h"
#include <sys/time.h>

#define WIN_WIDTH 800
#define WIN_HEIGHT 600
// Keycode definitions for AWDS keys
#define KEY_W 119
#define KEY_A 97
#define KEY_S 115
#define KEY_D 100
#define KEY_ESC 65307

typedef struct s_wall {
    int x;
    int y;
    int width;
    int height;
    void *img_ptr;
} t_wall;

typedef struct s_data {
    void *mlx_ptr;
    void *win_ptr;
    void *img_ptr;
    int img_x;
    int img_y;
    int img_speed;
    int key_state[100000];
    int img_w;
    int img_h;
    t_wall wall;
} t_data;

double get_time_in_seconds() {
    struct timeval now;
    gettimeofday(&now, NULL);
    return now.tv_sec + now.tv_usec / 1000000.0;
}

int check_collision(t_data *data, int new_x, int new_y) {
    // Check collision with the wall
    if (new_x < data->wall.x + data->wall.width && new_x + data->img_w > data->wall.x &&
        new_y < data->wall.y + data->wall.height && new_y + data->img_h > data->wall.y) {
        return 1; // Collision detected
    }
    return 0; // No collision
}

void animation_hook(t_data *data) {
    static double last_update = 0;
    double now = get_time_in_seconds();
    double elapsed_time = now - last_update;

    if (elapsed_time >= 0.01667) { // Target 60 FPS
        last_update = now;

        int new_x = data->img_x;
        int new_y = data->img_y;

        if (data->key_state[KEY_A]) new_x -= data->img_speed;
        if (data->key_state[KEY_D]) new_x += data->img_speed;
        if (data->key_state[KEY_W]) new_y -= data->img_speed;
        if (data->key_state[KEY_S]) new_y += data->img_speed;

        if (!check_collision(data, new_x, new_y)) {
            data->img_x = new_x;
            data->img_y = new_y;
        }

        mlx_clear_window(data->mlx_ptr, data->win_ptr);
        mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, data->img_x, data->img_y);
        mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->wall.img_ptr, data->wall.x, data->wall.y);
    }
}

int key_press_hook(int keycode, t_data *data) {
    if (keycode == KEY_ESC) exit(0); // Exit program
    data->key_state[keycode] = 1;
    return 0;
}

int key_release_hook(int keycode, t_data *data) {
    data->key_state[keycode] = 0;
    return 0;
}

int main(void) {
    t_data data;

    data.mlx_ptr = mlx_init();
    data.win_ptr = mlx_new_window(data.mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "Smooth Movement");
    data.img_ptr = mlx_xpm_file_to_image(data.mlx_ptr, "assets/wall.xpm", &data.img_w, &data.img_h);
    data.img_x = WIN_WIDTH / 2 - data.img_w / 2;
    data.img_y = WIN_HEIGHT / 2 - data.img_h / 2;
    data.img_speed = 10;

    for (size_t i = 0; i < 100000; i++)
	{
		data.key_state[i] = 0;
	}

    // Setup the wall
    data.wall.x = 300;
    data.wall.y = 200;
    data.wall.img_ptr = mlx_xpm_file_to_image(data.mlx_ptr, "assets/wall.xpm", &data.wall.width, &data.wall.height);


    if (!data.img_ptr || !data.wall.img_ptr) exit(1); // Handle loading errors

    mlx_hook(data.win_ptr, 2, 1L<<0, key_press_hook, &data);
    mlx_hook(data.win_ptr, 3, 1L<<1, key_release_hook, &data);
    mlx_loop_hook(data.mlx_ptr, (void *)animation_hook, &data);
    mlx_loop(data.mlx_ptr);

    return 0;
}
