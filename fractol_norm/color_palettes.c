/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_palettes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 17:00:54 by tstahlhu          #+#    #+#             */
/*   Updated: 2023/11/11 16:46:04 by tstahlhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fractol.h"

/* The colors range between:
    (0,0,0) in RGB - 0x000000 in hex -  0 in decimal and
    (255, 255, 255) in RGB - 0xFFFFFF in hex - 16777215 in decimal */

/* palette_M: Colour palette for Mandelbrot
    Traditionally, the pixels for which z = z^2 + c does not escape,
    are painted black. This is why the first if statement returns 0
    independently of the color that the user may choose.
    palette 0: blue and blue green contours with sprinkles
    palette 1: pink
    palette 2: yellow
    palette 3:
    palette 4:
    palette 5: takes a color from the user */

unsigned int palette_m(t_fractol *f, unsigned int i)
{
   if (i >= MAX_ITERATIONS)
        return (0x000000);
if (f->palette == 3)
    return (0x5FFFFF - 10000 * i);
if (f->palette == 4)
    return (0xFFFFFF / 10000 * i);
if (i <= (MAX_ITERATIONS / 10))
{
    if(f->palette == 0)
        return (0x0000FF + i * 1000);
    else if(f->palette == 1)
        return (0xF00000 + i * 1000);
    else if (f->palette == 2)
        return (0xFFF000 + i * 20);
}
if(f->palette == 0)
    return (0xFFFFFF / i);
else if(f->palette == 1)
    return (0xFFFFFF - 10485 * i);
else if (f->palette == 2)
    return (0xF00000 + 10485 * i);
   else if(f->palette == 0)
    {/*blue: blue green contours with sprinkles*/
        if (i <= (MAX_ITERATIONS / 10))
            return (0x0000FF + i * 1000);
        else
            return (0xFFFFFF / i);
    }
    else if(f->palette == 1)
    {/*pink */
      if (i <= (MAX_ITERATIONS / 10))
          return (0xF00000 + i * 1000);
       else
            return (0xFFFFFF - 10485 * i);
    }
    else if (f->palette == 2)
     {/*yellow */
      if (i <= (MAX_ITERATIONS / 10))
          return (0xFFF000 + i * 20);
       else
            return (0xF00000 + 10485 * i);
    }
    
    else if (f->palette == 5)
    {
        if (f->color > 0x7FFFFF)
            return (f->color - (f->color / 1000 * i));
       else
            return (f->color + (f->color / 1000 * i));
    }
    return (i);
}

unsigned int palette_j(t_fractol *f, unsigned int i)
{
   if(f->palette == 0)
    {/* blue green*/
        if (i <= (MAX_ITERATIONS / 10))
            return (0x0000FF + i * 1000);
        else
            return (0xFFFFFF / i);
    }
    else if(f->palette == 1)
    {/*pink */
      if (i <= (MAX_ITERATIONS / 10))
          return (0xFF00FF + i * 1000);
       else
            return (0xFFFFFF - 10485 * i);
    }
    else if (f->palette == 2)
     {/*yellow */
      if (i <= (MAX_ITERATIONS / 10))
          return (0xFFF000 + i * 20);
       else
            return (0xF00000 + 10485 * i);
    }
    else if (f->palette == 3)
    {
         if (i <= (MAX_ITERATIONS / 10))
            return (0x0000FF + i * 1000);
        else
            return (0xFFFFFF - 10485 * i);
    }
    else if (f->palette == 4)
    {
        if (i <= (MAX_ITERATIONS / 10))
            return (0xFFF000 + i * 20);
        else
            return (0xFFFFFF / 1000 * i);
    }
    else if (f->palette == 5)
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
    }
    return (i);
}
