/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheidy <vheidy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 08:07:21 by vheidy            #+#    #+#             */
/*   Updated: 2020/10/06 17:57:54 by vheidy           ###   ########.fr       */
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

// void	ft_swap_pointer(int *first, int *second)
// {
// 	int	tmp;

// 	tmp = *first;
// 	*first = *second;
// 	*second = tmp;
// }

// void	ft_quick_sort(int *begin, int *left, int *right)
// {
// 	int	tmp;
// 	int	*tmp_right;

// 	tmp_right = right;
// 	while (left < right)
// 	{
// 		while (*left < *begin && left < tmp_right)
// 			left++;
// 		while (*right > *begin && right > begin)
// 			right--;
// 		if (left < right)
// 			ft_swap_pointer(left, right);
// 	}
// 	if ((left != right) || (left == right && *begin > *right))
// 		ft_swap_pointer(begin, right);
// 	if (right - begin > 1)
// 		ft_quick_sort(begin, (begin + 1), (right - 1));
// 	if (tmp_right - right > 1)
// 		ft_quick_sort(left, (left + 1), tmp_right);
// }

// int		*ft_sorting_stack(int *stack, int size)
// {
// 	int	*sort;
// 	int	i;

// 	i = -1;
// 	sort = malloc(sizeof(int) * size);
// 	while (++i < size)
// 		sort[i] = stack[i];
// 	if (size > 1)
// 		ft_quick_sort(&sort[0], &sort[1], &sort[size - 1]);
// 	return (sort);
// }

// void	ft_print_command(char *str, t_stack *st)
// {
// 	ft_putstr(str);
// 	write(1, "\n", 1);
// 	ft_choose_command(str, st);
// }

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

// void	ft_push_A_B(t_stack *st, t_lst *A, t_lst *B)
// {
// 	int mid;
// 	int *sort;
// 	t_lst *next_lst;
// 	int count;

// 	mid = A->ch->size / 2;
// 	count = 0;
// 	if (!(next_lst = ft_new_list(0 , B)))
// 		error();
// 	B->next = next_lst;
// 	sort = ft_sorting_stack(A->ch->arr, A->ch->size);
// 	if (A->ch->size > 2 && !ft_check_order(A->ch, A->ch, 0))
// 	{
// 		while (B->ch->size < mid)
// 		{
// 			// printf("Hi\n");
// 			if (!A->before && ft_check_order(A->ch, A->ch, 0))
// 				break ;
// 			if (st->A->arr[0] < sort[mid])
// 					ft_print_command(ft_strdup("pb"), st, A, B);
// 			else if (st->A->arr[st->A->size - 1] < sort[mid])
// 				ft_print_command(ft_strdup("rra"), st, A, B);
// 			else
// 			{
// 				ft_print_command(ft_strdup("ra"), st, A, B);
// 				count = (A->before) ? (count + 1) : 0;
// 			}
// 			// printf("Bye\n");
// 			if (A->before)
// 				while (count--)
// 					ft_print_command(ft_strdup("rra"), st, A, B);
// 		}
// 	} else if (!ft_check_order(A->ch, A->ch, 0))
// 		ft_print_command(ft_strdup("sa"), st, A, B);
// 	if (st->A->size > 2 && !ft_check_order(A->ch, A->ch, 0)) {
// 		printf("--A-next-A-B--\n");
// 		ft_push_A_B(st, A, next_lst);
// 	}
// 	if (!next_lst->ch->size)
// 	{
// 		next_lst->before = NULL;
// 		B->next = NULL;
// 	}
// }

// void	ft_print_chunk(t_lst *begin)
// {
// 	t_lst *tmp;
// 	// int i = 4;

// 	tmp = begin;
// 	int c = 0;
// 	printf("--BEGIN--\n");
// 	// printf("size = %d\n", tmp->ch->size);
// 	while (c < tmp->ch->size)
// 		printf("%d\n", tmp->ch->arr[c++]);
// 	// tmp = tmp->before;
// 	printf("--END--\n");
// }

// void	ft_push_B_A(t_stack *st, t_lst *B, t_lst *A)
// {
// 	int mid;
// 	int count;
// 	int *sort;
// 	t_lst *next_list;
// 	int size_new;

// 	mid = B->ch->size / 2;
// 	size_new = (B->ch->size % 2) ? mid : mid - 1;
// 	count = 0;
// 	if (!(next_list = ft_new_list(0 , A)))
// 		error();
// 	A->next = next_list;
// 	sort = ft_sorting_stack(B->ch->arr, B->ch->size);
// 	if (B->ch->size > 2 && !ft_check_back_order(B->ch))
// 	{
// 		while (A->ch->size < size_new && !ft_check_back_order(B->ch))
// 		{
// 			if (st->B->arr[0] > sort[mid])
// 				ft_print_command(ft_strdup("pa"), st, A, B);
// 			else if (st->B->arr[st->B->size - 1] > sort[mid])
// 				ft_print_command(ft_strdup("rrb"), st, A, B);
// 			else
// 			{
// 				ft_print_command(ft_strdup("rb"), st, A, B);
// 				count++;
// 			}
// 		}
// 		if (B->before)
// 			while (count--)
// 				ft_print_command(ft_strdup("rrb"), st, A, B);
// 	}
// 	else if (!ft_check_back_order(B->ch))
// 		ft_print_command(ft_strdup("sb"), st, A, B);
// 	// printf("%d\n", B->ch->size);
// 	while (B->ch->size && ft_check_back_order(B->ch))
// 		ft_print_command(ft_strdup("pa"), st, A, B);
// 	if (!ft_check_order(A->ch, B->ch, 0))
// 	{
// 		if (!(next_list = ft_new_list(0 , B)))
// 		error();
// 		B->next = next_list;
// 		printf("--B-next-A-B--\n");
// 		ft_push_A_B(st, A, next_list);
// 	}
// 	if (st->B->size)
// 	{
// 		// printf("--A--\n");
// 		// ft_print_chunk(A);
// 		// printf("--B--\n");
// 		// ft_print_chunk(B);
// 		printf("--B-next-B-A--\n");
// 		if (B->before){
// 			ft_push_B_A(st, B->before, next_list);
// 		}
// 		// else 
// 		// 	ft_push_B_A(st, B, next_list);
// 	}
// }

// t_lst	*ft_get_end_lst(t_lst *begin)
// {
// 	t_lst *tmp;

// 	tmp = begin;
// 	while (tmp->next)
// 		tmp = tmp->next;
// 	// if (!tmp->ch->size)
// 	// 	ft_dellst(tmp);
// 	return tmp;
// }



// void	ft_algorithm(t_stack *st, t_lst *A)
// {
// 	t_lst *B_begin;
// 	t_lst *ch;

// 	if (!(B_begin = ft_new_list(0, 0)))
// 		error();
// 	if (A->ch->size > 2 && !ft_check_order(A->ch, A->ch, 0))
// 		ft_push_A_B(st, A, B_begin);
// 	ch = ft_get_end_lst(B_begin);
// 	// ft_print_chunk(ch);
// 	printf("--first-ok--\n");
// 	ft_push_B_A(st, ch, A);
// 	printf("--second-ok--\n");
// }

// void	ft_changes(t_stack *st)
// {
// 	t_lst	*ch_A_begin;
// 	int i;

// 	i = -1;
// 	if (!(ch_A_begin = ft_new_list(st->A->size, 0)))
// 		error();
// 	while (++i < st->A->size) {
// 			ch_A_begin->ch->arr[i] = st->A->arr[i];
// 	}
// 	ft_algorithm(st, ch_A_begin);
// }

void	ft_algo_three_num(t_stack *st)
{
	while (!ft_check_order(st->A, st->B, 0))
	{
		if (st->A->arr[0] > st->A->arr[2])
			ft_print_command(ft_strdup("ra"), st);
		else if (st->A->arr[0] > st->A->arr[1])
			ft_print_command(ft_strdup("sa"), st);
		else 
			ft_print_command(ft_strdup("rra"), st);
	}
}

// возвращает позицию минимального из значений больших елемента в отсортированном стэке

int		ft_min_in_max(int elem, t_chunk *st)
{
	int i;
	int *sort;

	i = -1;
	sort = ft_sorting_stack(st->arr, st->size);
	while (++i < st->size)
		if (sort[i] > elem)
			return sort[i];
	return 0;
}

// если флага нет то для А, если есть то для В

void	ft_put_up(int elem, t_stack *st, int fl)
{
	int pos;
	t_chunk *tmp;

	pos = -1;
	tmp = (fl) ? st->B : st->A;
	// printf("SZIE: %d\n", tmp->size);
	while (++pos < tmp->size)
		if (tmp->arr[pos] == elem)
			break;
	if (pos <= tmp->size / 2)
		while (pos--)
		{
			if (!fl)
				ft_print_command(ft_strdup("ra"), st);
			else
				ft_print_command(ft_strdup("rb"), st);
		}
	else
		while (tmp->size - (pos++))
			{
			if (!fl)
				ft_print_command(ft_strdup("rra"), st);
			else
				ft_print_command(ft_strdup("rrb"), st);
		}
}

// находит наименьшее значение которое больше елем и поднимает его вверх

void	ft_find_place(int elem, t_stack *st, int f)
{
	int i;
	int max_less;
	int fl;
	int *sort;
	t_chunk *tmp;

	i = -1;
	fl = 0;
	max_less = 0;
	tmp = (!f) ? st->A : st->B;
	while (++i < tmp->size)
		if (tmp->arr[i] < elem) {
			if (!fl){
				max_less = tmp->arr[i];
				fl = 1;
			}
			else if (fl && tmp->arr[i] > max_less)
				max_less = tmp->arr[i];
		}
	if (fl)
		ft_put_up(max_less, st, f);
	else
	{
		sort = ft_sorting_stack(tmp->arr, tmp->size);
		ft_put_up(sort[tmp->size - 1], st, f);
	}
}


void	ft_min_up(t_stack *st, int pos)
{
	if (pos <= st->A->size / 2)
		while (pos--)
			ft_print_command(ft_strdup("ra"), st);
	else
		while (st->A->size - (pos++))
			ft_print_command(ft_strdup("rra"), st);
}

int		ft_find_pos(int elem, t_chunk *st)
{
	int pos;

	pos = 0;
	while (pos < st->size)
	{
		if (st->arr[pos] == elem)
			return pos;
		pos++;
	}
	return 0;
}

void	ft_algo_five_num(t_stack *st)
{
	int *sort;
	int pos;
	if (!ft_check_order(st->A, st->B, 0))
	{
		sort = ft_sorting_stack(st->A->arr, st->A->size);
		while (st->A->size > 3)
			ft_print_command(ft_strdup("pb"), st);
		ft_algo_three_num(st);
		while (st->B->size){
			pos = ft_min_in_max(st->B->arr[0], st->A);
			ft_min_up(st, ft_find_pos(pos, st->A));
			ft_print_command(ft_strdup("pa"), st);
		}
		ft_min_up(st, ft_find_pos(sort[0], st->A));
	}
}

void	ft_algo(t_stack *st, int start, int end)
{
	int hold_first;
	int hold_second;

	hold_first = 0;
	hold_second = st->A->size - 1;
	while (hold_first < st->A->size && !(st->A->arr[hold_first] >= start && st->A->arr[hold_first] <= end))
		hold_first++;
	while (hold_second >= 0 && !(st->A->arr[hold_second] >= start && st->A->arr[hold_second] <= end))
		hold_second--;
	if (hold_first != st->A->size)
	{
		if (hold_first <= st->A->size / 2 && hold_second > st->A->size / 2)
		{
			if (hold_first <= st->A->size - hold_second)
				ft_put_up(st->A->arr[hold_first], st, 0);
			else
				ft_put_up(st->A->arr[hold_second], st, 0);
		}
		else if (hold_first > st->A->size / 2 && hold_second > st->A->size / 2)
			ft_put_up(st->A->arr[hold_second], st, 0);
		else
			ft_put_up(st->A->arr[hold_first], st, 0);
		if (st->B->size > 1)
			ft_find_place(st->A->arr[0], st, 1);
		ft_print_command(ft_strdup("pb"), st);
		ft_algo(st, start, end);
	}
}

void	ft_big_algo(t_stack *st, int part)
{
	int i;
	int *sort;
	int size;

	i = 0;
	size = st->A->size;
	sort = ft_sorting_stack(st->A->arr, st->A->size);
	while (++i <= part)
		if (i != part)
			ft_algo(st, sort[(size / part) * i - (size / part)], sort[(size / part) * i - 1]);
		else
			ft_algo(st, sort[(size / part) * i - (size / part)], sort[size - 1]);
	// printf("%d\n", sort[size - 1]);
	ft_put_up(sort[size - 1], st, 1);
	while (st->B->size)
		ft_print_command(ft_strdup("pa"), st);
}

void	ft_changes(t_stack *st)
{
	if (!ft_check_order(st->A, st->B, 0))
	{
		if (st->A->size == 2)
			ft_print_command(ft_strdup("sa"), st);
		else if (st->A->size > 2 && st->A->size <= 5)
			ft_algo_five_num(st);
		else if (st->A->size > 5 && st->A->size <= 49)
			ft_big_algo(st, 2);
		else if (st->A->size > 49 && st->A->size <= 99)
			ft_big_algo(st, 4);
		else if (st->A->size > 99 && st->A->size <= 200)
			ft_big_algo(st, 5);
		else if (st->A->size > 200 && st->A->size <= 400)
			ft_big_algo(st, 8);
		else if (st->A->size > 400 && st->A->size <= 499)
			ft_big_algo(st, 10);
		else if (st->A->size > 499)
			ft_big_algo(st, 11);
	}
}

int		main(int ac, char **av)
{
	t_stack	*st;
	int count;

	count = 0;
	if (ac == 1)
		return (0);
	count = ft_count_digit(av, ac);
	// printf("%d\n", count);
	if (!(st = ft_create_stack(count)))
			error();
	if (!ft_strcmp(av[1], "-v"))
		st->fl_v = 1;
	st->A->arr = ft_valid_digit(ac, count, av, st->fl_v);
	ft_changes(st);
	return (0);
}
