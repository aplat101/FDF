/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aplat <aplat@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/16 18:33:46 by aplat        #+#   ##    ##    #+#       */
/*   Updated: 2019/05/29 22:53:54 by aplat       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

static int	close_cross(t_fdf *fdf)
{
	(void)fdf;
	exit(0);
	return (0);
}

static void	loop(t_fdf *fdf)
{
	mlx_hook(fdf->mlx_window, 2, 0, key_press, fdf);
	mlx_hook(fdf->mlx_window, 3, 0, key_release, fdf);
	mlx_hook(fdf->mlx_window, 4, 0, mouse_press, fdf);
	mlx_hook(fdf->mlx_window, 17, (1L << 17), close_cross, fdf);
	mlx_loop(fdf->mlx_ptr);
}

int			main(int ac, char **av)
{
	t_fdf	fdf;

	ft_checkerror(ac, av, &fdf);
	if (!(fdf.nbword = malloc(sizeof(int) * fdf.nbline)))
		return (0);
	ft_init_mlx(&fdf);
	ft_init_value(&fdf);
	ft_init_window(&fdf);
	fdf.file = ft_alloc_data(av[ac - 1], &fdf);
	fdf.iso = ft_alloc_iso(fdf.file, &fdf);
	fdf.para = ft_alloc_para(fdf.file, &fdf);
	ft_center(&fdf);
	ft_print(&fdf);
	loop(&fdf);
	return (0);
}
