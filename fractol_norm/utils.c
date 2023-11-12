/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 09:44:10 by tstahlhu          #+#    #+#             */
/*   Updated: 2023/11/12 10:38:39 by tstahlhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/* ft_atox_color */

unsigned int	ft_atox_color(char *str)
{
	unsigned int	ret;
	int				i;

	i = 0;
	ret = 0;
	while (str[i] != '\0')
	{
		if ('0' <= str[i] && str[i] <= '9')
			ret = ret * 16 + str[i] - '0';
		else if ('A' <= str[i] && str[i] <= 'F')
			ret = ret * 16 + str[i] - 'A' + 10;
		else
			return (0x1000000);
		i++;
	}
	if (ret > 0xFFFFFF)
		return (0x1000000);
	else
		return (ret);
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
			return (42);
		ret = ret + (str[i] - '0') * div;
		div *= 0.1;
		i++;
	}
	return (ret * sign);
}
