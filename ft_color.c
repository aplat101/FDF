/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_color.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aplat <aplat@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/15 17:14:09 by aplat        #+#   ##    ##    #+#       */
/*   Updated: 2019/05/29 18:39:04 by aplat       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

void	ft_update_color(t_point **tp, t_fdf *fdf)
{
	int	i;
	int	j;

	i = 0;
	while (i < fdf->nbline)
	{
		j = 0;
		while (j < fdf->nbword[i] - 1)
		{
			tp[i][j].color_g = ft_get_color_g(fdf, tp[i][j]);
			j++;
		}
		i++;
	}
}

int		ft_get_color_g(t_fdf *fdf, t_point p)
{
	int	dif;

	dif = fdf->color_max - fdf->color_min;
	if (p.z < 0)
		return (fdf->color_min);
	else
		return ((int)((p.z / fdf->zmax) * dif) + fdf->color_min);
}

int		get_light(int start, int end, double percentage)
{
	return ((int)((1 - percentage) * start + percentage * end));
}

void	ft_swap_color(t_fdf *fdf)
{
	int res;

	res = fdf->mode_color;
	if (fdf->mode_color == 0)
		res = 1;
	if (fdf->mode_color == 1)
		res = 2;
	if (fdf->mode_color == 2)
		res = 0;
	fdf->mode_color = res;
	ft_print(fdf);
}

int		ft_get_color(t_fdf *fdf, double percent, t_point t1, t_point t2)
{
	int c;
	int	red;
	int	green;
	int blue;
	int	cg;

	cg = t1.color_g;
	if (fdf->mode_color == 0)
		c = fdf->single_c[fdf->mode_proj];
	if (fdf->mode_color == 1)
		c = t1.color_f;
	if (fdf->mode_color == 2)
	{
		red = get_light((cg >> 16) & 0xFF, (t2.color_g >> 16) & 0xFF, percent);
		green = get_light((cg >> 8) & 0xFF, (t2.color_g >> 8) & 0xFF, percent);
		blue = get_light(cg & 0xFF, t2.color_g & 0xFF, percent);
		return ((red << 16) | (green << 8) | blue);
	}
	return (c);
}
