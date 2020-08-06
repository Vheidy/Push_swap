/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_command_checker.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheidy <vheidy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 17:57:42 by vheidy            #+#    #+#             */
/*   Updated: 2020/08/06 18:55:06 by vheidy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_swap(int **stack, int size, int *fl) // принимает size полный
{
	int tmp;
	
	*fl = 1;
	if (size > 1) {
		tmp = (*stack)[0];
		(*stack)[0] = (*stack)[1];
		(*stack)[1] = tmp;
	}
}

void	ft_rotate(int **stack, int size, int *fl) // принимает size полный
{
	int first;
	int *tmp;
	int *begin;

	*fl = 1;
	if (size > 1) {
		first = *stack[0];
		tmp = *stack;
		begin = tmp;
		while (--size) {
			*tmp = *(tmp + 1);
			tmp++;
		}
		*tmp = first;
		*stack = begin;
	}
}

void	ft_reverse_rotate(int **stack, int size, int *fl) // принимает size - 1
{
	int last;
	int *tmp;
	int *begin;

	*fl = 1;
	if (size > 1) {
		last = (*stack)[size];
		tmp = *stack;
		begin = tmp;
		while (size) {
			tmp[size] = tmp[size - 1];
			size--;
		}
		tmp[0] = last;
		*stack = begin;
	}
}
// push a: b->a || push b: a->b || при пуш изменяется размер каждого из стеков
// элеметы массивов интов не удаляются, а сдвигаются || нужно ходить до size

void	ft_push(int **from, int **where, int *size_fr, int *size_wr) // принимает size полный
{
	int c;

	c = 0;
	if (size_fr > 0) {
		ft_reverse_rotate(where, (*size_wr - 1), &c);
		*where[0] = *from[0];
		*size_wr += 1;
		ft_rotate(from, *size_fr, &c);
		*size_fr -= 1;
	}
}


int	ft_choose_command(char *str, t_stack *st)
{
	if (str == "sa" || str == "ss")
		ft_swap(&st->stack_A, st->size_A, &st->flag);
	if (str == "sb" || str == "ss")
		ft_swap(&st->stack_B, st-> size_B, &st->flag);
	if (str == "pa" || str == "pb")
		st->flag = 1;
	if (str == "pa")
		ft_push(&st->stack_B, &st->stack_A, &st->size_B, &st->size_A);
	if (str == "pb")
		ft_push(&st->stack_A, &st->stack_B, &st->size_A, &st->size_B);
	if (str == "ra" || str == "rr")
		ft_rotate(&st->stack_A, st->size_A, &st->flag);
	if (str == "rb" || str == "rr")
		ft_rotate(&st->stack_B, st->size_B, &st->flag);
	if (str == "rra" || str == "rrr")
		ft_reverse_rotate(&st->stack_A, st->size_A, &st->flag);
	if (str == "rrb" || str == "rrr")
		ft_reverse_rotate(&st->stack_B, st->size_B, &st->flag);
	if (!st->flag)
		return 0;
	return 1;
}