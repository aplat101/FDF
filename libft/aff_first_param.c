/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   aff_first_param.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aplat <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/20 17:36:45 by aplat        #+#   ##    ##    #+#       */
/*   Updated: 2018/11/22 06:35:15 by aplat       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void		aff_first_param(int ac, char **str)
{
	if (ac >= 2)
		ft_putstr(str[1]);
	write(1, "\n", 1);
}