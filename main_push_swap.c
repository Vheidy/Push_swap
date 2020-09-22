/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheidy <vheidy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 08:07:21 by vheidy            #+#    #+#             */
/*   Updated: 2020/09/21 19:32:45 by vheidy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_push_swap.h"

/*
**
Задачи:
1. Понять почему циклиться из А в Б
2. Добавить функцию для цикла переброски
3. Изменить принткоманд: добавить изменение чанков, чтобы было в одну строку
4. Написать подобное для переброски из Б в А (должно быть похоже)
Фиксить в ех
*/

void	ft_swap_pointer(int *first, int *second)
{
	int	tmp;

	tmp = *first;
	*first = *second;
	*second = tmp;
}

void	ft_quick_sort(int *begin, int *left, int *right)
{
	int	tmp;
	int	*tmp_right;

	tmp_right = right;
	while (left < right)
	{
		while (*left < *begin && left < tmp_right)
			left++;
		while (*right > *begin && right > begin)
			right--;
		if (left < right)
			ft_swap_pointer(left, right);
	}
	if ((left != right) || (left == right && *begin > *right))
		ft_swap_pointer(begin, right);
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
	return (sort);
}

void	ft_print_command(char *str, t_stack *st)
{
	ft_putstr(str);
	write(1, "\n", 1);
	ft_choose_command(str, st);
}

// int		find_mid(int begin, int end)
// {
// 	int i;

// 	i = 0;
// 	while (i != ((end - begin) / 2))
// 		i++;
// 	return i;
// }

// int	ft_check_back_order(t_tmp *tmp_st)
// {
// 	int i;
	
// 	i = 0;
// 	while (i + 1 < tmp_st->size_tmp)
// 	{
// 		if (tmp_st->tmp[i] < tmp_st->tmp[i + 1])
// 			return 0;
// 		i++;
// 	}
// 	return 1;
// }

// int	ft_create_tmp_struct(t_tmp *tmp_st, int mid)
// {
// 	if (!(tmp_st->tmp = malloc(sizeof(int) * mid)))
// 		return 0;
// 	tmp_st->size_tmp = mid;
// 	return 1;
// }

// void	ft_push_from_A_B(t_stack *st, int *sort_stack, int mid, t_tmp *tmp_st)
// {
// 	int		i;
// 	int		f;

// 	i = mid - 1;
// 	f = 0;
// 	while (st->size_B != mid || !ft_check_order(st, 0))
// 	{
// 		if (st->stack_A[0] < sort_stack[mid])
// 		{
// 			f = 1;
// 			tmp_st->tmp[i--] = st->stack_A[0];
// 			ft_print_command(ft_strdup("pb"), st);
// 		}
// 		else if (st->stack_A[st->size_A - 1] < sort_stack[mid])
// 			ft_print_command(ft_strdup("rra"), st);
// 		else
// 			ft_print_command(ft_strdup("ra"), st);
// 	}
// 	if (!ft_check_order(st, 0))
// 		ft_changes(st);
// 	else if (!f)
// 		free(tmp_st->tmp);
// }

// void	ft_push_from_B_A(t_stack *st, t_tmp *chunc_B, t_tmp *chunc_A)
// {
// 	int *sort_stack;
// 	int i;
// 	int mid;

// 	i = 0;
// 	mid = chunc_B->size_tmp / 2;
// 	sort_stack = ft_sorting_stack(chunc_B->tmp, chunc_B->size_tmp);
// 	if (ft_check_back_order(chunc_B))
// 		while (chunc_B->size_tmp--)
// 			ft_print_command(ft_strdup("pa"), st);
// 	else
// 	{
// 		while (st->size_A - st->size_B == chunc_B->size_tmp - mid - 1)
// 		{
// 			if (st->stack_B[0] > sort_stack[mid])
// 			{
				
// 				ft_print_command(ft_strdup("pa"), st);
// 			}
// 			else
// 			{
// 				ft_print_command(ft_strdup("rb"), st);
// 				i++;
// 			}
// 		}
// 	}
// 	while (i--)
// 		ft_print_command(ft_strdup("rrb"), st);
// 	if (!ft_check_back_order(chunc_B))
// 		ft_changes(st);
// }

// void	ft_changes(t_stack *st)
// {
// 	int *sort_st;
// 	int mid;
// 	t_tmp chunc_B;
// 	t_tmp chunc_A;
	
// 	mid = st->size_A / 2;
// 	if (!ft_create_struct(&chunc_B, mid))
// 		error();
// 	sort_st = ft_sorting_stack(st->stack_A, st->size_A);
// 	if (st->size_A > 2 && !ft_check_order(st, 0))
// 		ft_push_from_A_to_B(st, sort_st, mid, &chunc_B);
// 	if (!ft_check_order(st, 0))
// 		ft_print_command(ft_strdup("sa"), st);
// 	if (!ft_create_struct(&chunc_A, (chunc_B.size_tmp / 2) - 1))
// 		error();
// 	if (chunc_B.size_tmp > 2 && !ft_check_back_order(&chunc_B))
// 		ft_push_from_B_A(st, &chunc_B, &chunc_A);
// 	if (!ft_check_back_order(&chunc_B) && chunc_B.size_tmp == 2)
// 		ft_print_command(ft_strdup("sb"), st);
// 	if (chunc_B.size_tmp)
// 		ft_push_from_B_A(st, &chunc_B, &chunc_A);
// }
	// if (chunc_B.size_tmp == 2 && !ft_check_back_order(&chunc_B))
	// 	ft_print_command(ft_strdup("sb"), st);
	// if (!ft_create_struct(&chunc_B, mid))
	// 	error();
	// if (chunc_B.size_tmp)
	// 	ft_push_from_B_A(st, &chunc_B, &chunc_A);

// {
// 	int *tmp;
// 	int i;

// 	i = 0;
// 	tmp = malloc(mid);
// 	if (st->size_A > 2 && !ft_check_order(st, 0)) {
// 		while (st->size_B != mid || !ft_check_order(st, 0))
// 		{
// 			if (st->stack_A[0] < sort_stack[mid])
// 			{
// 				tmp[i++] = st->stack_A[0];
// 				ft_print_command(ft_strdup("pb"), st);
// 			}
// 			else if (st->stack_A[st->size_A - 1] < sort_stack[mid])
// 				ft_print_command(ft_strdup("rra"), st);
// 			else
// 				ft_print_command(ft_strdup("ra"), st);
// 		}
// 		if (!ft_check_order(st, 0))
// 			ft_changes(st, sort_stack, mid + ft_find_mid(mid, st->size_A));
// 	}
// 	if (!ft_check_order(st, 0))
// 		ft_print_command(ft_strdup("sa"), st);
// 	mid = ft_find_mid(0, mid);
// 	while ()
// }

// void	ft_changes(t_stack *st, int *sort_stack, int mid)
// {
// 	while (!ft_check_order(st, 0) && st->size_A <= 2)
// 	{
// 		mid += ft_find_mid(sort_stack, mid, st->size_A);
// 		while (st->size_B < mid && !ft_check_order(st, 0) && st->size_A <= 2)
// 		{
// 			if (st->stack_A[0] < sort_stack[mid])
// 				ft_print_command(ft_strdup("pb"), st);
// 			else if (st->stack_A[st->size_A - 1] < sort_stack[mid])
// 				ft_print_command(ft_strdup("rra"), st);
// 			else
// 				ft_print_command(ft_strdup("ra"), st);
// 		}
// 	}
// }

// void	ft_changes(t_stack *st, int *sort_stack, int pos)
// {
// 	while (!ft_check_order(st, 0))
// 	{
// 		pos = 0;
// 		while (st->stack_A[pos] != *(sort_stack))
// 			pos++;
// 		if (pos == 0)
// 		{
// 			ft_print_command(ft_strdup("pb"), st);
// 			sort_stack++;
// 		}
// 		if (pos == 1 && st->stack_A[0] == *(sort_stack + 1))
// 			ft_print_command(ft_strdup("sa"), st);
// 		else
// 		{
// 			if (pos <= (st->size_A / 2))
// 				while (pos--)
// 					ft_print_command(ft_strdup("ra"), st);
// 			else if (pos > (st->size_A / 2))
// 				while (st->size_A > pos++)
// 					ft_print_command(ft_strdup("rra"), st);
// 		}
// 	}
// 	while (st->size_B)
// 		ft_print_command(ft_strdup("pa"), st);
// }

int		main(int ac, char **av)
{
	t_stack	st;
	t_stack	tmp;

	if (ac == 1)
		return (0);
	// int pos = ft_find_mid(0, st.size_A);
	if (!ft_create_struct(&st, (ac - 1)))
		error();
	st.stack_A = ft_valid_digit((ac - 1), av);
	if (!ft_create_struct(&tmp, ac - 1))
		error();
	tmp.stack_A = st.stack_A; // возможно надо через копирование
	tmp.flag = 0;
	ft_changes(&st, &tmp);
	return (0);
}
