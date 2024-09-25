#include <mlx.h>

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	draw_square(t_data *img, int x0, int y0, int side_length, int color)
{
	int	x;
	int	y;

	// Loop pelos pixels dentro do quadrado
	y = y0;
	while (y < y0 + side_length)
	{
		x = x0;
		while (x < x0 + side_length)
		{
			my_mlx_pixel_put(img, x, y, color);
			x++;
		}
		y++;
	}
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 800, 800, "Draw Square Example");
	img.img = mlx_new_image(mlx, 800, 800);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);

	// Desenhar um quadrado começando no ponto (100, 100), com lado de 200 pixels, cor vermelha
	draw_square(&img, 50, 50, 200, 0x00FF0000);

	// Mostrar a imagem na janela
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}

