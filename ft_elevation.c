/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_elevation.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aplat <aplat@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/23 17:45:53 by aplat        #+#   ##    ##    #+#       */
/*   Updated: 2019/05/29 18:52:23 by aplat       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

void	ft_eleup(t_fdf *fdf)
{
	fdf->ele[fdf->mode_proj] *= 1.05;
	ft_print(fdf);
}

void	ft_eledown(t_fdf *fdf)
{
	fdf->ele[fdf->mode_proj] *= 0.95;
	ft_print(fdf);
}

void	ft_reset_ele(t_fdf *fdf)
{
	fdf->ele[fdf->mode_proj] = 1;
	ft_print(fdf);
}
