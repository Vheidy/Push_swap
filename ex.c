#include "checker_push_swap.h"
#include <stdio.h>
#include "libft/libft.h"

// void	ft_push(int **from, int **where, int *size_fr, int *size_wr)
// {
// 	int tmp;
// 	int *new_from;
// 	int *new_where;
// 	int j;
// 	int i;
	
// 	i = -1;
// 	j = 0;
// 	*size_fr -= 1;
// 	*size_wr += 1;
// 	tmp = (*from)[0];
// 	new_from = malloc(sizeof(int) * (*size_fr));
// 	while (++i < *size_fr)
// 		new_from[i] = (*from)[i + 1];
// 	new_where = malloc(sizeof(int) * (*size_wr));
// 	new_where[j] = tmp;
// 	while (++j < *size_wr)
// 		new_where[j] = (*where)[j - 1];
// 	free(*from);
// 	free(*where);
// 	*from = new_from;
// 	*where = new_where;
// }

// int main() {
// 	int *from;
// 	int *where;
// 	int size_fr = 2;
// 	int size_wr = 4;

// 	where = malloc(sizeof(int) * size_wr);
// 	from = malloc(sizeof(int) * size_fr);
// 	from[0]= 5;
// 	from[1] = 3;
// 	where[0] = 1;
// 	where[1] = 7;
// 	where[2] = 4;
// 	where[3] = 2;
// 	ft_push(&from, &where, &size_fr, &size_wr);
// 	int i = 0;
// 	printf("From:\n");
// 	while (i < size_fr)
// 		printf("%d\n", from[i++]);
// 	int j = 0;
// 	printf("Where:\n");
// 	while (j < size_wr)
// 		printf("%d\n", where[j++]);
// 	printf("Size_fr: %d, Size_wr: %d\n", size_fr, size_wr);
// 	return 0;
// }

// void	ft_swap_pointer(int *first, int *second) {
// 	int tmp;

// 	tmp = *first;
// 	*first = *second;
// 	*second = tmp;
// }

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

/*
chunk:
		int *arr;
		int size;
*/

void	ft_from_A_B(t_stack *st, t_chunk *ch, int fl)
{

}
// void	ft_from_A_B(t_stack *st, t_stack *ch_base, int fl)
// {
// 	int *sort_bs;
// 	int mid;
// 	int i;
// 	int count;

// 	count = 0;
// 	sort_bs = ft_sorting_stack(ch_base->stack_A, ch_base->size_A);
// 	mid = ch_base->size_A / 2;
// 	// printf("%d\n", sort_bs[mid]);
// 	i = mid;
// 	if (ch_base->size_A > 2 && !ft_check_order(ch_base, 0))
// 	{
// 		while (ch_base->size_B < mid)
// 		{
// 			if (st->stack_A[0] < sort_bs[mid])
// 			{
// 				ft_choose_command(ft_strdup("pb"), ch_base);
// 				ft_print_command(ft_strdup("pb"), st);
// 			}
// 			else if (!fl && st->stack_A[st->size_A - 1] < sort_bs[mid])
// 			{
// 				ft_choose_command(ft_strdup("rra"), ch_base);
// 				ft_print_command(ft_strdup("rra"), st);
// 			}
// 			else
// 			{
// 				ft_choose_command(ft_strdup("ra"), ch_base);
// 				ft_print_command(ft_strdup("ra"), st);
// 				count++;
// 			}
// 		}
// 	}
// 	if (fl)
// 	{
// 		while (count--)
// 		{
// 			ft_choose_command(ft_strdup("rra"), ch_base);
// 			ft_print_command(ft_strdup("rra"), st);
// 		}
// 	}
// 	if (!ft_check_order(ch_base, 0) && ch_base->size_A > 2)
// 			ft_from_A_B(st, ch_base, 1);
// 	if (!ft_check_order(ch_base, 0)) {
// 		ft_choose_command(ft_strdup("sa"), ch_base);
// 		ft_print_command(ft_strdup("sa"), st);
// 	}
// }

int	ft_create_tmp_struct(t_chunk *tmp_st, int mid)
{
	if (!(tmp_st->tmp = malloc(sizeof(int) * mid)))
		return 0;
	tmp_st->size_tmp = mid;
	return 1;
}

int		main()
{
	t_stack st;
	t_chunk tmp;
	int i;

	i = -1;
	ft_create_struct(&st, 8);
	st.stack_A[0] = 8;
	st.stack_A[1] = 3;
	st.stack_A[2] = 6;
	st.stack_A[3] = 1;
	st.stack_A[4] = 2;
	st.stack_A[5] = 4;
	st.stack_A[6] = 7;
	st.stack_A[7] = 5;
	ft_create_tmp_struct(&tmp, st.size_A);
	while (++i < st.size_A)
		tmp.arr[i] = st.stack_A[i];
	ft_from_A_B(&st, &tmp, 0);
	return 0;
}