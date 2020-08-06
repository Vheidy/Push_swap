#include "libft/libft.h"
#include <stdio.h>

int		ft_check_repeat(int *stack, int ac)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < ac) {
		while (j < ac) {
			if (stack[i] == stack[j] && i != j)
				return 0;
			j++;
		}
		j = 0;
		i++;
	}
	return 1;
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

	int x = ft_check_repeat(stack, 4);
	printf("%d\n", x);
	// ft_print(stack);
	// ft_swap(&stack, 4, &i);
	// ft_print(stack);
	// ft_rotate(&stack, 4, &i);
	// ft_print(stack);
	// int fr = 4;
	// int wr = 0;
	// ft_push(&stack, &stack_B, &fr, &wr);
	// ft_print(stack, fr);
	// ft_print(stack_B, wr);
	return 0;
}