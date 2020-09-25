#include "checker_push_swap.h"







void	ft_push_A_B(t_stack *st, t_lst *A, t_lst *B, int fl)
{
	int mid;
	int *sort;
	t_lst *next_lst;
	int count;

	mid = A->ch->size / 2;
	count = 0;
	if (!(next_lst = ft_new_list((st->A->size - mid) / 2, B)))
		error();
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
	if (fl)
		while (count--)
			ft_print_command(ft_strdup("rra"), st, A, B);
	if (st->A->size > 2 && !ft_check_order(A, A, 0))
		ft_push_A_B(st, A, B, fl);
	if (st->A->size == 2 && !ft_check_order(A->ch, A->ch, 0))
		ft_print_command(ft_strdup("sa"), st, A, B);
}

void	ft_algorithm(t_stack *st, t_lst *A)
{
	t_lst *B;

	if (!(B = ft_new_list(0, 0)))
		error();
	if (A->ch->size > 2 && !ft_check_order(A, A, 0))
		ft_push_A_B(st, A, B, 0);
}

void	ft_changes(t_stack *st)
{
	t_lst	*ch_A_begin;
	// t_lst	*ch_B_begin;
	int i;

	i = 0;
	if (!(ch_A_begin = ft_new_list(st->A->size, 0)))
		error();
	while (i < st->A->size)
			ch_A_begin->ch->arr[i] = st->A->arr[i];
	ft_algotithm(st, &ch_A_begin);
}

int		main(int ac, char **av)
{
	t_chunk	st_A;
	t_chunk st_B;
	t_stack st;

	if (ac == 1)
		return (0);
	if (!ft_create_stack(&st, &st_A, &st_B, ac - 1))
		error();
	st_A.arr = ft_valid_digit((ac - 1), av);
	ft_changes(&st);
	return (0);
}