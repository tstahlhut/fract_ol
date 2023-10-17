/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <tstahlhu@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 11:45:17 by tstahlhu          #+#    #+#             */
/*   Updated: 2023/10/17 11:46:01 by tstahlhu         ###   ########.fr       */
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
            return (i);
    }
    return (i);
}

void    my_pixel_put(t_data *img, int x, int y, int color)
{
    char    *dst;

    dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

void    draw_image(t_data *img)
{
    double x;
    double y;
    double a;
    double b;
    double i;

    a = (WIDTH - 1) / 2;
    b = (HEIGHT - 1) / 2;
    x = -1;
    while (++x <= WIDTH)
    {
        y = -1;
        while (++y < HEIGHT)
        {
            i = complex_iteration((x - a), (y - b), -0.5, 0.3);
            if (i == MAX_ITERATIONS)
                 my_pixel_put(img, x, y, 0x00000000);
            else
                my_pixel_put(img, x, y, 0x00FFFF00);
        }
    }
   /* x = -1;
    while (++x <= WIDTH)
    {
        y = -1;
        while (++y <= HEIGHT)
            my_pixel_put(img, x, y, (0x0000FF00 + y / 2));
    }*/
}

