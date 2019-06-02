/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_error.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aplat <aplat@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/16 18:33:15 by aplat        #+#   ##    ##    #+#       */
/*   Updated: 2019/04/17 22:49:01 by aplat       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

void		ft_one_arg(void)
{
	ft_putstr("usage : ./fdf Need One Argument\n");
	exit(0);
}

void		ft_existing_arg(int fd)
{
	ft_putstr("usage : ./fdf Need Existing Argument\n");
	close(fd);
	exit(0);
}

void		ft_valid_arg(int fd)
{
	ft_putstr("usage : ./fdf Need Valid Argument\n");
	close(fd);
	exit(0);
}

void		ft_checkerror(int ac, char **av, t_fdf *fdf)
{
	int		fd1;
	int		res;

	if (ac != 2)
		ft_one_arg();
	fd1 = open(av[ac - 1], O_RDONLY);
	if (fd1 < 0)
		ft_existing_arg(fd1);
	if ((res = ft_check_validity(fd1)) < 0)
		ft_valid_arg(fd1);
	close(fd1);
	fdf->nbline = res;
}
