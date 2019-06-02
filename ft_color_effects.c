/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_color_effects.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aplat <aplat@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/16 18:18:56 by aplat        #+#   ##    ##    #+#       */
/*   Updated: 2019/05/29 16:45:57 by aplat       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

void	ft_colortoblack(t_fdf *fdf)
{
	if (fdf->mode_color == 0)
	{
		if (fdf->single_c[fdf->mode_proj] - 500 < 0)
			fdf->single_c[fdf->mode_proj] = 0;
		else
			fdf->single_c[fdf->mode_proj] -= 500;
	}
	ft_print(fdf);
}

void	ft_colortowhite(t_fdf *fdf)
{
	if (fdf->mode_color == 0)
	{
		if (fdf->single_c[fdf->mode_proj] + 500 > 16777215)
			fdf->single_c[fdf->mode_proj] = 16777215;
		else
			fdf->single_c[fdf->mode_proj] += 500;
	}
	ft_print(fdf);
}
