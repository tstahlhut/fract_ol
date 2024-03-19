/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <tstahlhu@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 10:44:46 by tstahlhu          #+#    #+#             */
/*   Updated: 2023/11/11 15:47:47 by tstahlhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*init_img inspired by 
https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html*/

void	init_img(t_fractol *f)
{
	f->img = malloc(sizeof(t_data));
	f->img->img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	if (!f->img->img)
		close_window(f);
	f->img->addr = mlx_get_data_addr(f->img->img, &f->img->bits_per_pixel,
			&f->img->line_length, &f->img->endian);
	if (!f->img->addr)
		close_window(f);
	draw_image(f);
}

/* open_window: This function opens the window, hooks are set and loops until
	the window is closed.
	mlx_init is used to establish a connection to the graphical server.
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
	init_img(f);
	mlx_key_hook(f->win, deal_key, f);
	mlx_mouse_hook(f->win, deal_mouse, f);
	mlx_hook(f->win, 17, 0L, x_close, f);
	mlx_loop(f->mlx);
}

int	main(int argc, char **argv)
{
	t_fractol	f;

	init_var(&f);
	check_input(argc, argv, &f);
	open_window(&f, "Fractol");
	return (0);
}
