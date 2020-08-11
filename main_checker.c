/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheidy <vheidy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 11:57:19 by vheidy            #+#    #+#             */
/*   Updated: 2020/08/11 17:59:57 by vheidy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
/*задачи:
Починить кроп
Написать проверку на отсортированность в файле валидность
Допилить работу всей программы в целом
*/

void	error()
{
	write(1, "Error\n", 6);
	exit(0);
}

char	*ft_crop(char *buf, t_stack *st) {
	char *begin;
	char *str;

	// str = *buf;
	str = malloc(sizeof(char) * (st->size_A - 1));
	begin = str;
	while (*buf != '\n' && *buf != '\0')
		*str++ = *buf++;
	*str = '\0';
	return begin;
}

// char	*ft_crop(char *buf) {
// 	int i;
// 	char *str;

// 	i = 0;
// 	printf("==5==\n");
// 	while (buf[i] != '\n' && buf[i] != '\0') {
// 		str[i] = buf[i];
// 		i++;
// 	}
// 	str[i] = '\0';
// 	printf("==6==\n");
// 	return str;
// }




/* чистить буффер каждый раз в конце цикла
должна вернуть 1 в случае если после выполненных действий стэк отсортирован
и 0 если нет
Обнулять флаг 
*/
int		ft_read_command(t_stack *st)
{
	int red;
	char *command;
	char *buf;

	// printf("----4----\n");
	while ((red = get_next_line(0, &buf))) {
		// printf("==5==\n");
		if (!(ft_choose_command(ft_crop(buf, st), st))) // выполнение команды и проверка ее на валидность
			error();
			// printf("==6==\n");
		st->flag = 0;
	}
	if (ft_check_order(st)) {
		write(1, "OK\n", 3);
	}
	else {
		write(1, "KO\n", 3);
	}
	return 0;
}

int	ft_create_struct(t_stack *st, int ac)
{
	if (!(st->stack_A = malloc(sizeof(int) * ac)) || !(st->stack_B = malloc(sizeof(int) * ac)))
		return 0;
	st->size_A = ac;
	st->size_B = 0;
	st->flag = 0;
	return 1;
}

int		main(int ac, char **av)
{
	t_stack st;
	int i = 0;

	if (ac == 1)
		return 0;
	printf("==1==\n");
	if (!ft_create_struct(&st, (ac - 1)))
		error();
	printf("==2==\n");
	st.stack_A = ft_valid_digit((ac - 1), av);
	printf("==3==\n");
	// while (i < (ac - 1)) {
	// 	printf("%d\n", st.stack_A[i++]);
	// }
	ft_read_command(&st);
	return 0;
}
