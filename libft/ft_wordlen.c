/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_wordlen.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aplat <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/15 16:30:41 by aplat        #+#   ##    ##    #+#       */
/*   Updated: 2018/10/18 22:46:05 by aplat       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_wordlen(const char *s, char c)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (0);
	while (*s != c)
	{
		s++;
		i++;
	}
	return (i);
}