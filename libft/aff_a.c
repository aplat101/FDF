/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   aff_a.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aplat <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/20 16:17:38 by aplat        #+#   ##    ##    #+#       */
/*   Updated: 2018/11/20 16:29:56 by aplat       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	aff_a(int ac, char *str)
{
	if (ac == 2)
	{
		while (*str != 'a')
			str++;
		if (*str == 'a')
			write(1, "a\n", 2);
	}
	if (ac == 1)
		write(1, "a\n", 2);
}