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

/* inspired by: https://users.math.yale.edu/public_html/People/
    frame/Fractals/MandelSet/ComplexIteration/ComplexIterEx.html */

int    complex_iteration(double zr, double zi, double cr, double ci)
{
    int i;

    i = -1;
    while (++i < MAX_ITERATIONS)
    {
        zr = pow(zr, 2) - pow(zi, 2) + cr;
        zi = 2 * zr * zi + ci;
        if (-2 > zr || zr > 2 || -2 > zi || zi > 2)
            break ;
    }
    /*if (i < MAX_ITERATIONS)
    	i = i + 2 - log(log(pow(zr, 2) + pow(zi, 2))) / log(2);*/
    return (i);
}

void    my_pixel_put(t_data *img, int x, int y, int color)
{
    char    *dst;

    dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

double	conv_to_coord(double x)
{
	double	z;
	double	centre;
	double	ratio;

	centre = (WIDTH - 1) / 2;
	ratio = (WIDTH - 1) / SCALE;
	z = (x - centre) / ratio;
	return (z);
}

void    draw_image(t_data *img)
{
    double x;
    double y;
    double i;

    x = -1;
    while (++x <= WIDTH)
    {
        y = -1;
        while (++y <= HEIGHT)
        {
            i = complex_iteration(conv_to_coord(x), conv_to_coord(y), -1, 0.16);
            if (i == MAX_ITERATIONS)
                 my_pixel_put(img, x, y, 0x00000000);
            else
                my_pixel_put(img, x, y, (0x0000FF00 + i));
        }
    }
    /*x = -1;
    while (++x <= WIDTH)
    {
        y = -1;
        while (++y <= HEIGHT)
            my_pixel_put(img, x, y, (0x0000FF00 + y / 2));
    }*/
}

