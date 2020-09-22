#include "checker_push_swap.h"

int	ft_check_back_order(t_chunk *tmp_st)
{
	int i;
	
	i = 0;
	while (i + 1 < tmp_st->size)
	{
		if (tmp_st->arr[i] < tmp_st->arr[i + 1])
			return 0;
		i++;
	}
	return 1;
}

int	ft_create_tmp_struct(t_chunk *tmp_st, int mid)
{
	if (!(tmp_st->arr = malloc(sizeof(int) * mid)))
		return 0;
	tmp_st->size = mid;
	return 1;
}

void	ft_from_A_B(t_stack *st, t_stack *ch_base)
{
	int *sort_bs;
	int mid;
	int i;
	int count;

	sort_bs = ft_sorting_stack(ch_base->stack_A, ch_base->size_A);
	mid = ch_base->size_A / 2;
	i = mid;
	if (ch_base->size_A > 2 && !ft_check_order(ch_base, 0))
	{
		while (ch_base->size_B != mid)
		{
			if (st->stack_A[0] < sort_bs[mid])
			{
				ft_push()
				ft_print_command(ft_strdup("pb"), st);
			}
			else if (!ch_base->flag && st->stack_A[st->size_A - 1] < sort_bs[mid])
				ft_print_command(ft_strdup("rra"), st);
			else
			{
				ft_print_command(ft_strdup("ra"), st);
				count++;
			}
		}
		if (ch_base->flag)
			while (count--)
				ft_print_command(ft_strdup("rra"), st);
		if (!ft_check_order(ch_base, 0))
			ft_from_A_B(st, ch_base);
	}
	if (!ft_check_order(ch_base, 0))
		ft_print_command(ft_strdup("sa"), st);
}

ft_changes(t_stack *st, t_stack *chunk)
{
	// t_chunk ch_B;
	// t_chunk ch_A;

	// if (!ft_create_struct(&ch_B, chunk->size / 2))
	// 	error();
	// sort_st = ft_sorting_stack(chunk->arr, chunk->size);
	ft_from_A_B(st, chunk);
	chunk->flag = 1;
	// if (!ft_create_struct(&ch_A, ch_B.size / 2 - 1))
	// 	error();
	ft_from_B_A(st, chunk);
	if (!ft_check_order(chunk, 0))
		ft_changes(st, chunk->stack_A);
}
