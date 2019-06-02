/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_center_para.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aplat <aplat@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/30 17:18:59 by aplat        #+#   ##    ##    #+#       */
/*   Updated: 2019/05/29 16:43:55 by aplat       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

void	ft_superior_para(t_fdf *fdf)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = (fdf->nbline - 1) / 2;
	j = (fdf->nbword[i] - 2) / 2;
	x = (fdf->file[i][j].x * fdf->zoom[1]) + fdf->proj[1].proj_x;
	y = (fdf->file[i][j].y * fdf->zoom[1]) + fdf->proj[1].proj_y;
	while (x >= (WD * 0.8) / 2)
	{
		fdf->proj[1].proj_x -= 1;
		x -= 1;
	}
	while (y >= HH / 2)
	{
		fdf->proj[1].proj_y -= 1;
		y -= 1;
	}
}

void	ft_inferior_para(t_fdf *fdf)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = (fdf->nbline - 1) / 2;
	j = (fdf->nbword[i] - 2) / 2;
	x = (fdf->file[i][j].x * fdf->zoom[1]) + fdf->proj[1].proj_x;
	y = (fdf->file[i][j].y * fdf->zoom[1]) + fdf->proj[1].proj_y;
	while (x <= (WD * 0.8) / 2)
	{
		fdf->proj[1].proj_x += 1;
		x += 1;
	}
	while (y <= HH / 2)
	{
		fdf->proj[1].proj_y += 1;
		y += 1;
	}
}

void	ft_center_para(t_fdf *fdf)
{
	int	i;
	int	j;

	i = fdf->nbline - 1;
	j = fdf->nbword[i] - 2;
	ft_adapt_zoom_para(fdf, i, j);
	ft_inferior_para(fdf);
	ft_superior_para(fdf);
	ft_print(fdf);
}
