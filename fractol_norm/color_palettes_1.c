/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_palettes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 17:00:54 by tstahlhu          #+#    #+#             */
/*   Updated: 2023/10/27 17:01:06 by tstahlhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/* The colors range between:
	(0,0,0) in RGB - 0x000000 in hex -  0 in decimal and
	(255, 255, 255) in RGB - 0xFFFFFF in hex - 16777215 in decimal */

/* palette_M: Colour palette for Mandelbrot
	Traditionally, the pixels for which z = z^2 + c does not escape,
	are painted black. This is why the first if statement returns 0
	independently of the color that the user may choose.
	palette 0: blue green
	palette 1: pink
	palette 2: yellow
	palette 3:
	palette 4:
	palette 5: takes a color from the user */

unsigned int	palette_5(t_fractol *f, unsigned int i)
{
	if (f->color > 0x7FFFFF)
	{
		if (i <= (MAX_ITERATIONS / 10))
			return (f->color - i * 20);
		else
			return (f->color - (f->color / 10000 * i));
	}
	else if (f->color <= 0x7FFFFF)
	{
		if (i <= (MAX_ITERATIONS / 10))
			return (f->color + i * 20);
		else
			return (f->color + ((0xFFFFFF - f->color) / 1000 * i));
	}
	return (i);
}

unsigned int	color_palette(t_fractol *f, unsigned int i)
{
	unsigned int	color;

	if (f->set == 'M' && i >= MAX_ITERATIONS)
		return (0x000000);
	else if (f->palette == 0)
		color = palette_0(i);
	else if (f->palette == 1)
		color = palette_1(i, f);
	else if (f->palette == 2)
		color = palette_2(i);
	else if (f->palette == 3)
		color = palette_3(i, f);
	else if (f->palette == 4)
		color = palette_4(i, f);
	else if (f->palette == 5)
		color = palette_5(f, i);
	else
		color = f->color;
	return (color);
}
