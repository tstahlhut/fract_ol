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

void    init_var(t_fractol *f)
{
    init_zero(f);
    f->color = 0x000000;
    f->palette = 0;
    f->div = 1;
    f->cr = 0.0;
    f->ci = 0.0;
    f->COO[0] = (WIDTH - 1) / 2;
    f->COO[1] = (HEIGHT - 1) / 2;
    f->scale[0] = 4;
    f->scale[1] = -4;
    f->x = 0;
    f->y = 0;
}

void    init_set(char *str, t_fractol *f)
{
    if (!str ||  *str == '\0')
        user_msg();
    if (str[0] != '1' && str[0] != '2')
        user_msg();
    if (str[1] == '\0')
        f->set = str[0];
}

int    init_palette(char *str, t_fractol *f)
{
    if (!str ||  *str == '\0')
        user_msg();
    if (str[0] >= '0' && str[0] <= '5' && str[1] == '\0')
    {
        f->palette = str[0] - '0';
        return (1);
    }
    return (0);
}

int    init_color(char *str, t_fractol **f)
{
    if (!str ||  *str == '\0')
        user_msg();
    if (str[0] != '0' && str[1] != 'x')
        return (0);
    (*f)->color = ft_atox(str);
    printf("color: %d\n", (*f)->color);
    if ((*f)->color == 42)
    {
        (*f)->color = 0xFFFFFF;
        return (0);
    }
    (*f)->div = 0xFFFFFF / MAX_ITERATIONS; /*so that whole colour range is depicted*/
    return (1);
}

int init_c(char *str1, char *str2, t_fractol *f)
{
    double  x;
    double  y;

    if (!str1 || !str2 || *str1 == '\0' || *str2 == '\0')
		user_msg();
    x = ft_atod(str1);
    y = ft_atod(str2);
    if (x < -2.0 || x > 2.0 || y < -2.0 || y > 2.0)
    {
        f->ci = 0.8;
        return (0);
    }
    else
    {
        f->cr = x;
        f->ci = y;
    }
    return (2);
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
    draw_image(f);                                                  
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
    init_img(f);
    mlx_key_hook(f->win, deal_key, f);
    mlx_mouse_hook(f->win, deal_mouse, f);
    mlx_hook(f->win, 17, 0L, x_close, f);
    mlx_loop(f->mlx);
	//mlx_pixel_put(set->mlx, set->win, 250, 250, 0xFFFFFF);
	//mlx_key_hook(set->win, deal_key, set);
	//mlx_loop(set->mlx);
}