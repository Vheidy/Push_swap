/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_general_func.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheidy <vheidy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 08:14:14 by vheidy            #+#    #+#             */
/*   Updated: 2020/08/12 08:16:00 by vheidy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_push_swap.h"

void	error()
{
	write(1, "Error\n", 6);
	exit(0);
}

int	ft_create_struct(t_stack *st, int ac)
{
	if (!(st->stack_A = malloc(sizeof(int) * ac)) || !(st->stack_B = malloc(sizeof(int) * ac)))
		return 0;
	st->size_A = ac;
	st->size_B = 0;
	st->flag = 0;
	return 1;
}