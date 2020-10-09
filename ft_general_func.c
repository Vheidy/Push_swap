/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_general_func.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheidy <vheidy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 08:14:14 by vheidy            #+#    #+#             */
/*   Updated: 2020/10/09 16:57:28 by vheidy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_push_swap.h"

int		ft_check_back_order(t_chunk *tmp_st)
{
	int i;

	i = 0;
	while (i + 1 < tmp_st->size)
	{
		if (tmp_st->arr[i] < tmp_st->arr[i + 1])
			return (0);
		i++;
	}
	return (1);
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

int		ft_check_order(t_chunk *a, t_chunk *b, int fl)
{
	int i;

	i = 0;
	if (b->size && fl)
		return (0);
	while (i + 1 < a->size)
	{
		if (a->arr[i] > a->arr[i + 1])
			return (0);
		i++;
	}
	return (1);
}
