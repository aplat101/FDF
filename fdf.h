/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fdf.h                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aplat <aplat@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/19 16:36:52 by aplat        #+#   ##    ##    #+#       */
/*   Updated: 2019/05/29 23:53:35 by aplat       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "minilibx_macos/mlx.h"
# include "libft/libft.h"
# include "key_map_macos.h"
# include "info.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>

# define WD 1920
# define HH 1080
# define POST (WD * 0.8)
# define WDI (POST + 5)
# define TIN (WD * 0.2)
# define RED 16711680
# define WHITE 16777215
# define TETA (M_PI / 6)

typedef struct	s_proj
{	int			proj_x;
	int			proj_y;
}				t_proj;

typedef	struct	s_point
{
	double		x;
	double		y;
	double		z;
	int			color_f;
	int			color_g;
}				t_point;

typedef struct	s_fdf
{
	void		*mlx_ptr;
	void		*mlx_window;
	void		*img_ptr;
	void		*img_info;
	int			*img;
	int			*info;
	int			nbline;
	int			*nbword;
	t_point		**file;
	t_point		**iso;
	t_point		**para;
	int			mode_proj;
	int			mode_color;
	t_proj		proj[2];
	double		zoom[2];
	double		ele[2];
	t_point		max;
	t_point		max_i;
	t_point		max_p;
	int			single_c[2];
	int			zmax;
	int			color_min;
	int			color_max;
}				t_fdf;

/*
** Fonctions de Gestion d'erreurs liées aux arguments et Files Descriptors
*/

void			ft_one_arg(void);
void			ft_existing_arg(int fd);
void			ft_valid_arg(int fd);
void			ft_checkerror(int ac, char **av, t_fdf *fdf);

/*
** Fonctions de Check de validité du fichier en paramètre
*/

int				ft_check_line_caract(char c);
int				ft_check_line_validity(int i, char *line);
int				ft_check_hexa(int c);
int				ft_check_line(char *line);
int				ft_check_validity(int fd);

/*
** Fonctions d'initialisation des valeurs utiles dans
** l'utilisation de la minilibx
** ainsi que des différentes fonctionnalités du programme
*/

void			ft_init_window(t_fdf *fdf);
void			ft_new_img(t_fdf *fdf);
void			ft_frame(t_fdf *fdf);
void			ft_fill_frame(t_fdf *fdf);
void			ft_interactive_fill(t_fdf *fdf);

void			ft_init_mlx(t_fdf *fdf);
void			ft_init_ele(t_fdf *fdf);
void			ft_init_proj(t_fdf *fdf);
void			ft_init_zoom(t_fdf *fdf);
void			ft_init_value(t_fdf *fdf);

/*
** Parsing du fichier et stockage des valeurs présentes dans celui-ci
*/

char			*ft_strnewzero(size_t size);
int				ft_converthexint(char *line, int power);
void			ft_check_data_color(t_point *file, int *j, char *line);
t_point			*ft_stock_data(t_point *file, int nbl, int nbword, char *line);
t_point			**ft_alloc_data(char *av, t_fdf *fdf);

/*
** Fonctions pour l'allocation des valeurs isometriques
*/

t_point			*ft_stock_iso(t_point **iso, int i, t_point **file, t_fdf *fdf);
t_point			**ft_alloc_iso(t_point **file, t_fdf *fdf);

/*
** Fonctions pour l'allocation des valeurs paralelles
*/

t_point			*ft_stock_para(t_point **para, int i,
					t_point **file, t_fdf *fdf);
t_point			**ft_alloc_para(t_point **file, t_fdf *fdf);

int				ft_check(t_point t1, t_point t2, t_fdf *fdf);
void			ft_take_zoom(t_point **p, t_fdf *fdf);
void			ft_print(t_fdf *fdf);
void			ft_draw(t_point **p, t_fdf *fdf);

/*
** Fonctions liees au tracage des differentes projections
*/

void			ft_get_cur(t_point *d, int i, t_point *t1, t_point *cur);
void			ft_calculate(t_point *t1, t_point *t2, t_fdf *fdf);
double			ft_percentage(t_point *d, t_point *t1,
					t_point *t2, t_point *cur);
void			ft_get_point_delta(t_point *d, int *nb_point);
void			ft_bresenham(t_point t1, t_point t2, t_fdf *fdf);

/*
** Fonctions liees au bind de certaines touches
*/

int				key_press(int keycode, t_fdf *fdf);
int				key_release(int keycode, t_fdf *fdf);
int				mouse_press(int button, int x, int y, t_fdf *fdf);

void			ft_adapt_zoom_side(t_fdf *fdf, int i);
void			ft_swap_proj(t_fdf *fdf);
void			ft_center(t_fdf *fdf);

/*
** Fonctions liees aux modifications et application du zoom
*/

void			ft_zoomm(t_fdf *fdf);
void			ft_zoomp(t_fdf *fdf);
void			ft_adapt_zoom_iso(t_fdf *fdf, int i, int j);
void			ft_adapt_zoom_para(t_fdf *fdf, int i, int j);
void			ft_adapt_zoom(t_fdf *fdf);

void			ft_para(t_fdf *fdf);
void			ft_iso_wd(t_fdf *fdf);
void			ft_iso_hh(t_fdf *fdf);
void			ft_center_middle_point(t_fdf *fdf, int i, int j);
void			ft_center_iso(t_fdf *fdf);

void			ft_inferior_para(t_fdf *fdf);
void			ft_superior_para(t_fdf *fdf);
void			ft_center_para(t_fdf *fdf);

void			ft_move_right(t_fdf *fdf);
void			ft_move_left(t_fdf *fdf);
void			ft_move_up(t_fdf *fdf);
void			ft_move_down(t_fdf *fdf);

void			ft_eledown(t_fdf *fdf);
void			ft_eleup(t_fdf *fdf);
void			ft_reset_ele(t_fdf *fdf);

void			ft_update_color(t_point **tp, t_fdf *fdf);
int				ft_get_color_g(t_fdf *fdf, t_point p);
int				get_light(int start, int end, double percentage);
void			ft_swap_color(t_fdf *fdf);
int				ft_get_color(t_fdf *fdf, double percent,
					t_point t1, t_point t2);

void			ft_colortoblack(t_fdf *fdf);
void			ft_colortowhite(t_fdf *fdf);

#endif
