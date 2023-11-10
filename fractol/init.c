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
    f->color = 0xFFFFFF;
    f->palette = 0;
    f->div = 1;
    f->cr = 0.0;
    f->ci = 0.0;
    f->COO[0] = (WIDTH - 1) / 2;
    f->COO[1] = (HEIGHT - 1) / 2;
    f->ratio[0] = (WIDTH - 1) / SCALE;
    f->ratio[1] = (HEIGHT - 1) / SCALE;
    f->move = ((HEIGHT + WIDTH) / 2) / 10;
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
