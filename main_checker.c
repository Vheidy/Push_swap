/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheidy <vheidy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 11:57:19 by vheidy            #+#    #+#             */
/*   Updated: 2020/08/12 08:48:49 by vheidy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_push_swap.h"
/*задачи:
*/


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

int		ft_read_command(t_stack *st)
{
	int red;
	char *command;
	char *buf;

	while ((red = get_next_line(0, &buf))) {
		if (!(ft_choose_command(ft_crop(buf, st), st))) // выполнение команды и проверка ее на валидность
			error();
		free(buf);
		st->flag = 0;
	}
	// free(buf);
	if (ft_check_order(st))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return 0;
}



int		main(int ac, char **av)
{
	t_stack st;
	int i = 0;

	if (ac == 1)
		return 0;
	if (!ft_create_struct(&st, (ac - 1)))
		error();
	st.stack_A = ft_valid_digit((ac - 1), av);
	ft_read_command(&st);
	free(st.stack_A);
	free(st.stack_B);
	return 0;
}
