/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_struct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheidy <vheidy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 16:43:59 by vheidy            #+#    #+#             */
/*   Updated: 2020/10/09 17:27:17 by vheidy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_push_swap.h"

void	error(void)
{
	write(1, "Error\n", 6);
	exit(0);
}

int		ft_create_chunk(t_chunk *st, int ac)
{
	if (!(st->arr = malloc(sizeof(int) * ac)))
		return (0);
	st->size = ac;
	return (1);
}

int		ft_count_digit(char **av, int ac)
{
	int	i;
	int	count;

	count = 0;
	while (--ac)
	{
		i = -1;
		while (av[ac][++i])
			if ((ft_isdigit(av[ac][i]) && i == 0) ||\
			(i == 0 && av[ac][i] == '-' && ft_isdigit(av[ac][i + 1])) \
			|| (av[ac][i] == ' ' && ft_isdigit(av[ac][i + 1])) || \
			(av[ac][i] == '-' && i > 0 && av[ac][i - 1] == ' ' \
			&& ft_isdigit(av[ac][i + 1])))
				count++;
	}
	return (count);
}

t_stack	*ft_create_stack(int ac)
{
	t_stack *st;

	if (!(st = (t_stack *)malloc(sizeof(t_stack))) \
	|| !(st->a = (t_chunk *)malloc(sizeof(t_chunk))) \
	|| !(st->b = (t_chunk *)malloc(sizeof(t_chunk))))
		return (NULL);
	st->a->size = ac;
	st->b->size = 0;
	st->fl_v = 0;
	st->fl_c = 0;
	return (st);
}

void	ft_delete_stack(t_stack *st)
{
	if (st->a->size)
		free(st->a->arr);
	if (st->b->size)
		free(st->b->arr);
	free(st->b);
	free(st->a);
	free(st);
}
