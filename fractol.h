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

# define WIDTH 700
# define HEIGHT 700
//# define SCALE 4 /*of coordinate system. if 6 it ranges from -3 to 3 */
# define MAX_ITERATIONS 100

typedef struct s_data
{
	void	*img;
	char	*addr;
	int	bits_per_pixel;
	int	line_length;
	int	endian;
}			t_data;

typedef struct s_fractol
{
	void	*mlx;
	void	*win;
	char	set;
	t_data	*img;
	double	cr;		/* real part of complex number c */
	double	ci;		/* imaginary part of complex number c */
	double	COO[2];		/* center of origin (O; Mittelpunkt: M) */
	double	scale[2];	/* O[0] & scale[0] are the reference points for x, ..[1] for y*/
}          t_fractol;	/* the scale for y has to be negative for the further calculations to be right*/


/* init.c */
void    init_zero(t_fractol *f);
void    init_var(t_fractol *f);
void    open_window(t_fractol *f, char *name);
void    my_pixel_put(t_data *img, int x, int y, int color);
void    init_img(t_fractol *f);

/*event_handling.c*/
int     deal_key(int key, t_fractol *f);
//int     deal_mouse(int button, int x, int y, void *param);
int     deal_mouse(int button, int x, int y, t_fractol *f);

/*image.c*/
void    my_pixel_put(t_data *img, int x, int y, int color);
int    complex_iteration(double zr, double zi, double cr, double ci);
double	conv_to_coord(double x, int i, t_fractol *f);
void    draw_image(t_fractol *f);
void    zoom(int button, int x, int y, t_fractol *f);

/*fractol.c*/
void	user_msg(void);
void	check_input(int argc, char **argv, t_fractol *f);

/*error_exit_handlings.c*/
int x_close(t_fractol *f);
void   close_window(t_fractol *f);
void    error_exit(t_fractol *f, char *message);

#endif
