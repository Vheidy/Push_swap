/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_checker.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheidy <vheidy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 17:59:37 by vheidy            #+#    #+#             */
/*   Updated: 2020/10/13 17:51:09 by vheidy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_push_swap.h"

int		ft_check_repeat(int *stack, int ac)
{
	int i;
	int j;

	i = -1;
	while (++i < ac)
	{
		j = -1;
		while (++j < ac)
		{
			if (stack[i] == stack[j] && i != j)
				return (0);
		}
	}
	return (1);
}

char	*ft_check_val(char *str)
{
	if (*str == '+' || *str == '-')
		str++;
	while (*str == '0' || *str == ' ')
		str++;
	return (str);
}

int		ft_check_digit(char *str, int *f)
{
	int i;
	int fl;

	i = -1;
	fl = 0;
	while (str[++i] != '\0')
	{
		if (ft_isdigit(str[i]))
			*f = 1;
		if (!ft_isdigit(str[i]) && str[i] != ' ' && \
		!((str[i] == '-' || str[i] == '+') && ft_isdigit(str[i + 1])))
			return (0);
		if (str[i] == ' ' && ft_isdigit(str[i + 1]))
			fl = 1;
	}
	if (fl)
		return (2);
	if (ft_strlen(ft_check_val(str)) > 12)
		return (0);
	return (1);
}

void	ft_cycle(char **av, int ac, int **tmp, int *count)
{
	int				f;
	long long int	ch;

	f = 0;
	ch = ft_atoi(av[ac]);
	if (!ft_check_digit(av[ac], &f) || ch > 2147483647 || ch < (-2147483648))
		error();
	if (ft_check_digit(av[ac], &f) == 2)
		ft_read_string(tmp, ac, av, count);
	else if (f)
	{
		(*tmp)[*count] = ch;
		(*count)--;
	}
}

int		*ft_valid_digit(int ac, int count, char **av, int fl)
{
	int				*tmp;
	int				i;
	int				end;

	i = count;
	end = (fl) ? 1 : 0;
	if (!(tmp = malloc(sizeof(int) * count)))
		return (NULL);
	count--;
	while (--ac > end)
		ft_cycle(av, ac, &tmp, &count);
	if (!ft_check_repeat(tmp, i))
		error();
	return (tmp);
}
