/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_small_algo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheidy <vheidy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 19:18:17 by vheidy            #+#    #+#             */
/*   Updated: 2020/10/12 18:53:33 by vheidy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_push_swap.h"

void	ft_find_min_more(int elem, int curr, int *fl, int *min_more)
{
	if (curr > elem)
	{
		if (!*fl)
		{
			*min_more = curr;
			*fl = 1;
		}
		else if (*fl && curr < *min_more)
			*min_more = curr;
	}
}

void	ft_find_and_up(int elem, t_stack *st)
{
	int		i;
	int		min_more;
	int		fl;
	int		*sort;

	i = -1;
	fl = 0;
	min_more = 0;
	while (++i < st->a->size)
		ft_find_min_more(elem, st->a->arr[i], &fl, &min_more);
	if (fl)
		ft_put_up(min_more, st, 0);
	else
	{
		sort = ft_sorting_stack(st->a->arr, st->a->size);
		ft_put_up(sort[0], st, 0);
		free(sort);
	}
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

	if (!ft_check_order(st->a, st->b, 0))
	{
		sort = ft_sorting_stack(st->a->arr, st->a->size);
		while (st->a->size > 3)
			ft_print_command(ft_strdup("pb"), st, 0);
		ft_algo_three_num(st);
		while (st->b->size)
		{
			ft_find_and_up(st->b->arr[0], st);
			ft_print_command(ft_strdup("pa"), st, 0);
		}
		ft_put_up(sort[0], st, 0);
		free(sort);
	}
}
