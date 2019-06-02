/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_window.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aplat <aplat@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/17 22:15:06 by aplat        #+#   ##    ##    #+#       */
/*   Updated: 2019/05/29 23:42:14 by aplat       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

void		ft_init_window(t_fdf *fdf)
{
	int		bpp;
	int		s_l;
	int		endian;

	fdf->mlx_ptr = mlx_init();
	fdf->mlx_window = mlx_new_window(fdf->mlx_ptr, WD, HH, "FDF");
	fdf->img_ptr = mlx_new_image(fdf->mlx_ptr, (int)POST, HH);
	fdf->img = (int*)mlx_get_data_addr(fdf->img_ptr, &(bpp), &(s_l), &(endian));
	fdf->img_info = mlx_new_image(fdf->mlx_ptr, (int)(TIN), HH);
	fdf->info =
	(int*)mlx_get_data_addr(fdf->img_info, &(bpp), &(s_l), &(endian));
}

void		ft_new_img(t_fdf *fdf)
{
	int		bpp;
	int		s_l;
	int		endian;

	mlx_destroy_image(fdf->mlx_ptr, fdf->img_ptr);
	fdf->img_ptr = mlx_new_image(fdf->mlx_ptr, POST, HH);
	fdf->img = (int*)mlx_get_data_addr(fdf->img_ptr, &(bpp), &(s_l), &(endian));
	mlx_destroy_image(fdf->mlx_ptr, fdf->img_info);
	fdf->img_info = mlx_new_image(fdf->mlx_ptr, TIN, HH);
	fdf->info =
	(int*)mlx_get_data_addr(fdf->img_info, &(bpp), &(s_l), &(endian));
}

void		ft_frame(t_fdf *fdf)
{
	int		i;

	i = -1;
	while (++i < TIN)
	{
		fdf->info[i] = RED;
		fdf->info[(int)(TIN) + i] = RED;
		fdf->info[(int)(2 * TIN) + i] = RED;
		fdf->info[(int)((HH - 1) * TIN) + i] = RED;
		fdf->info[(int)((HH - 2) * TIN) + i] = RED;
		fdf->info[(int)((HH - 3) * TIN) + i] = RED;
	}
	i = -1;
	while (++i < HH)
	{
		fdf->info[(int)(i * TIN)] = RED;
		fdf->info[(int)(i * TIN) + 1] = RED;
		fdf->info[(int)(i * TIN) + 2] = RED;
		fdf->info[(int)((i * TIN) + ((TIN) - 1))] = RED;
		fdf->info[(int)((i * TIN) + ((TIN) - 1)) - 1] = RED;
		fdf->info[(int)((i * TIN) + ((TIN) - 1)) - 2] = RED;
	}
	mlx_put_image_to_window(fdf->info, fdf->mlx_window, fdf->img_info, POST, 0);
	ft_fill_frame(fdf);
}

void		ft_fill_frame(t_fdf *fdf)
{
	void	*ptr;
	void	*win;

	ptr = fdf->mlx_ptr;
	win = fdf->mlx_window;
	mlx_string_put(ptr, win, WD * 0.9 - 15, 10, WHITE, "FDF");
	mlx_string_put(ptr, win, WDI, HH * 0.05, WHITE, ESC);
	mlx_string_put(ptr, win, WDI, HH * 0.10, WHITE, TRANS);
	mlx_string_put(ptr, win, WDI, HH * 0.15, WHITE, ZP);
	mlx_string_put(ptr, win, WDI, HH * 0.20, WHITE, ZM);
	mlx_string_put(ptr, win, WDI, HH * 0.25, WHITE, ELE);
	mlx_string_put(ptr, win, WDI, HH * 0.30, WHITE, CENTER);
	mlx_string_put(ptr, win, WDI, HH * 0.35, WHITE, RESET);
	mlx_string_put(ptr, win, WDI, HH * 0.40, WHITE, CRESET);
	mlx_string_put(ptr, win, WDI, HH * 0.45, WHITE, SWAPP);
	mlx_string_put(ptr, win, WDI, HH * 0.50, WHITE, SWAPC);
	if (fdf->mode_color == 0)
	{
		mlx_string_put(ptr, win, WDI, HH * 0.55, WHITE, CTB);
		mlx_string_put(ptr, win, WDI, HH * 0.60, WHITE, CTW);
	}
	ft_interactive_fill(fdf);
}

void		ft_interactive_fill(t_fdf *fdf)
{
	void	*ptr;
	void	*win;

	ptr = fdf->mlx_ptr;
	win = fdf->mlx_window;
	if (fdf->mode_proj == 0)
		mlx_string_put(ptr, win, WDI, HH * 0.85, WHITE, PMI);
	else
		mlx_string_put(ptr, win, WDI, HH * 0.85, WHITE, PMP);
	if (fdf->mode_color == 0)
		mlx_string_put(ptr, win, WDI, HH * 0.90, WHITE, CMP);
	if (fdf->mode_color == 1)
		mlx_string_put(ptr, win, WDI, HH * 0.90, WHITE, CMI);
	if (fdf->mode_color == 2)
		mlx_string_put(ptr, win, WDI, HH * 0.90, WHITE, CMG);
}
