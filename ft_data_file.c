/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_data_file.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aplat <aplat@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/17 22:44:31 by aplat        #+#   ##    ##    #+#       */
/*   Updated: 2019/05/29 19:10:46 by aplat       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

char		*ft_strnewzero(size_t size)
{
	char	*str;
	size_t	i;

	i = 0;
	if (!(str = ft_memalloc(size + 1)))
		return (NULL);
	while (i < size)
	{
		str[i] = '0';
		i++;
	}
	str[size] = '\0';
	return (str);
}

int			ft_converthexint(char *line, int power)
{
	int		i;
	double	res;

	res = 0;
	i = 0;
	if (!line)
		return (16777215);
	while (line[i] && power >= 0)
	{
		if (ft_isalpha(line[i]))
		{
			if (line[i] > 64 && line[i] < 71)
				res = res + ((line[i] - 55) * ft_power(16, power));
			if (line[i] > 96 && line[i] < 103)
				res = res + ((line[i] - 87) * ft_power(16, power));
		}
		if (ft_isdigit(line[i]))
			res = res + ((line[i] - 48) * ft_power(16, power));
		else if ((!ft_isdigit(line[i])) && (!ft_isalpha(line[i])))
			return (16777215);
		i++;
		power--;
	}
	return (res);
}

void		ft_check_data_color(t_point *file, int *j, char *line)
{
	char	*hexa;
	int		i;

	while ((ft_isdigit(line[*j]) || line[*j] == '-') && line[*j])
		*j += 1;
	if (line[*j] == ',' && line[*j + 1] == '0' && line[*j + 2] == 'x')
	{
		*j += 3;
		i = 0;
		while (line[*j + i] != ' ' && line[*j + i] != '\0')
			i++;
		if (!(hexa = ft_strnewzero(6)))
			return ;
		file->color_f = ft_converthexint(ft_strncpy(hexa, &(line[*j]), i), 5);
		free(hexa);
		*j += i;
	}
	else
		file->color_f = 16777215;
}

t_point		*ft_stock_data(t_point *file, int nbl, int nbword, char *line)
{
	int		index;
	int		j;

	index = 0;
	j = 0;
	while (index < nbword && line[j])
	{
		while (line[j] == ' ' && line[j])
			j++;
		if (ft_isdigit(line[j]) || (line[j] == '-' && ft_isdigit(line[j + 1])))
		{
			file[index].x = index;
			file[index].y = nbl;
			file[index].z = (double)ft_atoi(&line[j]);
			ft_check_data_color(&file[index], &j, line);
			index++;
		}
	}
	return (file);
}

t_point		**ft_alloc_data(char *av, t_fdf *fdf)
{
	int		fd;
	char	*line;
	int		i;
	int		res;

	i = 0;
	fd = open(av, O_RDONLY);
	if (!(fdf->file = (t_point**)malloc(sizeof(t_point*) * (fdf->nbline))))
		return (NULL);
	while ((res = get_next_line(fd, &line)) == 1 && fd > 0)
	{
		fdf->nbword[i] = ft_countwords(line, ' ');
		if (!(fdf->file[i] =
			(t_point*)malloc(sizeof(t_point) * (fdf->nbword[i]))))
			return (NULL);
		fdf->file[i] = ft_stock_data(fdf->file[i], i, fdf->nbword[i], line);
		free(line);
		i++;
	}
	fdf->max.x = fdf->file[i - 1][fdf->nbword[i - 1] - 2].x;
	fdf->max.y = fdf->file[i - 1][fdf->nbword[i - 1] - 2].y;
	fdf->max.z = fdf->file[i - 1][fdf->nbword[i - 1] - 2].z;
	close(fd);
	return (fdf->file);
}
