/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheidy <vheidy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 11:57:19 by vheidy            #+#    #+#             */
/*   Updated: 2020/08/06 19:11:42 by vheidy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
/*задачи:
Доделать считываемость
Сделать проверку на считываемость
Написать проверку на отсортированность в файле валидность
Допилить работу всей программы в целом
*/
/* считывание заканчивается на ctrl + D (EOF) */

void	error()
{
	write(1, "Error\n", 6);
	exit(0);
}

// считывание команд if (read(fd, buf, 0) < 0)

char	*ft_crop(char *buf) {
	int i;
	char *str;

	i = 0;
	while (*buf != '\n') {
		str[i++] = *buf;
		*buf++;
	}
	str[i] = '\0';
	return str;
}





/* чистить буффер каждый раз в конце цикла
должна вернуть 1 в случае если после выполненных действий стэк отсортирован
и 0 если нет
Обнулять флаг 
*/
int		ft_read_command(t_stack *st)
{
	int red;
	char *command;
	
	char buf[5];
	while(red = read(0, buf, 4) > 0) {
		buf[red] = '\0';
		if (!(ft_choose_command(ft_crop(buf), st)))
			error();
		st->flag = 0;
	}
}

void	ft_create_struct(t_stack *st, int ac)
{
	if (!(st->stack_A = malloc(sizeof(int) * ac)) || !(st->stack_B = malloc(sizeof(int) * ac)))
		return NULL;
	st->size_A = ac;
	st->size_B = 0;
	st->flag = 0;
}

int		main(int ac, char **av)
{
	t_stack st;
	int i = 0;

	if (ac == 1)
		return 0;
	ft_create_struct(&st, (ac - 1));
	st.stack_A = ft_valid_digit((ac - 1), av);
	while (i < (ac - 1)) {
		printf("%d\n", st.stack_A[i++]);
	}
	if (ft_read_command(&st)) {
		write(1, "OK\n", 3);
	}
	else {
		write(1, "KO\n", 3);
	}
	return 0;
}
