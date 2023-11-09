/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <tstahlhu@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 10:44:46 by tstahlhu          #+#    #+#             */
/*   Updated: 2023/10/13 15:23:53 by tstahlhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


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
	printf("%c %f %f", f.set, f.cr, f.ci);
	open_window(&f, "Fractol"); // vielleicht anpassen, je nachdem welches set. Koennte in struct gespeichert sein.
	return (0);
}
