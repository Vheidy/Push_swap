/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheidy <vheidy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 08:07:21 by vheidy            #+#    #+#             */
/*   Updated: 2020/09/04 13:45:55 by vheidy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_push_swap.h"

/*
задачи:
Реализовать алгоритм сортировки стэка А
Сравнивать отстортированный стэк с поданным и измнять его командами
*/

// 2 1 3 6 5 8

void	ft_quick_sort(int *begin, int *left, int *right)
{
	int	tmp;
	int	*tmp_right;

	tmp_right = right;
	while (left < right) {
		while (*left < *begin && left < tmp_right)
			left++;
		while (*right > *begin && right > begin)
			right--;
		if (left < right) {
			tmp = *left;
			*left = *right;
			*right = tmp;
		}
	}
	if ((left != right) || (left == right && *begin > *right)) {
		tmp = *begin;
		*begin = *right;
		*right = tmp;
	}
	if (right - begin > 1)
		ft_quick_sort(begin, (begin + 1), (right - 1));
	if (tmp_right - right > 1)
		ft_quick_sort(left, (left + 1), tmp_right);
}

int		*ft_sorting_stack(int *stack, int size)
{
	int	*sort;
	int	i;
	
	i = -1;
	sort = malloc(sizeof(int) * size);
	while (++i < size)
		sort[i] = stack[i];
	if (size > 1)
		ft_quick_sort(&sort[0], &sort[1], &sort[size - 1]);
	return sort;
}

void	ft_print_command(char *str, t_stack *st)
{
	ft_putstr(str);
	write(1, "\n", 1);
	ft_choose_command(str, st);
}

void	ft_changes(t_stack *st, int *sort_stack)
{
	int	pos;

	while (!ft_check_order(st, 0)) {
		pos = 0;
		while (st->stack_A[pos] != *(sort_stack))
			pos++;
		if (pos == 0) {
			ft_print_command(ft_strdup("pb"), st);
			sort_stack++;
		}
		if (pos == 1 && st->stack_A[0] == *(sort_stack + 1))
			ft_print_command(ft_strdup("sa"), st);
		else
		{
			if (pos <= (st->size_A / 2))
				while (pos--)
					ft_print_command(ft_strdup("ra"), st);
			else if (pos > (st->size_A / 2))
				while (st->size_A > pos++)
					ft_print_command(ft_strdup("rra"), st);
		}
	}
	while (st->size_B)
		ft_print_command(ft_strdup("pa"), st);
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
	ft_changes(&st, sort_stack);
	return 0;
}