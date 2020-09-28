/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheidy <vheidy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 11:57:19 by vheidy            #+#    #+#             */
/*   Updated: 2020/09/28 16:44:32 by vheidy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_push_swap.h"
/*задачи:
*/


char	*ft_crop(char *buf, t_stack *st) {
	char *begin;
	char *str;

	// str = *buf;
	str = malloc(sizeof(char) * (st->A->size - 1));
	begin = str;
	while (*buf != '\n' && *buf != '\0')
		*str++ = *buf++;
	*str = '\0';
	return begin;
}

int		ft_read_command(t_stack *st)
{
	int red;
	char *buf;

	while ((red = get_next_line(0, &buf))) {
		if (!(ft_choose_command(ft_crop(buf, st), st->A, st->B, 0))) // выполнение команды и проверка ее на валидность
			error();
		free(buf);
	}
	// free(buf);
	if (ft_check_order(st->A, st->B, 1))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return 0;
}

int		main(int ac, char **av)
{
	t_stack	*st;
	int count;

	if (ac == 1)
		return (0);
	count = ft_count_digit(av, ac);
	if (!(st = ft_create_stack(count)))
		error();
	st->A->arr = ft_valid_digit((ac - 1), count, av);
	ft_read_command(st);
	free(st->A->arr);
	free(st->B->arr);
	return 0;
}

