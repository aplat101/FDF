/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_translate.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aplat <aplat@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/23 15:36:16 by aplat        #+#   ##    ##    #+#       */
/*   Updated: 2019/05/29 18:58:29 by aplat       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

void	ft_move_right(t_fdf *fdf)
{
	fdf->proj[fdf->mode_proj].proj_x += 10;
	ft_print(fdf);
}

void	ft_move_left(t_fdf *fdf)
{
	fdf->proj[fdf->mode_proj].proj_x -= 10;
	ft_print(fdf);
}

void	ft_move_down(t_fdf *fdf)
{
	fdf->proj[fdf->mode_proj].proj_y += 10;
	ft_print(fdf);
}

void	ft_move_up(t_fdf *fdf)
{
	fdf->proj[fdf->mode_proj].proj_y -= 10;
	ft_print(fdf);
}
