/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_zoom.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aplat <aplat@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/22 05:27:07 by aplat        #+#   ##    ##    #+#       */
/*   Updated: 2019/05/29 23:43:43 by aplat       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

void		ft_zoomp(t_fdf *fdf)
{
	fdf->zoom[fdf->mode_proj] *= 1.1;
	ft_print(fdf);
}

void		ft_zoomm(t_fdf *fdf)
{
	fdf->zoom[fdf->mode_proj] *= 0.9;
	ft_print(fdf);
}

void		ft_adapt_zoom_para(t_fdf *fdf, int i, int j)
{
	fdf->max_p.x = i * fdf->zoom[1];
	fdf->max_p.y = j * fdf->zoom[1];
	if (fdf->max_i.x < (WD * 0.8) || fdf->max_i.y < HH)
	{
		while (fdf->max_p.x < (WD * 0.8) && fdf->max_p.y < HH)
		{
			fdf->zoom[1] += 1;
			fdf->max_p.x = i * fdf->zoom[1];
			fdf->max_p.y = j * fdf->zoom[1];
		}
	}
	while (fdf->max_p.x >= (WD * 0.8) || fdf->max_p.y >= HH)
	{
		fdf->zoom[1] -= 1;
		fdf->max_p.x = i * fdf->zoom[1];
		fdf->max_p.y = j * fdf->zoom[1];
	}
}

void		ft_adapt_zoom_iso(t_fdf *fdf, int i, int j)
{
	double	z;
	double	teta;

	z = fdf->file[i][j].z;
	teta = M_PI / 6;
	fdf->max_i.x = ((j - i) * cos(teta)) * fdf->zoom[0];
	fdf->max_i.y = -z + (((j + i) * sin(teta)) * fdf->zoom[0]);
	if (fdf->max_i.x < (WD * 0.8) || fdf->max_i.y < HH)
	{
		while (fdf->max_i.x < (WD * 0.8) && fdf->max_i.y < HH)
		{
			fdf->zoom[0] += 1;
			fdf->max_i.x = ((j - i) * cos(teta)) * fdf->zoom[0];
			fdf->max_i.y = -z + (((j + i) * sin(teta)) * fdf->zoom[0]);
		}
	}
	while (fdf->max_i.x >= (WD * 0.8) || fdf->max_i.y >= HH)
	{
		fdf->zoom[0] -= 1;
		fdf->max_i.x = ((j - i) * cos(teta)) * fdf->zoom[0];
		fdf->max_i.y = -z + (((j + i) * sin(teta)) * fdf->zoom[0]);
	}
}

void		ft_adapt_zoom(t_fdf *fdf)
{
	int		i;
	int		j;

	i = fdf->nbline - 1;
	j = fdf->nbword[i] - 2;
	if (fdf->mode_proj == 0)
		ft_adapt_zoom_iso(fdf, i, j);
	if (fdf->mode_proj == 1)
		ft_adapt_zoom_para(fdf, i, j);
}
