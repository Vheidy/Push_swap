/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorithm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheidy <vheidy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 19:14:23 by vheidy            #+#    #+#             */
/*   Updated: 2020/10/09 19:47:21 by vheidy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_push_swap.h"

void	ft_put_up(int elem, t_stack *st, int fl)
{
	int		pos;
	t_chunk *tmp;

	pos = -1;
	tmp = (fl) ? st->b : st->a;
	while (++pos < tmp->size)
		if (tmp->arr[pos] == elem)
			break ;
	if (pos <= tmp->size / 2)
		while (pos--)
			if (!fl)
				ft_print_command(ft_strdup("ra"), st, 0);
			else
				ft_print_command(ft_strdup("rb"), st, 0);
	else
		while (tmp->size - (pos++))
			if (!fl)
				ft_print_command(ft_strdup("rra"), st, 0);
			else
				ft_print_command(ft_strdup("rrb"), st, 0);
}

void	ft_find_max_less(int elem, int curr, int *fl, int *max_less)
{
	if (curr < elem)
	{
		if (!*fl)
		{
			*max_less = curr;
			*fl = 1;
		}
		else if (*fl && curr > *max_less)
			*max_less = curr;
	}
}

void	ft_find_place(int elem, t_stack *st, int f)
{
	int		i;
	int		max_less;
	int		fl;
	int		*sort;
	t_chunk	*tmp;

	i = -1;
	fl = 0;
	max_less = 0;
	tmp = (!f) ? st->a : st->b;
	while (++i < tmp->size)
		ft_find_max_less(elem, tmp->arr[i], &fl, &max_less);
	if (fl)
		ft_put_up(max_less, st, f);
	else
	{
		sort = ft_sorting_stack(tmp->arr, tmp->size);
		ft_put_up(sort[tmp->size - 1], st, f);
		free(sort);
	}
}
