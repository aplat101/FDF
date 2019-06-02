/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   first_word.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aplat <aplat@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/21 22:43:43 by aplat        #+#   ##    ##    #+#       */
/*   Updated: 2019/05/30 11:51:54 by aplat       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void		first_word(int ac, char **str)
{
	if (ac != 2)
		write(1, "\n", 1);
	else
	{
		while (*str[ac - 1] && (*str[ac - 1] == ' ' || *str[ac - 1] == '\t'))
			str[ac - 1]++;
		while (*str[ac - 1] && *str[ac - 1] != ' ' && *str[ac - 1] != '\t')
		{
			ft_putchar(*str[ac - 1]);
			str[ac - 1]++;
		}
		write(1, "\n", 1);
	}
}
