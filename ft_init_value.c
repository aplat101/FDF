/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_init_value.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aplat <aplat@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/22 01:38:35 by aplat        #+#   ##    ##    #+#       */
/*   Updated: 2019/05/29 19:07:39 by aplat       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

void	ft_init_mlx(t_fdf *fdf)
{
	fdf->mlx_ptr = NULL;
	fdf->mlx_window = NULL;
	fdf->img_ptr = NULL;
	fdf->img_info = NULL;
	fdf->mode_proj = 0;
	fdf->mode_color = 0;
	fdf->single_c[0] = WHITE;
	fdf->single_c[1] = WHITE;
	fdf->zmax = 0;
	fdf->color_min = RED;
	fdf->color_max = WHITE;
}

void	ft_init_ele(t_fdf *fdf)
{
	fdf->ele[0] = 1;
	fdf->ele[1] = 1;
}

void	ft_init_proj(t_fdf *fdf)
{
	fdf->proj[0].proj_x = 0;
	fdf->proj[0].proj_y = 0;
	fdf->proj[1].proj_x = 0;
	fdf->proj[1].proj_y = 0;
}

void	ft_init_zoom(t_fdf *fdf)
{
	fdf->zoom[0] = 1;
	fdf->zoom[1] = 1;
}

void	ft_init_value(t_fdf *fdf)
{
	ft_init_proj(fdf);
	ft_init_zoom(fdf);
	ft_init_ele(fdf);
}
