/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_checker.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheidy <vheidy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 17:59:37 by vheidy            #+#    #+#             */
/*   Updated: 2020/08/06 19:11:29 by vheidy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

/*
В этот файл закинуть функцию проверки на отсортированность
*/

int		ft_check_repeat(int *stack, int ac)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < ac) {
		while (j < ac) {
			if (stack[i] == stack[j] && i != j)
				return 0;
			j++;
		}
		j = 0;
		i++;
	}
	return 1;
}

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
	if (!ft_check_repeat(tmp, ac))
		error();
	return tmp;
}
