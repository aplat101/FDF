/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_bresenham.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aplat <aplat@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/19 23:27:12 by aplat        #+#   ##    ##    #+#       */
/*   Updated: 2019/05/29 18:50:56 by aplat       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

void		ft_get_cur(t_point *d, int i, t_point *t1, t_point *cur)
{
	cur->x = (int)(t1->x + (int)(d->x * i));
	cur->y = (int)(t1->y + (int)(d->y * i));
}

void		ft_calculate(t_point *t1, t_point *t2, t_fdf *fdf)
{
	t1->x += fdf->proj[fdf->mode_proj].proj_x;
	t1->y += fdf->proj[fdf->mode_proj].proj_y;
	t2->x += fdf->proj[fdf->mode_proj].proj_x;
	t2->y += fdf->proj[fdf->mode_proj].proj_y;
}

double		ft_percentage(t_point *d, t_point *t1, t_point *t2, t_point *cur)
{
	double	placement;
	double	distance;

	if (d->x > d->y)
	{
		placement = cur->x - t1->x;
		distance = t2->x - t1->x;
		return ((distance == 0) ? 1.0 : (placement / distance));
	}
	else
	{
		placement = cur->y - t1->y;
		distance = t2->y - t1->y;
		return ((distance == 0) ? 1.0 : (placement / distance));
	}
}

void		ft_get_point_delta(t_point *d, int *nb_point)
{
	if (fabs(d->x) > fabs(d->y))
	{
		*nb_point = abs((int)d->x);
		d->y = d->y / fabs(d->x);
		d->x = d->x / fabs(d->x);
	}
	else
	{
		*nb_point = abs((int)d->y);
		d->x = d->x / fabs(d->y);
		d->y = d->y / fabs(d->y);
	}
}

void		ft_bresenham(t_point t1, t_point t2, t_fdf *fdf)
{
	t_point d;
	int		i;
	int		nb_point;
	double	per;
	t_point	cur;

	ft_calculate(&t1, &t2, fdf);
	i = 0;
	d.x = t2.x - t1.x;
	d.y = t2.y - t1.y;
	ft_get_point_delta(&d, &nb_point);
	while (i <= nb_point)
	{
		ft_get_cur(&d, i, &t1, &cur);
		per = ft_percentage(&d, &t1, &t2, &cur);
		if ((((cur.y * POST) + cur.x < (POST * HH) - 1) &&
			(((cur.y * POST) + cur.x > 0) &&
			cur.x > 0 && cur.x < (POST) - 1)
			&& cur.y > 0 && cur.y < HH - 1))
		{
			fdf->img[(int)((cur.y * POST) + cur.x)] =
			ft_get_color(fdf, per, t1, t2);
		}
		i++;
	}
}
