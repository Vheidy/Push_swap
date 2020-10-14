/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheidy <vheidy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 17:47:16 by vheidy            #+#    #+#             */
/*   Updated: 2020/10/13 19:39:41 by vheidy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_push_swap.h"

void	ft_small_free(int **from, int **where, int *size_wr)
{
	free(*from);
	if (*size_wr - 1)
		free(*where);
}

void	ft_read_string(int **tmp, int ac, char **av, int *count)
{
	int				i;
	long long int	elem;
	int				f;

	i = ft_strlen(av[ac]);
	f = 0;
	while (--i >= 0)
	{
		if ((ft_isdigit(av[ac][i]) && !i) || \
		((av[ac][i] == '-' || av[ac][i] == '+') && \
		!i && ft_isdigit(av[ac][i + 1])) || \
		(av[ac][i] == ' ' && ft_isdigit(av[ac][i + 1])) || \
		((av[ac][i] == '-' || av[ac][i] == '+') && \
		av[ac][i - 1] == ' ' && ft_isdigit(av[ac][i + 1])))
		{
			elem = ft_atoi(&av[ac][i]);
			if (elem > 2147483647 || elem < (-2147483648))
				error();
			(*tmp)[(*count)--] = elem;
		}
	}
}
