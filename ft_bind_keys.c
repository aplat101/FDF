/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_bind_keys.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aplat <aplat@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/22 02:12:00 by aplat        #+#   ##    ##    #+#       */
/*   Updated: 2019/05/29 16:40:46 by aplat       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

int	key_press(int keycode, t_fdf *fdf)
{
	if (keycode == K_ESC)
	{
		(void)fdf;
		exit(0);
		return (0);
	}
	if (keycode == K_LEFT)
		ft_move_left(fdf);
	if (keycode == K_RIGHT)
		ft_move_right(fdf);
	if (keycode == K_DOWN)
		ft_move_down(fdf);
	if (keycode == K_UP)
		ft_move_up(fdf);
	if (keycode == K_PAD_PLUS)
		ft_eleup(fdf);
	if (keycode == K_PAD_MINUS)
		ft_eledown(fdf);
	if (keycode == K_W)
		ft_colortowhite(fdf);
	if (keycode == K_B)
		ft_colortoblack(fdf);
	return (0);
}

int	key_release(int keycode, t_fdf *fdf)
{
	if (keycode == K_P)
		ft_swap_proj(fdf);
	if (keycode == K_C)
	{
		if (fdf->mode_proj == 0)
			ft_center_iso(fdf);
		if (fdf->mode_proj == 1)
			ft_center_para(fdf);
	}
	if (keycode == K_R)
		ft_reset_ele(fdf);
	if (keycode == K_A)
	{
		ft_reset_ele(fdf);
		if (fdf->mode_proj == 0)
			ft_center_iso(fdf);
		if (fdf->mode_proj == 1)
			ft_center_para(fdf);
	}
	if (keycode == K_S)
		ft_swap_color(fdf);
	return (0);
}

int	mouse_press(int button, int x, int y, t_fdf *fdf)
{
	y = x;
	if (button == M_WHEELDOWN)
		ft_zoomp(fdf);
	if (button == M_WHEELUP)
		ft_zoomm(fdf);
	return (0);
}
