/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <tstahlhu@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 11:45:17 by tstahlhu          #+#    #+#             */
/*   Updated: 2023/10/18 15:06:39 by tstahlhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/* In order to zoom in or out, the image is newly created. Two parametres have
    to be changed: COO and scale. The new COO (center/ coordinate of origin) 
    is shifted accoring to the mouse position captured in "deal_mouse". 
    By manipulating the scale the illusion of zooming is given. */

void    zoom(int button, int x, int y, t_fractol *f)
{
   // f->COO[0] = f->COO[0] + (f->COO[0] - x);
	//f->COO[1] = f->COO[1] + (f->COO[1] - y);
   // f->COO[0] = x;
    //f->COO[1] = y;
    ft_printf("x = %i, y = %i", x, y);
    if (button == 4)
	{
        f->scale[0] *= 0.9;
        f->scale[1] *= 0.9;
    }
    if (button == 5)
    {
        f->scale[0] /= 0.9;
        f->scale[1] /= 0.9;
    }
  //  mlx_destroy_image(f->mlx, f->img->img);
    //free(f->img);
    mlx_clear_window(f->mlx, f->win);
    draw_image(f);
}

/* inspired by: https://users.math.yale.edu/public_html/People/
    frame/Fractals/MandelSet/ComplexIteration/ComplexIterEx.html */
/* unoptimized escape time algorithm
      while (i < MAX_ITERATIONS)
    {
        zr_temp = pow(zr, 2) - pow(zi, 2) + cr;
        zi = 2 * zr * zi + ci;
        zr = zr_temp;
        if (-2 > zr || zr > 2 || -2 > zi || zi > 2)
            return (i) ;
        i++;
    }
    optimized escape time algorithm found on:
    https://en.wikipedia.org/wiki/Plotting_algorithms_for_the_Mandelbrot_set */

unsigned int    complex_iteration(double zr, double zi, double cr, double ci)
{
    unsigned int i;
    double zr2;
    double zi2;

    zr2 = zr;
    zi2 = zi;
    i = 0;
    while (zr + zi <= 4 && i < MAX_ITERATIONS)
    {
        zi = 2 * zr * zi + ci;
        zr = zr2 - zi2 + cr;
        zr2 = zr * zr;
        zi2 = zi * zi;
        i++;
    }
    return (i);
}

unsigned int    complex_iteration_M(double zr, double zi, double cr, double ci)
{
    int i;
    double zr2;
    double zi2;

    zr2 = 0;
    zi2 = 0;
    i = 0;
    while (zr + zi <= 4 && i < MAX_ITERATIONS)
    {
        zi = 2 * zr * zi + ci;
        zr = zr2 - zi2 + cr;
        zr2 = zr * zr;
        zi2 = zi * zi;
        i++;
    }
    return (i);
}

unsigned int    complex_iteration_J(double zr, double zi, double cr, double ci)
{
    unsigned int i;
    double zr_temp;

    i = 0;
    while (i < MAX_ITERATIONS)    
    {
      /*    zr_temp = pow(zr, 2) - pow(zi, 2) + cr;
        zi = 2 * zr * zi + ci;
        zr = zr_temp;
        if (-2 > zr || zr > 2 || -2 > zi || zi > 2)
            return (i) ;
        i++;*/
        zr_temp = zr * zr - zi * zi;
        zi = 2 * zr * zi + ci;
        zr = zr_temp + cr;
        if (-2 > zr || zr > 2 || -2 > zi || zi > 2)
            return (i) ;
        i++;
    }
    return (i);
}

void    my_pixel_put(t_data *img, int x, int y, unsigned int color)
{
    char    *dst;

    dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

double	conv_to_coord(double x, int i, t_fractol *f)
{
	double	z;
	double	ratio;

	ratio = (WIDTH - 1) / f->scale[i];                                            
	z = (x - f->COO[i]) / ratio;
    //printf("c = %f, z = %f", x, z);
	return (z);
}

void    draw_image(t_fractol *f)
{
    double x;
    double y;
    unsigned int i;

    x = -1;
    while (++x < WIDTH)
    {
        y = -1;
        while (++y < HEIGHT)
        {
           // printf("\n\nx = %f  y = %f\n", x, y);
         //   zr = conv_to_coord(x, 0, f);
           // zi = conv_to_coord(y, 1, f);
            //i = complex_iteration(zr, zi, f);
            if (f->set == '1')
            {
                i = complex_iteration(0, 0, conv_to_coord(x, 0, f), conv_to_coord(y, 1, f));
                my_pixel_put(f->img, x, y, palette_M(f, i));
            }
            else if (f->set == '2')
             {
                i = complex_iteration_J(conv_to_coord(x, 0, f), conv_to_coord(y, 1, f), f->cr, f->ci);
                my_pixel_put(f->img, x, y, palette_J(f, i));
             }
            else
                error_exit(f, "Set not valid\n");
            }
    }
    mlx_put_image_to_window(f->mlx, f->win, f->img->img, 0, 0);
    /*x = -1;
    while (++x <= WIDTH)
    {
        y = -1;
        while (++y <= HEIGHT)
            my_pixel_put(img, x, y, (0x0000FF00 + y / 2));
    }*/
}

