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

int	x_close(t_fractol *f)
{
	close_window(f);
	return (0);
}

int	deal_key(int key, t_fractol *f)
{
	if (key == 0xff1b)
		close_window(f);
	if (key == 43)
	{
		f->scale[0] *= 0.9;
        f->scale[1] *= 0.9;
		mlx_clear_window(f->mlx, f->win);
    	draw_image(f);
	}
	if (key == 45)
	{
		f->scale[0] /= 0.9;
        f->scale[1] /= 0.9;
		mlx_clear_window(f->mlx, f->win);
    	draw_image(f);
	}
	else
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