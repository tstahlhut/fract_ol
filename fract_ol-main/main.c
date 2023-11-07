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





int	main(int argc, char **argv)
{
	t_fractol	f;

	init_var(&f);
	check_input(argc, argv, &f);
	printf("%c %f %f", f.set, f.cr, f.ci);
	open_window(&f, "Fractol"); // vielleicht anpassen, je nachdem welches set. Koennte in struct gespeichert sein.
	return (0);
}
