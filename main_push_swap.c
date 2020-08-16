/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheidy <vheidy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 08:07:21 by vheidy            #+#    #+#             */
/*   Updated: 2020/08/16 18:24:23 by vheidy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_push_swap.h"

/*
задачи:
Реализовать алгоритм сортировки стэка А
Сравнивать отстортированный стэк с поданным и измнять его командами
*/

// 2 1 3 6 5 8

int		ft_len_less(int *stack, int size, int index)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (i < size) {
		if (stack[i] < stack[index])
			count++;
		i++;
	}
	return count;
}

int		ft_len_larg(int *stack, int size, int index)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (i < size) {
		if (stack[i] > stack[index])
			count++;
		i++;
	}
	return count;
}

int		*ft_quick_sort(int *stack, int size)
{
	int main_index;
	int *less;
	int *larg;

	int i = 0;
	main_index = size / 2;
	less = malloc(sizeof(int) * ft_len_less(stack, size, main_index));
	larg = malloc(sizeof(int) * ft_len_larg(stack, size, main_index));
	while (i < size) {
		if (stack[i] < stack[main_index])
		i++;
	}
}

int		*ft_sorting_stack(int *stack, int size)
{
	int	*sort;
	
	sort = ft_quick_sort(stack, size);
}

int		main(int ac, char **av)
{
	t_stack st;
	int *sort_stack;
	
	if (ac == 1)
		return 0;
	if (!ft_create_struct(&st, (ac - 1)))
		error();
	st.stack_A = ft_valid_digit((ac - 1), av);
	sort_stack = ft_sorting_stack(st.stack_A, st.size_A);
	// int i = 0;
	// while (i < st.size_A)
	// 	printf("%d\n", st.stack_A[i++]);
	// printf("Size A: %d, Size B: %d\n", st.size_A, st.size_B);
	return 0;
}