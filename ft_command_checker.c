/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_command_checker.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheidy <vheidy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 17:57:42 by vheidy            #+#    #+#             */
/*   Updated: 2020/10/06 18:22:13 by vheidy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_push_swap.h"

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
	if (size > 0) {
		last = (*stack)[size];
		tmp = *stack;
		begin = tmp;
		if (!size)
			tmp[size + 1] = tmp[size];
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

void	ft_push(int **from, int **where, int *size_fr, int *size_wr)
{
	int tmp;
	int *new_from;
	int *new_where;
	int j;
	int i;
	
	i = -1;
	j = 0;
	*size_fr -= 1;
	*size_wr += 1;
	tmp = (*from)[0];
	new_from = malloc(sizeof(int) * (*size_fr));
	while (++i < *size_fr)
		new_from[i] = (*from)[i + 1];
	new_where = malloc(sizeof(int) * (*size_wr));
	new_where[j] = tmp;
	while (++j < *size_wr)
		new_where[j] = (*where)[j - 1];
	free(*from);
	if (*size_wr - 1)
		free(*where);
	*from = new_from;
	*where = new_where;
}

// void	ft_push(int **from, int **where, int *size_fr, int *size_wr) // принимает size полный
// {
// 	int c;

// 	c = 0;
// 	if (*size_fr > 0) {
// 		ft_reverse_rotate(where, (*size_wr - 1), &c);
// 		(*where)[0] = (*from)[0];
// 		*size_wr += 1;
// 		ft_rotate(from, *size_fr, &c);
// 		*size_fr -= 1;
// 	}
// }


int	ft_choose_command(char *str, t_chunk *stack_A, t_chunk *stack_B, int flag)
{
	if (!ft_strcmp(str, "sa") || !ft_strcmp(str,"ss"))
		ft_swap(&stack_A->arr, stack_A->size, &flag);
	if (!ft_strcmp(str, "sb") || !ft_strcmp(str, "ss"))
		ft_swap(&stack_B->arr, stack_B->size, &flag);
	if (!ft_strcmp(str, "pa") || !ft_strcmp(str, "pb"))
		flag = 1;
	if (!ft_strcmp(str, "pa"))
		ft_push(&stack_B->arr, &stack_A->arr, &stack_B->size, &stack_A->size);
	if (!ft_strcmp(str, "pb"))
		ft_push(&stack_A->arr, &stack_B->arr, &stack_A->size, &stack_B->size);
	if (!ft_strcmp(str, "ra") || !ft_strcmp(str, "rr"))
		ft_rotate(&stack_A->arr, stack_A->size, &flag);
	if (!ft_strcmp(str, "rb") || !ft_strcmp(str, "rr"))
		ft_rotate(&stack_B->arr, stack_B->size, &flag);
	if (!ft_strcmp(str, "rra") || !ft_strcmp(str, "rrr"))
		ft_reverse_rotate(&stack_A->arr, (stack_A->size - 1), &flag);
	if (!ft_strcmp(str, "rrb") || !ft_strcmp(str, "rrr"))
		ft_reverse_rotate(&stack_B->arr, (stack_B->size - 1), &flag);
	if (!flag)
		return 0;
	free(str);
	return 1;
}