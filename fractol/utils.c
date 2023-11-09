/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 09:44:10 by tstahlhu          #+#    #+#             */
/*   Updated: 2023/10/29 09:44:12 by tstahlhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fractol.h"

unsigned int ft_atox(char *str)
{
    unsigned int ret;
    int     i;

    if (str[0] != '0' || str[1] != 'x')
        return (42);
    i = 2;
    ret = 0;
    while (str[i] != '\0')
    {
        if ('0' <= str[i] && str[i] <= '9')
            ret = ret * 16 + str[i] - '0';
        else if ('A' <= str[i] && str[i] <= 'F')
        {
            printf("%d * 16 + %i - %i\n", ret, str[i], 'A');
            ret = ret * 16 + str[i] - 'A' + 10;
        }   
        else
            return (42);
        printf("color: %d\n", ret);
        i++;
    }
    if (ret > 0xFFFFFF)
        return (42);
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
