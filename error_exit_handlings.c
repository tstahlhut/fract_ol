/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit_handlings.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <tstahlhu@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 10:43:16 by tstahlhu          #+#    #+#             */
/*   Updated: 2023/11/11 15:27:28 by tstahlhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	close_window(t_fractol *f)
{
	if (!f)
		return ;
	if (f->img)
	{
		mlx_destroy_image(f->mlx, f->img->img);
		free(f->img);
	}
	if (f->win && f->mlx)
	{
		mlx_clear_window(f->mlx, f->win);
		mlx_destroy_window(f->mlx, f->win);
	}
	if (f->mlx)
	{
		mlx_loop_end(f->mlx);
		mlx_destroy_display(f->mlx);
		free(f->mlx);
	}
	exit (0);
}

void	error_exit(t_fractol *f, char *message)
{
	ft_printf("Error:%s.\n", message);
	close_window(f);
	exit(1);
}
