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

# include "fractol.h"

/* 0x000000 (in RGB(0,0,0)) is 0 in integer
    0xFFFFFF (RGB(255, 255, 255)) is 16777215 in integer
    durch 255 = 65,793
    */

int palette(int i)
{
   // int color;

    //color = 0xFFFFFF;
  // color = 0xFF0000; /*pink*/
 
   /* */
    /* Mandelbrot: its contours */
    /* 
    }*/
     /* Mandelbrot: its contours with sprinkles*/
   /* else */
    /* Mandelbrot: Fireworks*/
    /*else if (i <= (MAX_ITERATIONS / 4))
        return (0xFFFFFF + i);
    else
        return (0xFFF0F0 - i * 16);*/
    /*else if (i <= (MAX_ITERATIONS / 3))
        return (0x0000FF + i);
    else if (i <= (MAX_ITERATIONS / 2))
        return (color / i * 16);
    else
        return (color + i * 255);*/
    /* Seventies */
   /* if (i >= MAX_ITERATIONS)
        return (0);
    else
        return (16777215 / MAX_ITERATIONS * i);*/
  /* else if (i < 15)
        return (0x0000FF + i); */
   /* else
        return (16777215 / MAX_ITERATIONS * i);*/
  return (i);
}

/* Colour palette for Mandelbrot:
    Traditionally, the pixels for which z = z^2 + c does not escape,
    are painted black. This is why the first if statement returns 0
    independently of the color that the user may choose.*/

unsigned int palette_M(t_fractol *f, unsigned int i)
{
   // if (i >= MAX_ITERATIONS)
   //     return (0x000000);
    if (f->palette == 0)
    { /*contours*/
        if (i <= (MAX_ITERATIONS / 3))
            return (f->color + i);
        else
            return (f->color + 16777215 / i);
    }
    else if(f->palette == 1)
    {/*contours with sprinkles*/
        if (i <= (MAX_ITERATIONS / 4))
            return (f->color + i);
        else
            return (f->color + 16777215 / i + i);
    }
    else if(f->palette == 2)
    {/*fireworks*/
        if (i <= (MAX_ITERATIONS / 4))
            return (0xFFFFFF + i);
        else
            return (0xFFF0F0 - i * 16);
    }
    else if (f->palette == 3)
    {
        if (i <= (MAX_ITERATIONS / 3))
            return (0x0000FF + i);
        else if (i <= (MAX_ITERATIONS / 2))
            return (f->color / i * 16);
        else
            return (f->color + i * 255);
    }
    else if (f->palette == 4)
       return (f->color + (f->div * i));
       // return (16777215 / MAX_ITERATIONS * i);

    else if (f->palette == 5)
    {
        if (i < 15)
            return (0x0000FF + i);
        else
            return (16777215 / MAX_ITERATIONS * i);
    }
    return (i);
}

/* palette for Julia sets best:
    in blue: return (i * 16)
    
    best julia sets
    -0,8 0.156
    -1 0.16
    0 0.8*/

unsigned int palette_J(t_fractol *f, unsigned int i)
{
    if (f->palette == 0)
    {
        if (i < 25)
            return (i);
        else
            return (i * 1000);
    }
    else if (f->palette == 1)
    {
        if (i < 15)
            return (f->color);
        return (f->color - f->div * i);
    }
    else if (f->palette == 2)
    {
        return (f->color + f->div * i + i);
    }
    return (i);
}
