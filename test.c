#include "checker_push_swap.h"

void	ft_push_A_B(t_stack *st, t_lst *A, t_lst *B, int fl)
{
	int mid;
	int *sort;
	t_lst *next_lst;
	int count;

	mid = A->ch->size / 2;
	count = 0;
	if (!(next_lst = ft_new_list(0 , B)))
		error();
	B->next = next_lst;
	sort = ft_sorting_stack(A->ch->arr, A->ch->size);
	while (B->ch->size < mid && !ft_check_order(A->ch, A->ch, 0))
	{
		if (st->A->arr[0] < sort[mid])
				ft_print_command(ft_strdup("pb"), st, A, B);
		else if (st->A->arr[st->A->size - 1] < sort[mid])
			ft_print_command(ft_strdup("rra"), st, A, B);
		else
		{
			ft_print_command(ft_strdup("ra"), st, A, B);
			count++;
		}
	}
	if (A->before)
		while (count--)
			ft_print_command(ft_strdup("rra"), st, A, B);
	if (st->A->size > 2 && !ft_check_order(A->ch, A->ch, 0))
		ft_push_A_B(st, A, next_lst, fl);
	if (st->A->size == 2 && !ft_check_order(A->ch, A->ch, 0))
		ft_print_command(ft_strdup("sa"), st, A, B);
}

void	ft_push_B_A(t_stack *st, t_lst *B, t_lst *A, int fl)
{
	int mid;
	int count;
	int *sort;
	t_lst *next_list;
	int size_new;

	mid = B->ch->size / 2;
	size_new = (B->ch->size % 2) ? mid : mid - 1;
	count = 0;
	if (!(next_list = ft_new_list(0 , A)))
		error();
	A->next = next_list;
	sort = ft_sorting_stack(B->ch->arr, B->ch->size);
	if (B->ch->size > 2 && !ft_check_back_order(B->ch))
	{
		while (A->ch->size < size_new && !ft_check_back_order(B->ch))
		{
			if (st->B->arr[0] > sort[mid])
				ft_print_command(ft_strdup("pa"), st, A, B);
			else if (st->B->arr[st->B->size - 1] > sort[mid])
				ft_print_command(ft_strdup("rrb"), st, A, B);
			else
			{
				ft_print_command(ft_strdup("rb"), st, A, B);
				count++;
			}
		}
		if (B->before)
			while (count--)
				ft_print_command(ft_strdup("rrb"), st, A, B);
	}
	else if (!ft_check_back_order(B->ch))
		ft_print_command(ft_strdup("sb"), st, A, B);
	// printf("%d\n", B->ch->size);
	while (B->ch->size && ft_check_back_order(B->ch))
		ft_print_command(ft_strdup("pa"), st, A, B);
	if (!ft_check_order(A->ch, B->ch, 0))
		ft_push_A_B(st, A, B, 1);
	if (st->B->size)
	{
		if (B->before)
			ft_push_B_A(st, B->before, next_list, 1);
		else 
			ft_push_B_A(st, B, next_list, 1);
	}
}

t_lst	*ft_get_end_lst(t_lst *begin)
{
	t_lst *tmp;

	tmp = begin;
	while (tmp->next)
		tmp = tmp->next;
	return tmp;
}

void	ft_algorithm(t_stack *st, t_lst *A)
{
	t_lst *B_begin;
	t_lst *ch;

	if (!(B_begin = ft_new_list(0, 0)))
		error();
	if (A->ch->size > 2 && !ft_check_order(A->ch, A->ch, 0))
		ft_push_A_B(st, A, B_begin, 0);
	// printf("--1--\n");
	ch = ft_get_end_lst(B_begin);
	printf("---FIRST-PART-END--\n");
	ft_push_B_A(st, ch, A, 0);
	// printf("---SECOND-PART-END--\n");
}

void	ft_changes(t_stack *st)
{
	t_lst	*ch_A_begin;
	int i;

	i = -1;
	if (!(ch_A_begin = ft_new_list(st->A->size, 0)))
		error();
	while (++i < st->A->size) {
			ch_A_begin->ch->arr[i] = st->A->arr[i];
	}
	ft_algorithm(st, ch_A_begin);
}

int		main()
{
	t_stack *st;

	if (!(st = ft_create_stack(8)))
		error();
	st->A->arr[0] = 8;
	st->A->arr[1] = 3;
	st->A->arr[2] = 6;
	st->A->arr[3] = 1;
	st->A->arr[4] = 2;
	st->A->arr[5] = 4;
	st->A->arr[6] = 7;
	st->A->arr[7] = 5;
	// st->A->arr[8] = 8;
	ft_changes(st);
	// int i = 0;
	// while (i < st.A->size)
	// 	printf("%d\n", st.A->arr[i]);
	return (0);
}