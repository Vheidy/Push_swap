/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheidy <vheidy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 11:57:19 by vheidy            #+#    #+#             */
/*   Updated: 2020/10/09 17:20:57 by vheidy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_push_swap.h"

char	*ft_crop(char *buf)
{
	char *begin;
	char *str;

	str = malloc(sizeof(char) * ft_strlen(buf) + 1);
	begin = str;
	while (*buf != '\n' && *buf != '\0')
		*str++ = *buf++;
	*str = '\0';
	return (begin);
}

int		ft_read_command(t_stack *st)
{
	int		red;
	char	*buf;
	char	*str;

	while ((red = get_next_line(0, &buf)))
	{
		if (!(ft_choose_command((str = ft_crop(buf)), st->a, st->b, 0)))
			error();
		ft_print_command(str, st, 1);
		free(buf);
	}
	if (ft_check_order(st->a, st->b, 1))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return (0);
}

int		main(int ac, char **av)
{
	t_stack	*st;
	int		count;

	if (ac == 1)
		return (0);
	count = ft_count_digit(av, ac);
	if (!(st = ft_create_stack(count)))
		error();
	if (!ft_strcmp(av[1], "-v") || !ft_strcmp(av[1], "-vc") \
	|| !ft_strcmp(av[1], "-cv"))
	{
		if (!ft_strcmp(av[1], "-vc") || !ft_strcmp(av[1], "-cv"))
			st->fl_c = 1;
		st->fl_v = 1;
	}
	st->a->arr = ft_valid_digit(ac, count, av, st->fl_v);
	ft_read_command(st);
	ft_delete_stack(st);
	return (0);
}
