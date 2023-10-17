/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <tstahlhu@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 10:45:26 by tstahlhu          #+#    #+#             */
/*   Updated: 2023/10/13 15:18:25 by tstahlhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
#define FRACTOL_H

# include "mlx.h"
# include "ft_printf.h"
# include <unistd.h> /*write*/
# include <stdlib.h> /*exit*/
# include <math.h>

# define WIDTH 5
# define HEIGHT 5
# define MAX_ITERATIONS 1000

typedef struct s_data
{
    void    *img;
    char    *addr;
    int     bits_per_pixel;
    int     line_length;
    int     endian;
}           t_data;

typedef struct s_fractol
{
    void    	*mlx;
	void    	*win;
    t_data   *img;
}          t_fractol;




/* init.c */
void    init_zero(t_fractol *f);
void    open_window(t_fractol *f, char *name);
void    my_pixel_put(t_data *img, int x, int y, int color);
void    init_img(t_fractol *f);

/*event_handling.c*/
int     deal_key(int key, void *param);
int     deal_mouse(int button, int x, int y, void *param);

/*image.c*/
void    my_pixel_put(t_data *img, int x, int y, int color);
int    complex_iteration(double zr, double zi, double cr, double ci);
void    draw_image(t_data *img);

/*fractol.c*/
/*error_exit_handlings.c*/
int x_close(t_fractol *f);
void   close_window(t_fractol *f);
void    error_exit(t_fractol *f, char *message);

#endif
