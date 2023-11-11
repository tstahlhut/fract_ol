/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <tstahlhu@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:14:39 by tstahlhu          #+#    #+#             */
/*   Updated: 2023/10/16 14:14:48 by tstahlhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/* In order to zoom in or out, the image is newly created. Two parametres have
    to be changed: COO and scale. The new COO (center/ coordinate of origin) 
    is shifted accoring to the mouse position captured in "deal_mouse". 
    By manipulating the scale the illusion of zooming is given. */

void    zoom(int button, int x, int y, t_fractol *f)
{
   if (button == 4)
	{
		f->COO[0] += (f->COO[0] - x);
		f->COO[1] += (f->COO[1] - y);
		f->ratio[0] *= 2;
        f->ratio[1] *= 2;
		/*f->COO[0] += ((f->COO[0] - x) * 0.5);
		f->COO[1] += ((f->COO[1] - y) * 0.5);
        f->ratio[0] *= 1.5;
        f->ratio[1] *= 1.5;*/
    }
    if (button == 5)
    {
		f->COO[0] -= ((f->COO[0] - x) / 2);
		f->COO[1] -= ((f->COO[1] - y) / 2);
        f->ratio[0] /= 2;
        f->ratio[1] /= 2;
    }
    mlx_clear_window(f->mlx, f->win);
    draw_image(f);
}

/* x_close: This function closes the window with a MLX function. */

int	x_close(t_fractol *f)
{
	close_window(f);
	return (0);
}

/* deal_key: This function handles key events (when the keyboard is pressed).
	If ESC (0xff1b) is pressed, the window is closed.
	If + is pressed, it zooms in by enhancing the ratio and drawing a new
	image.
	if - is pressed, it zooms out by decreasing the ratio and drawing a new
	image. */

int	deal_key(int key, t_fractol *f)
{
	if (key == KEY_ESC)
		close_window(f);
	if (key == KEY_PLUS)
	{
		f->ratio[0] *= 2;
        f->ratio[1] *= 2;
		f->COO[0] += (f->COO[0] - ((WIDTH - 1) / 2));
		f->COO[1] += (f->COO[1] - ((HEIGHT - 1) / 2));
		mlx_clear_window(f->mlx, f->win);
    	draw_image(f);
	}
	if (key == KEY_MINUS)
	{
		f->ratio[0] /= 2;
        f->ratio[1] /= 2;
		f->COO[0] -= ((f->COO[0] - ((WIDTH - 1) / 2)) / 2);
		f->COO[1] -= ((f->COO[1] - ((HEIGHT - 1) / 2)) / 2);
		mlx_clear_window(f->mlx, f->win);
    	draw_image(f);
	}
	if (key == KEY_LEFT)
	{
		f->COO[0] += f->move;
		mlx_clear_window(f->mlx, f->win);
    	draw_image(f);
	}
	if (key == KEY_RIGHT)
	{
		f->COO[0] -= f->move;
		mlx_clear_window(f->mlx, f->win);
    	draw_image(f);
	}
	if (key == KEY_UP)
	{
		f->COO[1] += f->move;
		mlx_clear_window(f->mlx, f->win);
    	draw_image(f);
	}
	if (key == KEY_DOWN)
	{
		f->COO[1] -= f->move;
		mlx_clear_window(f->mlx, f->win);
    	draw_image(f);
	}
	printf("C00: %f\n ratio: %f\n", f->COO[0], f->ratio[0]);
	ft_printf("keyboard toched: %i\n", key);
	return (0);	
}

/* deal_mouse: This function handles the mouse events.
	Buttons have been assigned in minilibx:
	button 4: mouse wheel moves forward
	button 5: mouse wheel moves backward 
	button 6: mouse moves */

int     deal_mouse(int button, int x, int y, t_fractol *f)//void *param)
{
    ft_printf("button: %i | x = %i | y =%i\n", button, x, y);
	printf("x = %f, y = %f\n", conv_to_coord(x, 0, f), conv_to_coord(y, 1, f));
	if (button == 4 || button == 5)		
		zoom(button, x, y, f);
	if (button == 1)
	{
		/*f->cr = x;
		f->ci = y;
		mlx_clear_window(f->mlx, f->win);
    	draw_image(f);*/
		mlx_mouse_get_pos(f->mlx, f->win, &f->x, &f->y);
		f->cr = conv_to_coord(f->x, 0, f);
		f->ci = conv_to_coord(f->y, 1, f);
		mlx_clear_window(f->mlx, f->win);
   		draw_image(f);
	}
    return (0);
}