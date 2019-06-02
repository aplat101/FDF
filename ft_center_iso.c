/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_center_iso.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aplat <aplat@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/23 18:21:36 by aplat        #+#   ##    ##    #+#       */
/*   Updated: 2019/05/29 18:33:41 by aplat       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

void		ft_iso_wd(t_fdf *fdf)
{
	int		i;
	int		j;
	double	res;

	i = fdf->nbline / 2;
	j = fdf->nbword[i] / 2;
	res = ((j - i) * cos(TETA)) * fdf->zoom[0] + fdf->proj[0].proj_x;
	if (res > (WD * 0.8) / 2)
	{
		while (res > (WD * 0.8) / 2)
		{
			fdf->proj[0].proj_x -= 5;
			res -= 5;
		}
	}
	while (res < (WD * 0.8) / 2)
	{
		fdf->proj[0].proj_x += 1;
		res += 1;
	}
}

void		ft_iso_hh(t_fdf *fdf)
{
	int		i;
	int		j;
	double	res;
	double	max;
	int		proj;

	i = fdf->nbline / 2;
	j = fdf->nbword[i] / 2;
	proj = fdf->proj[0].proj_y;
	res = -(fdf->file[i][j].z) + (((j + i) * sin(TETA)) * fdf->zoom[0]) + proj;
	max = -(fdf->max.z) + (((j + i) * sin(TETA)) * fdf->zoom[0]) + proj;
	if (res < HH / 2)
	{
		while (max++ < HH)
		{
			fdf->proj[0].proj_y += 1;
			res += 1;
		}
	}
	max = (fdf->iso[0][0].y * fdf->zoom[0]) + proj;
	if (res > HH / 2)
	{
		while (res-- > HH / 2)
			fdf->proj[0].proj_y -= 1;
	}
}

void		ft_center_middle_point(t_fdf *fdf, int i, int j)
{
	double	x;
	double	y;
	int		proj;

	proj = fdf->proj[0].proj_y;
	x = (((j - i) * cos(TETA)) * fdf->zoom[0]) + fdf->proj[0].proj_x;
	y = (-(fdf->file[i][j].z) + ((j + i) * sin(TETA)) * fdf->zoom[0]) + proj;
	while (x < (WD * 0.8) / 2)
	{
		x += 1;
		fdf->proj[0].proj_x += 1;
	}
	while (y < HH / 2)
	{
		y += 1;
		fdf->proj[0].proj_y += 1;
	}
}

void		ft_center_iso(t_fdf *fdf)
{
	int		i;
	int		j;

	i = fdf->nbline - 1;
	j = fdf->nbword[i] - 2;
	ft_adapt_zoom_iso(fdf, i, j);
	ft_iso_wd(fdf);
	ft_iso_hh(fdf);
	ft_adapt_zoom_side(fdf, i);
	ft_center_middle_point(fdf, i / 2, j / 2);
	ft_print(fdf);
}
