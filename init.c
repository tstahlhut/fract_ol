/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <tstahlhu@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 12:01:59 by tstahlhu          #+#    #+#             */
/*   Updated: 2023/10/16 12:02:10 by tstahlhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void    init_zero(t_fractol *f)
{
    f->mlx = NULL;
    f->win = NULL;
    f->img = NULL;
}

/*init_img inspired by 
https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html*/

void    init_img(t_fractol *f)
{
    f->img = malloc(sizeof(t_data));
    f->img->img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
    if (!f->img->img)
        close_window(f);
    f->img->addr = mlx_get_data_addr(f->img->img, &f->img->bits_per_pixel, &f->img->line_length, 
                                                            &f->img->endian);
    if (!f->img->addr)
        close_window(f); 
    draw_image(f->img);                                                  
    mlx_put_image_to_window(f->mlx, f->win, f->img->img, 0, 0);
}

/* mlx_init is used to establish a connection to the graphical server.
 * It returns void* which is needed by mlx_new_window.
 * mlx_new_window returns a void*. Thus, you can open several windows. 
 * mlx_key_hook handles the keyboard input
 * mlx_mouse_hook handles the mouse input
 * mlx_hook with the hooking event code 17 (ON_DESTROY) handles the closing
 * of the window when the cross is clicked
 * info: https://harm-smits.github.io/42docs/libs/minilibx/events.html*/

void	open_window(t_fractol *f, char *name)
{
	f->mlx = mlx_init();
    if (!f->mlx)
        error_exit(f, "connection to X-Server failed to establish");
    f->win = mlx_new_window(f->mlx, WIDTH, HEIGHT, name);
    if (!f->win)
        error_exit(f, "new window failed to open");
    mlx_key_hook(f->win, deal_key, f);
    mlx_mouse_hook(f->win, deal_mouse, f);
    mlx_hook(f->win, 17, 0L, x_close, f);
    init_img(f);
    mlx_loop(f->mlx);
	//mlx_pixel_put(set->mlx, set->win, 250, 250, 0xFFFFFF);
	//mlx_key_hook(set->win, deal_key, set);
	//mlx_loop(set->mlx);
}