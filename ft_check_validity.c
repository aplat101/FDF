/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_check_validity.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aplat <aplat@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/16 21:05:43 by aplat        #+#   ##    ##    #+#       */
/*   Updated: 2019/04/21 20:04:59 by aplat       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

int				ft_check_line_caract(char c)
{
	if (c == ',' || c == 'x' || c == '-')
		return (1);
	if (c != 'x' && c != ',' && c != ' ' && c != '-')
		return (2);
	else
		return (3);
}

int				ft_check_line_validity(int i, char *line)
{
	int			res;

	res = 0;
	if (line[i] == ',')
	{
		i++;
		if (line[i] == '0' && line[i + 1] == 'x')
			i += 2;
		res = i + 6;
		while ((ft_isdigit(line[i]) || ft_check_hexa(line[i])) && i < res)
			i++;
		if (line[i] != ' ' && line[i] != '\0')
			return (-1);
	}
	else
		i++;
	return (i);
}

int				ft_check_hexa(int c)
{
	if ((c < 71 && c > 64) || (c > 96 && c < 103))
		return (1);
	else
		return (0);
}

int				ft_check_line(char *line)
{
	int			i;

	i = 0;
	while (line[i])
	{
		while (line[i] == ' ')
			i++;
		while (ft_isdigit(line[i]) || ft_check_line_caract(line[i]) == 1)
			i = ft_check_line_validity(i, line);
		if (((!(ft_isdigit(line[i]))) && ft_check_line_caract(line[i]) == 2)
			&& line[i] != '\0')
			return (-1);
	}
	return (0);
}

int				ft_check_validity(int fd)
{
	char		*line;
	int			res;
	static int	y;

	y = 0;
	while ((res = get_next_line(fd, &line)) == 1)
	{
		if (ft_check_line(line) < 0)
		{
			free(line);
			return (-1);
		}
		free(line);
		y++;
	}
	return (res == -1 ? -1 : y);
}
