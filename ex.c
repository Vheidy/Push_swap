#include "checker.h"
#include <stdio.h>

// void	error()
// {
// 	write(1, "Error\n", 6);
// 	exit(0);
// }

// char	*ft_crop(char *buf, t_stack *st) {
// 	char *begin;
// 	char *str;

// 	// str = *buf;
// 	str = malloc(sizeof(char) * (st->size_A - 1));
// 	begin = str;
// 	// printf("==5==\n");
// 	while (*buf != '\n' && *buf != '\0')
// 		*str++ = *buf++;
// 	*str = '\0';
// 	// printf("==6==\n");
// 	return begin;
// }


// // int		ft_check_order(t_stack *st) {
// // 	return 1;
// // }

// int		ft_read_command(t_stack *st)
// {
// 	int red;
// 	char *command;
// 	char *buf;
// 	int i = 0;

// 	buf = "sa\n";
// 	// buf[2] = '\0';
// 	// buf = ft_strdup("pa\n");
// 	// while ((red = get_next_line(0, &buf))) {
// 		// i = 0;
// 		// printf("----%d----\n", i);
// 		if (!(ft_choose_command(ft_crop(buf, st), st))) // выполнение команды и проверка ее на валидность
// 			error();
// 		while (i < st->size_A)
// 			printf("%d\n", st->stack_A[i++]);
// 		st->flag = 0;
// 	// }
// 	if (ft_check_order(st)) {
// 		write(1, "OK\n", 3);
// 		return 1;
// 	}
// 	write(1, "KO\n", 3);
// 	return 0;
// }

// int	ft_create_struct(t_stack *st, int ac)
// {
// 	if (!(st->stack_A = malloc(sizeof(int) * ac)) || !(st->stack_B = malloc(sizeof(int) * ac)))
// 		return 0;
// 	st->size_A = ac;
// 	st->size_B = 0;
// 	st->flag = 0;
// 	printf("---------\n");
// 	return 1;
// }

// {3, 5, 1, 7, 8, 9}
// 


void	ft_quick_sort(int *stack, int *left, int *right) // принимает size - 1
{
	int *pr;
	int *left_h = left;
	int *right_h = right;
	int *tmp;

	// if ((size + 1) < 2)
	// 	return stack;
	tmp = stack;
	pr = stack;
	
	*tmp = *pr;
	*pr = *right;
	*right = *pr;
	left = left_h;
	right = right_h;
	if (left < pr)
		ft_quick_sort(stack, left, (pr - 1));
	if (right > pr)
		ft_quick_sort(stack, (pr + 1), right);
}


int main(int ac, char **av) {
	// t_stack st;
	int i = 0;
	int *st;
	st = malloc(sizeof(int) * 6);
	st[0] = 7;
	st[1] = 5;
	st[2] = 1;
	st[3] = 8;
	st[4] = 3;
	st[5] = 9;
	int *l = st;
	int *r = st + 5;

	printf("left: %d\nright: %d\n left - right: %ld\n", *l, *r, (r - l));

	printf("------------");
	ft_quick_sort(st, (st + 1), (st + 5));
	while (i < 6) {
		printf("%d\n", st[i++]);
	}
	// if (ac == 1)
	// 	return 0;
	// if (!ft_create_struct(&st, (ac - 1)))
	// 	error();
	// st.stack_A = ft_valid_digit((ac - 1), av);
	// while (i < ac - 1) {
	// 	printf("%d\n", st.stack_A[i++]);
	// }
	// printf("---------\n");
	// i = 0;
	// while (i < ac - 1) {
	// 	printf("%d\n", st.stack_A[i++]);
	// }
	// ft_read_command(&st);
	// 	write(1, "OK\n", 3);
	// }
	// else {
	// 	write(1, "KO\n", 3);
	// }
	return 0;
}