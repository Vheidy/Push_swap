#include "libft/libft.h"
#include <stdio.h>

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

void	ft_print(int *stack, int i)
{
	int с;

	с = 0;
	while (с < i) {
		printf("%d\n", stack[с++]);
	}
	printf("-----\n");
}

int main() {
	int *stack;
	int *stack_B;
	int i = 0;

	stack = malloc(sizeof(int) * 4);
	stack_B = malloc(sizeof(int) * 4);
	stack[0] = 1;
	stack[1] = 2;
	stack[2] = 3;
	stack[3] = 4;

	// ft_reverse_rotate(&stack, 3, &i);
	// ft_print(stack);
	// ft_swap(&stack, 4, &i);
	// ft_print(stack);
	// ft_rotate(&stack, 4, &i);
	// ft_print(stack);
	int fr = 4;
	int wr = 0;
	ft_push(&stack, &stack_B, &fr, &wr);
	ft_print(stack, fr);
	ft_print(stack_B, wr);
	return 0;
}