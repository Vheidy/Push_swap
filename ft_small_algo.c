/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_small_algo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheidy <vheidy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 19:18:17 by vheidy            #+#    #+#             */
/*   Updated: 2020/10/09 19:22:21 by vheidy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_push_swap.h"

int		ft_min_in_max(int elem, t_chunk *st)
{
	int i;
	int *sort;

	i = -1;
	sort = ft_sorting_stack(st->arr, st->size);
	while (++i < st->size)
		if (sort[i] > elem)
			return (sort[i]);
	return (0);
}

void	ft_min_up(t_stack *st, int pos)
{
	if (pos <= st->a->size / 2)
		while (pos--)
			ft_print_command(ft_strdup("ra"), st, 0);
	else
		while (st->a->size - (pos++))
			ft_print_command(ft_strdup("rra"), st, 0);
}

int		ft_find_pos(int elem, t_chunk *st)
{
	int pos;

	pos = 0;
	while (pos < st->size)
	{
		if (st->arr[pos] == elem)
			return (pos);
		pos++;
	}
	return (0);
}

void	ft_algo_three_num(t_stack *st)
{
	while (!ft_check_order(st->a, st->b, 0))
	{
		if (st->a->arr[0] > st->a->arr[2])
			ft_print_command(ft_strdup("ra"), st, 0);
		else if (st->a->arr[0] > st->a->arr[1])
			ft_print_command(ft_strdup("sa"), st, 0);
		else
			ft_print_command(ft_strdup("rra"), st, 0);
	}
}

void	ft_algo_five_num(t_stack *st)
{
	int *sort;
	int pos;

	if (!ft_check_order(st->a, st->b, 0))
	{
		sort = ft_sorting_stack(st->a->arr, st->a->size);
		while (st->a->size > 3)
			ft_print_command(ft_strdup("pb"), st, 0);
		ft_algo_three_num(st);
		while (st->b->size)
		{
			pos = ft_min_in_max(st->b->arr[0], st->a);
			ft_min_up(st, ft_find_pos(pos, st->a));
			ft_print_command(ft_strdup("pa"), st, 0);
		}
		ft_min_up(st, ft_find_pos(sort[0], st->a));
	}
}
