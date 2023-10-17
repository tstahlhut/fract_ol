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


int	main()
{
	t_fractol	f;
	
	init_zero(&f);
	open_window(&f, "Fractol"); // vielleicht anpassen, je nachdem welches set. Koennte in struct gespeichert sein.
	return (0);
}
