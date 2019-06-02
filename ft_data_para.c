/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_data_para.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aplat <aplat@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/19 22:20:19 by aplat        #+#   ##    ##    #+#       */
/*   Updated: 2019/05/29 18:55:38 by aplat       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

t_point		*ft_stock_para(t_point **para, int i, t_point **file, t_fdf *fdf)
{
	int		j;

	j = 0;
	while (j < fdf->nbword[i] - 1)
	{
		para[i][j].x = file[i][j].x;
		para[i][j].y = file[i][j].y;
		para[i][j].z = file[i][j].z;
		para[i][j].color_f = fdf->file[i][j].color_f;
		para[i][j].color_g = ft_get_color_g(fdf, para[i][j]);
		j++;
	}
	return (para[i]);
}

t_point		**ft_alloc_para(t_point **file, t_fdf *fdf)
{
	int		i;

	i = 0;
	if (!(fdf->para = malloc(sizeof(t_point*) * fdf->nbline)))
		return (NULL);
	while (i < fdf->nbline)
	{
		if (!(fdf->para[i] = malloc(sizeof(t_point) * (fdf->nbword[i] + 1))))
			return (NULL);
		fdf->para[i] = ft_stock_para(fdf->para, i, file, fdf);
		i++;
	}
	return (fdf->para);
}
