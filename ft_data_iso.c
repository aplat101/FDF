/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_data_iso.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aplat <aplat@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/19 19:04:59 by aplat        #+#   ##    ##    #+#       */
/*   Updated: 2019/05/29 18:57:38 by aplat       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

t_point		*ft_stock_iso(t_point **iso, int i, t_point **file, t_fdf *fdf)
{
	int		j;
	int		z;

	j = 0;
	while (j < fdf->nbword[i] - 1)
	{
		z = file[i][j].z * fdf->ele[0];
		iso[i][j].x = ((j - i) * cos(M_PI / 6));
		iso[i][j].y = -(z) + ((j + i) * sin(M_PI / 6));
		iso[i][j].z = z;
		if (iso[i][j].z > fdf->zmax)
			fdf->zmax = iso[i][j].z;
		iso[i][j].color_f = fdf->file[i][j].color_f;
		iso[i][j].color_g = ft_get_color_g(fdf, iso[i][j]);
		j++;
	}
	return (iso[i]);
}

t_point		**ft_alloc_iso(t_point **file, t_fdf *fdf)
{
	int		i;

	i = 0;
	if (!(fdf->iso = malloc(sizeof(t_point*) * fdf->nbline)))
		return (NULL);
	while (i < fdf->nbline)
	{
		if (!((fdf->iso[i]) = malloc(sizeof(t_point) * (fdf->nbword[i]))))
			return (NULL);
		fdf->iso[i] = ft_stock_iso(fdf->iso, i, file, fdf);
		i++;
	}
	return (fdf->iso);
}
