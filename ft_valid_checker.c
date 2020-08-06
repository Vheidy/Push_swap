/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_checker.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheidy <vheidy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 17:59:37 by vheidy            #+#    #+#             */
/*   Updated: 2020/08/06 18:01:31 by vheidy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

/*
Добавить проверку на повторение элементов
В этот файл закинуть функцию проверки на отсортированность
*/

int		ft_check_digit(char *str)
{
	int i;
	
	i = 0;
	if (ft_strlen(str) > 12)
		return 0;
	if (str[i] == '-')
		i++;
	while (str[i])
		if (ft_isdigit(str[i++]) == 0)
			return 0;
	return 1;
}

// проверить на повторение элементов

int		*ft_valid_digit(int ac, char **av)
{
	int *tmp;
	long long int ch;

	if (!(tmp = malloc(sizeof(int) * ac)))
		return NULL;
	while (ac > 0)
	{
		ch = ft_atoi(av[ac]);
		if (!ft_check_digit(av[ac]) || ch > 2147483647 || ch < (-2147483647))
			error();
		tmp[ac - 1] = ch;
		ac--;
	}
	return tmp;
}
