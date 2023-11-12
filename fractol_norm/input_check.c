/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 14:57:59 by tstahlhu          #+#    #+#             */
/*   Updated: 2023/10/28 14:58:07 by tstahlhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	user_msg(void)
{
	ft_printf("How to use fractol - Explanation of parameters\n");
	ft_printf("Mandatory (1):\n");
	ft_printf("[SET] (1):\n");
	ft_printf("\tM - for Mandelbrot set\n");
	ft_printf("\tJ - for Julia set\n\n");
	ft_printf("Optional (2-5):\n");
	ft_printf("\t[C] (2 & 3): Only available for Julia set\n");
	ft_printf("\t\tEnter complex number c as two decimals (cr & ci)");
	ft_printf("each ranging from -2.0 to 2.0.\n");
	ft_printf("\t\tDefault: 0 0.8\n\n");
	ft_printf("\t[COLOR PALETTE] (4): Change the color palette\n");
	ft_printf("\t\tEnter integer 0 to 5 to choose color palette\n");
	ft_printf("\t\tDefault: 0\n\n");
	ft_printf("\t[COLOR] (5): ");
	ft_printf("If you chose palette 5, you can choose a color, too\n");
	ft_printf("\t\tEnter a color in hex from 0x000000 to 0xFFFFFF\n");
	ft_printf("\t\tDefault: 0xFFFFFF\n\n");
	ft_printf("Input example: ./fractol J -1.0 0.16 5 0xFF0000\n\n");
	exit (0);
}

/*void	check_input(int argc, char **argv, t_fractol *f)
{
	if (argc == 2 && argv[1][1] == '\0')
	{
		if (argv[1][0] == '1' || argv[1][0] == '2')
		{
			f->set = argv[1][0];
			return ;
		}
	}
	if (argc == 4 && *argv[1] == '2')
	{
		f->set = argv[1][0];
		f->cr = ft_atod(argv[2]);
		printf("cr = %f\n", f->cr);
		f->ci = ft_atod(argv[3]);
		printf("ci = %f\n", f->ci);
		return ;
	}
	else
		user_msg();	
}*/

void	check_input(int argc, char **argv, t_fractol *f)
{
	int	i;

	i = 2;
	if (argc < 2 || argc > 6)
		user_msg();
	if (argc >= 2)
	{
		printf("argv[%i]: %s", 1, argv[1]);
		init_set(argv[1], f);
	}
	if (f->set == 'J')
	{
		f->ci = 0.8;
		if (argc >= 4)
			i += init_c(argv[i], argv[i + 1], f);
	}
	if (argc - i <= 2 && argc - i > 0)
		i += init_palette(argv[i], f);
	if (argc - i == 1)
		i += init_color(argv[i], &f);
	if (argc - i > 0)
		user_msg();
}
