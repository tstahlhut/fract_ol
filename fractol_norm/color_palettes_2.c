/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_palettes_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <tstahlhu@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 12:47:38 by tstahlhu          #+#    #+#             */
/*   Updated: 2023/11/12 12:47:55 by tstahlhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/* palette_0: This color palette displays the fractals in blue green
	and is the same for the Mandelbrot and Julia set.
	Be aware that a change of MAX_ITERATIONS influences the coloring
	because it is dependent on the number of iterations (i).*/

unsigned int	palette_0(unsigned int i)
{
	if (i <= (MAX_ITERATIONS / 10))
		return (0x0000FF + i * 1000);
	else
		return (0xFFFFFF / i);
}

/* palette_1: This color palette displays the fractals in pink. */

unsigned int	palette_1(unsigned int i, t_fractol *f)
{
	if (i > (MAX_ITERATIONS / 10))
		return (0xFFFFFF - 10485 * i);
	else if (f->set == 'M')
		return (0xF00000 + i * 1000);
	else
		return (0xFF00FF + i * 1000);
}

/* palette_2: This color palette displays the fractals in yellow. 
	It is the same for the Mandelbrot and Julia set.*/

unsigned int	palette_2(unsigned int i)
{
	if (i <= (MAX_ITERATIONS / 10))
		return (0xFFF000 + i * 20);
	else
		return (0xF00000 + 10485 * i);
}

unsigned int	palette_3(unsigned int i, t_fractol *f)
{
	if (f->set == 'M')
		return (0x5FFFFF - 10000 * i);
	else if (i <= (MAX_ITERATIONS / 10))
		return (0x0000FF + i * 1000);
	else
		return (0xFFFFFF - 10485 * i);
}

unsigned int	palette_4(unsigned int i, t_fractol *f)
{
	if (f->set == 'M')
		return (0xFFFFFF / 10000 * i);
	else if (i <= (MAX_ITERATIONS / 10))
		return (0xFFF000 + i * 20);
	else
		return (0xFFFFFF / 1000 * i);
}
