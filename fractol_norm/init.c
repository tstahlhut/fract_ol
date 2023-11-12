/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <tstahlhu@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 12:01:59 by tstahlhu          #+#    #+#             */
/*   Updated: 2023/11/11 15:22:31 by tstahlhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/* init_var: The variables of struct fractol are initialized.*/
void	init_var(t_fractol *f)
{
	f->mlx = NULL;
	f->win = NULL;
	f->img = NULL;
	f->color = 0xFFFFFF;
	f->palette = 0;
	f->cr = 0.0;
	f->ci = 0.0;
	f->coo[0] = (WIDTH - 1) / 2;
	f->coo[1] = (HEIGHT - 1) / 2;
	f->ratio[0] = (WIDTH - 1) / SCALE;
	f->ratio[1] = (HEIGHT - 1) / SCALE;
	f->move = ((HEIGHT + WIDTH) / 2) / 10;
	f->x = 0;
	f->y = 0;
}

void	init_set(char *str, t_fractol *f)
{
	if (!str || *str == '\0')
		user_msg();
	if (str[0] != 'M' && str[0] != 'J')
		user_msg();
	if (str[1] == '\0')
		f->set = str[0];
	else
		user_msg();
}

int	init_palette(char *str, t_fractol *f)
{
	if (!str || *str == '\0')
		user_msg();
	if (str[0] >= '0' && str[0] <= '5' && str[1] == '\0')
	{
		f->palette = str[0] - '0';
		return (1);
	}
	else
		user_msg();
	return (0);
}

int	init_color(char *str, t_fractol **f)
{
	if (!str || *str == '\0')
		user_msg();
	if (str[0] != '0' && str[1] != 'x')
		user_msg();
	(*f)->color = ft_atox_color(str + 2);
	if ((*f)->color == 0x1000000)
	{
		user_msg();
		return (0);
	}
	return (1);
}

int	init_c(char *str1, char *str2, t_fractol *f)
{
	double	x;
	double	y;

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
