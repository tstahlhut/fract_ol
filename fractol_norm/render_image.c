/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <tstahlhu@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 11:45:17 by tstahlhu          #+#    #+#             */
/*   Updated: 2023/11/11 16:57:59 by tstahlhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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

unsigned int	complex_iteration_m(double zr, double zi, double cr, double ci)
{
	unsigned int	i;
	double		zr2;
	double		zi2;
	
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

unsigned int	complex_iteration_j(double zr, double zi, double cr, double ci)
{
	unsigned int	i;
	double		zr_temp;
	
	i = 0;
	while (i < MAX_ITERATIONS)
	{
		zr_temp = zr * zr - zi * zi;
		zi = 2 * zr * zi + ci;
		zr = zr_temp + cr;
		if (-2 > zr || zr > 2 || -2 > zi || zi > 2)
			return (i);
		i++;
	}
	return (i);
}

void	my_pixel_put(t_data *img, int x, int y, unsigned int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

double	conv_to_coord(double x, int i, t_fractol *f)
{
	double	z;
	
	z = (x - f->COO[i]) / f->ratio[i];
	return (z);
}

void	draw_image(t_fractol *f)
{
	double		x;
	double		y;
	unsigned int	i;
       
	x = -1;
	while (++x < WIDTH)
	{
		y = -1;
		while (++y < HEIGHT)
		{
			if (f->set == '1')
			{
				i = complex_iteration_m(0, 0, conv_to_coord(x, 0, f),
						conv_to_coord(y, 1, f));
				my_pixel_put(f->img, x, y, palette_m(f, i));
			}
			else if (f->set == '2')
			{
				i = complex_iteration_j(conv_to_coord(x, 0, f),
						conv_to_coord(y, 1, f), f->cr, f->ci);
				my_pixel_put(f->img, x, y, palette_j(f, i));
			}
			else
				error_exit(f, "Set not valid\n");
		}
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img->img, 0, 0);
}
