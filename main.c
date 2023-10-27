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

void	user_msg(void)
{
	ft_printf("How to use fractol:\nA. Choose set:\n");
	ft_printf("\t1 - for Mandelbrot set\n");
	ft_printf("\t2 - for Julia set\n");
	ft_printf("B: Specify starting point c (only possible for Julia set)\n");
	ft_printf("\tEnter the complex number c as two decimals (cr & ci)");
	ft_printf(" each ranging from -2.0 to 2.0.\n");
	ft_printf("\tInput example: ./fractol 2 -1.0 0.16\n");
	exit (0);
}

double	ft_atod(char *str)
{
	double	ret;
	double	sign;
	double	div;
	int		i;

	sign = 1;
	div = 0.1;
	i = 0;
	if (!str || *str == '\0')
		user_msg();
	if (str[i] == '-')
		sign = sign * -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if ('0' <= str[i] && str[i] <= '9')
		ret = str[i++] - '0';
	if (str[i] == '.')
		i++;
	while (str[i] != '\0')
	{
		if ('0' > str[i] || str[i] > '9')
			user_msg();
		ret = ret + (str[i] - '0') * div;
		printf("ret = %f\t str[%i] = %c\n", ret, i, str[i]);
		div *= 0.1;
		i++;
	}
	if (ret > 2.0)
		user_msg();
	return (ret * sign);
}

void	check_input(int argc, char **argv, t_fractol *f)
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
}

int	main(int argc, char **argv)
{
	t_fractol	f;
	
	init_var(&f);
	check_input(argc, argv, &f);
	open_window(&f, "Fractol"); // vielleicht anpassen, je nachdem welches set. Koennte in struct gespeichert sein.
	return (0);
}
