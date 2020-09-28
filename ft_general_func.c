/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_general_func.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheidy <vheidy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 08:14:14 by vheidy            #+#    #+#             */
/*   Updated: 2020/09/28 18:48:38 by vheidy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_push_swap.h"

int		ft_create_chunk(t_chunk *st, int ac)
{
	if (!(st->arr = malloc(sizeof(int) * ac)))
		return 0;
	st->size = ac;
	return 1;
}


int		ft_count_digit(char **av, int ac)
{
	int i;
	int count;

	count = 0;
	while (--ac)
	{
		i = -1;
		while (av[ac][++i])
			if ((ft_isdigit(av[ac][i]) && i == 0) \
			|| (av[ac][i] == ' ' && ft_isdigit(av[ac][i + 1])) || \
			(av[ac][i] == '-' && i > 0 && av[ac][i - 1] == ' ' && ft_isdigit(av[ac][i + 1])))
				count++;
	}
	return count;
}

t_stack	*ft_create_stack(int ac)
{
	t_stack *st;


	if (!(st = (t_stack *)malloc(sizeof(t_stack))) || !(st->A = (t_chunk *)malloc(sizeof(t_chunk))) || !(st->B = (t_chunk *)malloc(sizeof(t_chunk))))
		return NULL;
	if (!ft_create_chunk(st->A, ac) || !ft_create_chunk(st->B, 0))
		return NULL;
	st->A->size = ac;
	st->B->size = 0;
	return st;
}

t_lst		*ft_new_list(int content_size, t_lst *before)
{
	t_lst *list;

	if (!(list = (t_lst *)malloc(sizeof(t_lst))) || !(list->ch = (t_chunk *)malloc(sizeof(t_chunk))))
		return (NULL);
	if (content_size)
		if (!(list->ch->arr = malloc(sizeof(int) * content_size)))
			return NULL;
	list->ch->size = content_size;
	list->next = NULL;
	list->before = before;
	return (list);
}

// void	ft_dellst(t_lst *list)
// {
// 	free(list->ch->arr);
// 	list = list->before;
// 	list->next = NULL;
// }

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

void	ft_print_command(char *str, t_stack *st, t_lst *A, t_lst *B)
{
	char *tmp;

	tmp = ft_strdup(str);
	ft_putstr(str);
	write(1, "\n", 1);
	if (!ft_choose_command(str, A->ch, B->ch, 0) || !ft_choose_command(tmp, st->A, st->B, 0))
		error();
}

void	ft_swap_pointer(int *first, int *second)
{
	int	tmp;

	tmp = *first;
	*first = *second;
	*second = tmp;
}

void	ft_quick_sort(int *begin, int *left, int *right)
{
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


void	error()
{
	write(1, "Error\n", 6);
	exit(0);
}

// int	ft_create_struct(t_stack *st, int ac)
// {
// 	if (!(st->stack_A = malloc(sizeof(int) * ac)) || !(st->stack_B = malloc(sizeof(int) * 0)))
// 		return 0;
// 	st->size_A = ac;
// 	st->size_B = 0;
// 	st->flag = 0;
// 	return 1;
// }

int		ft_check_order(t_chunk *A, t_chunk *B, int fl)
{
	int i;

	i = 0;
	if (B->size && fl)
		return 0;
	while (i + 1 < A->size) {
		if (A->arr[i] > A->arr[i + 1])
			return 0;
		i++;
	}
	return 1;
}