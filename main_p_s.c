#include "checker_push_swap.h"

// void	ft_algo_three_num(t_stack *st)
// {
// 	while (!ft_check_order(st->A, st->B, 0))
// 	{
// 		if (st->A->arr[0] > st->A->arr[2])
// 			ft_print_command(ft_strdup("ra"), st);
// 		else if (st->A->arr[0] > st->A->arr[1])
// 			ft_print_command(ft_strdup("sa"), st);
// 		else 
// 			ft_print_command(ft_strdup("rra"), st);
// 	}
// }

// // возвращает позицию минимального из значений больших елемента в отсортированном стэке

// int		ft_min_in_max(int elem, t_chunk *st)
// {
// 	int i;
// 	int *sort;

// 	i = -1;
// 	sort = ft_sorting_stack(st->arr, st->size);
// 	while (++i < st->size)
// 		if (sort[i] > elem)
// 			return sort[i];
// 	return 0;
// }

// // двигает стэк до поднятия позиции вверх стэка

// void	ft_min_up(t_stack *st, int pos)
// {
// 	if (pos <= st->A->size / 2)
// 		while (pos--)
// 			ft_print_command(ft_strdup("ra"), st);
// 	else
// 		while (st->A->size - (pos++))
// 			ft_print_command(ft_strdup("rra"), st);
// }

// int		ft_find_pos(int elem, t_chunk *st)
// {
// 	int pos;

// 	pos = 0;
// 	while (pos < st->size)
// 	{
// 		if (st->arr[pos] == elem)
// 			return pos;
// 		pos++;
// 	}
// 	return 0;
// }

// int		ft_check_order_new(t_chunk *st)
// {
// 	int i;
// 	int max;
// 	int min;

// 	i = -1;
// 	min = st->arr[0];
// 	while (++i + 1 < st->size)
// 		if (st->arr[i] > st->arr[i + 1])
// 		{
// 			max = st->arr[i];
// 			break ;
// 		}
// 	while (++i + 1 < st->size)
// 	{
// 		if (st->arr[i] > st->arr[i + 1] || st->arr[i] > max || st->arr[i] > min)
// 			return 0;
// 	}
// 	return 1;
// }

// void	ft_algo_five_num(t_stack *st)
// {
// 	int *sort;
// 	int pos;
// 	if (!ft_check_order(st->A, st->B, 0))
// 	{
// 		sort = ft_sorting_stack(st->A->arr, st->A->size);
// 		while (st->A->size > 3)
// 			ft_print_command(ft_strdup("pb"), st);
// 		ft_algo_three_num(st);
// 		while (st->B->size){
// 			pos = ft_min_in_max(st->B->arr[0], st->A);
// 			ft_min_up(st, ft_find_pos(pos, st->A));
// 			ft_print_command(ft_strdup("pa"), st);
// 		}
// 		ft_min_up(st, ft_find_pos(sort[0], st->A));
// 	}
// }

// void	ft_changes(t_stack *st)
// {
// 	if (st->A->size == 3)
// 		ft_algo_three_num(st);
// 	else if (st->A->size <= 5)
// 		ft_algo_five_num(st);
// 	// else if (st->A->size > 5 && st->A->size < 500)
// 	// 	ft_algo_part(st);
// }

// void	ft_put_up(int elem, t_stack *st)
// {
// 	int pos;

// 	pos = -1;
// 	while (++pos < st->A->size)
// 		if (st->A->arr[pos] == elem)
// 			break;
// 	if (pos <= st->A->size / 2)
// 		while (pos--)
// 			ft_print_command(ft_strdup("ra"), st);
// 	else
// 		while (st->A->size - (pos++))
// 			ft_print_command(ft_strdup("rra"), st);
// }

// void	ft_find_place(int elem, t_stack *st)
// {
// 	int i;
// 	int min_more;
// 	int fl;
// 	int *sort;

// 	i = -1;
// 	fl = 0;
// 	min_more = 0;
// 	while (++i < st->A->size)
// 		if (st->A->arr[i] > elem) {
// 			if (!fl){
// 				min_more = st->A->arr[i];
// 				fl = 1;
// 			}
// 			else if (fl && st->A->arr[i] < min_more)
// 				min_more = st->A->arr[i];
// 		}
// 	if (fl)
// 		ft_put_up(min_more, st);
// 	else
// 	{
// 		sort = ft_sorting_stack(st->A->arr, st->A->size);
// 		ft_put_up(sort[0], st);
// 	}
// }

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

void	ft_algo(t_stack *st, int end)
{
	int hold_first;
	int hold_second;

	hold_first = 0;
	hold_second = st->A->size - 1;
	while (hold_first < st->A->size && !(st->A->arr[hold_first] < end))
		hold_first++;
	while (hold_second >= 0 && !(st->A->arr[hold_second] < end))
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
	}
}

void	ft_push_A_B(t_stack *st)
{
	int mid;
	int *sort;
	int count;

	mid = st->A->size / 2;
	count = 0;
	sort = ft_sorting_stack(st->A->arr, st->A->size);
	printf("%d\n", sort[mid]);
	if (st->A->size > 2 && !ft_check_order(st->A, st->B, 0))
		while(count < mid && !ft_check_order(st->A, st->B, 0))
		{
			if (st->A->arr[0] < sort[mid])
			{
				ft_print_command(ft_strdup("pb"), st);
				count++;
			}
			else
				ft_algo(st, sort[mid]);
		}
	else if (!ft_check_order(st->A, st->B, 0))
		ft_print_command(ft_strdup("sa"), st);
	if (!ft_check_order(st->A, st->B, 0))
		ft_push_A_B(st);
}

void	ft_algorithm(t_stack *st)
{
	int *sort;
	
	// printf("--ok--\n");
	if (!ft_check_order(st->A, st->B, 0))
		ft_push_A_B(st);
	while (st->B->size){
		ft_find_place(st->B->arr[0], st, 0);
		ft_print_command(ft_strdup("pa"), st);
	}
	if (!ft_check_order(st->A, st->B, 0))
	{
		sort = ft_sorting_stack(st->A->arr, st->A->size);
		ft_put_up(sort[0], st, 0);
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
	// printf("%d\n", st->fl_v);
	st->A->arr = ft_valid_digit(ac, count, av, st->fl_v);
	// int i = 0;
	// while (i < count)
	// 	printf("%d\n", st->A->arr[i++]);
	// printf("Size: %d\n", st->A->size);
	ft_algorithm(st);
	return (0);
}