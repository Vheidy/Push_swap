/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_checker.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheidy <vheidy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 17:59:37 by vheidy            #+#    #+#             */
/*   Updated: 2020/08/12 08:47:23 by vheidy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_push_swap.h"

int		ft_check_order(t_stack *st)
{
	int i;

	i = 0;
	if (st->size_B)
		return 0;
	while (i + 1 < st->size_A) {
		if (st->stack_A[i] > st->stack_A[i + 1])
			return 0;
		i++;
	}
	return 1;
}

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

char	*ft_check_val(char *str) {
	while (*str == '0')
		str++;
	return str;
}

int		ft_check_digit(char *str)
{
	int i;
	
	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i])
		if (ft_isdigit(str[i++]) == 0)
			return 0;
	if (ft_strlen(ft_check_val(str)) > 12)
		return 0;
	return 1;
}

int		*ft_valid_digit(int ac, char **av)
{
	int *tmp;
	long long int ch;
	int i;

	i = ac;
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
	if (!ft_check_repeat(tmp, i))
		error();
	return tmp;
}
