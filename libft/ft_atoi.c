/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheidy <vheidy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 17:38:31 by vheidy            #+#    #+#             */
/*   Updated: 2019/09/16 22:01:39 by vheidy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_check(int a, int b)
{
	if (a > 19 && b == -1)
		return (0);
	if (a > 19 && b == 1)
		return (-1);
	return (1);
}

int				ft_atoi(const char *str)
{
	int i;
	int b;
	int a;
	int k;

	i = 0;
	b = 1;
	k = 0;
	a = 0;
	while (str[i] == '\t' || str[i] == ' ' || str[i] == '\r' || str[i] == '\n'
			|| str[i] == '\v' || str[i] == '\f')
		i++;
	if (str[i] == '-')
		b = 1 * -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		k = k * 10 + str[i] - '0';
		i++;
		a++;
	}
	if (ft_check(a, b) == 0 || ft_check(a, b) == -1)
		return (ft_check(a, b));
	return (k * b);
}
