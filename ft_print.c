/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_print.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aplat <aplat@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/19 23:20:08 by aplat        #+#   ##    ##    #+#       */
/*   Updated: 2019/05/29 19:20:08 by aplat       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

int			ft_check(t_point t1, t_point t2, t_fdf *fdf)
{
	int		res;

	res = 1;
	ft_calculate(&t1, &t2, fdf);
	if (t1.x < 0 && t2.x < 0)
		res = 0;
	if (t1.x > WD * 0.8 && t2.x > WD * 0.8)
		res = 0;
	if (t1.y < 0 && t2.y < 0)
		res = 0;
	if (t1.y > HH && t2.y > HH)
		res = 0;
	return (res);
}

void		ft_take_zoom(t_point **p, t_fdf *fdf)
{
	int		i;
	int		j;
	double	z;

	i = -1;
	while (++i < fdf->nbline)
	{
		j = -1;
		while (++j < fdf->nbword[i])
		{
			if (fdf->mode_proj == 0)
			{
				p[i][j].z = fdf->file[i][j].z * fdf->ele[0];
				z = fdf->iso[i][j].z;
				p[i][j].x = ((j - i) * cos(TETA)) * fdf->zoom[0];
				p[i][j].y = -(z) + ((j + i) * sin(TETA)) * fdf->zoom[0];
			}
			if (fdf->mode_proj == 1)
			{
				p[i][j].x = fdf->file[i][j].x * fdf->zoom[1];
				p[i][j].y = fdf->file[i][j].y * fdf->zoom[1];
				p[i][j].z = fdf->file[i][j].z * fdf->ele[1];
			}
		}
	}
}

void		ft_draw(t_point **p, t_fdf *fdf)
{
	int		i;
	int		j;

	i = 0;
	ft_new_img(fdf);
	ft_frame(fdf);
	while (i < fdf->nbline)
	{
		j = 0;
		while (j < fdf->nbword[i] - 1)
		{
			if (j + 1 < fdf->nbword[i] - 1 &&
				ft_check(p[i][j], p[i][j + 1], fdf) == 1)
				ft_bresenham(p[i][j], p[i][j + 1], fdf);
			if (i + 1 < fdf->nbline && ft_check(p[i][j], p[i + 1][j], fdf) == 1)
				ft_bresenham(p[i][j], p[i + 1][j], fdf);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(fdf->img, fdf->mlx_window, fdf->img_ptr, 0, 0);
}

void		ft_print(t_fdf *fdf)
{
	if (fdf->mode_proj == 0)
	{
		ft_take_zoom(fdf->iso, fdf);
		ft_draw(fdf->iso, fdf);
	}
	else
	{
		ft_take_zoom(fdf->para, fdf);
		ft_draw(fdf->para, fdf);
	}
}
