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

int	deal_key(int key, void *param)
{
	if (key == 0xff1b)
		close_window((t_fractol*)param);
	else
		ft_printf("keyboard toched: %i\n", key);
	return (0);	
}

int     deal_mouse(int button, int x, int y, void *param)
{
    ft_printf("button: %i | x = %i | y =%i\n", button, x, y);
    ft_printf("param: %p\n", param);
    return (0);
}