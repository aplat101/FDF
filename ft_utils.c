/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_utils.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aplat <aplat@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/22 03:52:02 by aplat        #+#   ##    ##    #+#       */
/*   Updated: 2019/05/29 18:29:07 by aplat       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

void		ft_adapt_zoom_side(t_fdf *fdf, int i)
{
	double	teta;
	double	right;
	double	left;

	teta = M_PI / 6;
	right = (cos(teta) * fdf->zoom[0]) + fdf->proj[0].proj_x;
	left = (((-i) * cos(teta)) * fdf->zoom[0]) + fdf->proj[0].proj_x;
	while (left < 1 || right > WD * 0.8)
	{
		fdf->zoom[0] -= 1;
		right = (cos(teta) * fdf->zoom[0]) + fdf->proj[0].proj_x;
		left = (((-i) * cos(teta)) * fdf->zoom[0]) + fdf->proj[0].proj_x;
	}
}

void		ft_swap_proj(t_fdf *fdf)
{
	int		res;

	res = fdf->mode_proj;
	if (fdf->mode_proj == 0)
		res = 1;
	if (fdf->mode_proj == 1)
		res = 0;
	fdf->mode_proj = res;
	ft_print(fdf);
}

void		ft_center(t_fdf *fdf)
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
	ft_adapt_zoom_para(fdf, i, j);
	ft_inferior_para(fdf);
	ft_superior_para(fdf);
}
