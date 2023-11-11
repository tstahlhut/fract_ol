/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <tstahlhu@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 10:45:26 by tstahlhu          #+#    #+#             */
/*   Updated: 2023/10/20 13:17:16 by tstahlhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include "ft_printf.h"
# include <unistd.h> /*write*/
# include <stdlib.h> /*exit*/
# include <math.h>
# include "key_codes.h"

# define WIDTH 900
# define HEIGHT 900
# define SCALE 4 /*of coordinate system. if 6 it ranges from -3 to 3 */
# define MOVE 70
# define MAX_ITERATIONS 100

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

typedef struct s_fractol
{
	void			*mlx;
	void			*win;
	char			set;
	t_data			*img;
	unsigned int	color;
	int				palette;
	unsigned int	div;
	double			cr;		/* real part of complex number c */
	double			ci;		/* imaginary part of complex number c */
	double			COO[2];		/* center of origin (O; Mittelpunkt: M) */
	double			ratio[2];	/* CoO[0] & ratio[0] are the reference points for x, ..[1] for y*/
	double			move;
	int				x;			/* mouse position */
	int				y;
}          t_fractol;	/* the scale for y has to be negative for the further calculations to be right*/


/* init.c */
void    init_zero(t_fractol *f);
void    init_var(t_fractol *f);
void    open_window(t_fractol *f, char *name);
void    init_img(t_fractol *f);
void    init_set(char *str, t_fractol *f);
int    init_palette(char *str, t_fractol *f);
int    init_color(char *str, t_fractol **f);
int init_c(char *str1, char *str2, t_fractol *f);

/*event_handling.c*/
int     deal_key(int key, t_fractol *f);
//int     deal_mouse(int button, int x, int y, void *param);
int     deal_mouse(int button, int x, int y, t_fractol *f);

/*image.c*/
void    my_pixel_put(t_data *img, int x, int y, unsigned int color);
unsigned int    complex_iteration(double zr, double zi, double cr, double ci);
double	conv_to_coord(double x, int i, t_fractol *f);
void    draw_image(t_fractol *f);
void    zoom(int button, int x, int y, t_fractol *f);

/*color_palettes.c*/
unsigned int palette_M(t_fractol *f, unsigned int i);
unsigned int palette_J(t_fractol *f, unsigned int i);

/*fractol.c*/
void	user_msg(void);
void	check_input(int argc, char **argv, t_fractol *f);

/*error_exit_handlings.c*/
int x_close(t_fractol *f);
void   close_window(t_fractol *f);
void    error_exit(t_fractol *f, char *message);

/*utils.c*/
unsigned int ft_atox(char *str);
double	ft_atod(char *str);
#endif
