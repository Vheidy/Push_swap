/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheidy <vheidy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 08:07:21 by vheidy            #+#    #+#             */
/*   Updated: 2020/08/14 18:32:16 by vheidy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_push_swap.h"

/*
задачи:
Реализовать алгоритм сортировки стэка А
Сравнивать отстортированный стэк с поданным и измнять его командами
*/

// 2 1 3 6 5 8

int main(int ac, char **av)
{
	t_stack st;
	
	if (ac == 1)
		return 0;
	if (!ft_create_struct(&st, (ac - 1)))
		error();
	st.stack_A = ft_valid_digit((ac - 1), av);
	
	// int i = 0;
	// while (i < st.size_A)
	// 	printf("%d\n", st.stack_A[i++]);
	// printf("Size A: %d, Size B: %d\n", st.size_A, st.size_B);
	return 0;
}