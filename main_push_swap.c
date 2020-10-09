/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheidy <vheidy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 08:07:21 by vheidy            #+#    #+#             */
/*   Updated: 2020/10/09 19:29:43 by vheidy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_push_swap.h"

void	ft_choose_hold(int first, int second, t_stack *st)
{
	if (first <= st->a->size / 2 && second > st->a->size / 2)
	{
		if (first <= st->a->size - second)
			ft_put_up(st->a->arr[first], st, 0);
		else
			ft_put_up(st->a->arr[second], st, 0);
	}
	else if (first > st->a->size / 2 && second > st->a->size / 2)
		ft_put_up(st->a->arr[second], st, 0);
	else
		ft_put_up(st->a->arr[first], st, 0);
}

void	ft_algo(t_stack *st, int start, int end)
{
	int first;
	int second;

	first = 0;
	second = st->a->size - 1;
	while (first < st->a->size && !(st->a->arr[first] >= start \
	&& st->a->arr[first] <= end))
		first++;
	while (second >= 0 && !(st->a->arr[second] >= start \
	&& st->a->arr[second] <= end))
		second--;
	if (first != st->a->size)
	{
		ft_choose_hold(first, second, st);
		if (st->b->size > 1)
			ft_find_place(st->a->arr[0], st, 1);
		ft_print_command(ft_strdup("pb"), st, 0);
		ft_algo(st, start, end);
	}
}

void	ft_big_algo(t_stack *st, int part)
{
	int i;
	int *sort;
	int size;

	i = 0;
	size = st->a->size;
	sort = ft_sorting_stack(st->a->arr, st->a->size);
	while (++i <= part && !(ft_check_order(st->a, st->b, 0) \
	&& (st->a->arr[st->a->size - 1] == sort[size - 1] && \
	st->a->arr[0] == sort[size - st->a->size])))
	{
		if (i != part)
			ft_algo(st, sort[(size / part) * i - (size / part)], \
			sort[(size / part) * i - 1]);
		else
			ft_algo(st, sort[(size / part) * i - (size / part)], \
			sort[size - 1]);
	}
	ft_put_up(sort[size - 1], st, 1);
	while (st->b->size)
		ft_print_command(ft_strdup("pa"), st, 0);
	free(sort);
}

void	ft_changes(t_stack *st)
{
	if (!ft_check_order(st->a, st->b, 0))
	{
		if (st->a->size == 2)
			ft_print_command(ft_strdup("sa"), st, 0);
		else if (st->a->size > 2 && st->a->size <= 5)
			ft_algo_five_num(st);
		else if (st->a->size > 5 && st->a->size <= 49)
			ft_big_algo(st, 3);
		else if (st->a->size > 49 && st->a->size <= 99)
			ft_big_algo(st, 4);
		else if (st->a->size > 99 && st->a->size <= 200)
			ft_big_algo(st, 5);
		else if (st->a->size > 200 && st->a->size <= 400)
			ft_big_algo(st, 8);
		else if (st->a->size > 400 && st->a->size <= 499)
			ft_big_algo(st, 10);
		else if (st->a->size > 499)
			ft_big_algo(st, 11);
	}
}

int		main(int ac, char **av)
{
	t_stack	*st;
	int		count;

	count = 0;
	if (ac == 1)
		return (0);
	count = ft_count_digit(av, ac);
	if (!(st = ft_create_stack(count)))
		error();
	if (!ft_strcmp(av[1], "-v") || !ft_strcmp(av[1], "-vc") \
	|| !ft_strcmp(av[1], "-cv"))
	{
		if (!ft_strcmp(av[1], "-vc") || !ft_strcmp(av[1], "-cv"))
			st->fl_c = 1;
		st->fl_v = 1;
	}
	st->a->arr = ft_valid_digit(ac, count, av, st->fl_v);
	ft_changes(st);
	ft_delete_stack(st);
	return (0);
}
