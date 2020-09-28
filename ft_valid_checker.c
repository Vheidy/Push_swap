/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_checker.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheidy <vheidy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 17:59:37 by vheidy            #+#    #+#             */
/*   Updated: 2020/09/28 16:29:59 by vheidy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_push_swap.h"



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

char	*ft_check_val(char *str) {
	while (*str == '0')
		str++;
	return str;
}

int		ft_check_digit(char *str)
{
	int i;
	int fl;
	
	i = -1;
	fl = 0;
	// if (str[i] == '-')
	// 	i++;
	while (str[++i] != '\0')
	{
		if (!ft_isdigit(str[i]) && str[i] != ' ' && str[i] != '-')
			return 0;
		if (str[i] == ' ' && ft_isdigit(str[i + 1]))
			fl = 1;
		// printf("%d\n", fl);
		// i++;
	}
	if (fl)
		return 2;
	// printf("--ok--\n");
	if (ft_strlen(ft_check_val(str)) > 12)
		return 0;
	return 1;
}

void	ft_read_string(int *tmp, int ac, char **av, int *count)
{
	int i;
	long long int elem;

	i = ft_strlen(av[ac]);
	while (--i >= 0)
	{
		if ((ft_isdigit(av[ac][i]) && i == 0) || \
			(av[ac][i] == ' ' && ft_isdigit(av[ac][i + 1])) || \
		(av[ac][i] == '-' && av[ac][i - 1] == ' ' && ft_isdigit(av[ac][i + 1])))
		{
			elem = ft_atoi(&av[ac][i]);
			if (elem > 2147483647 || elem < (-2147483647))
				error();
			tmp[(*count)--] = elem;
		}
	}
}

int		*ft_valid_digit(int ac, int count, char **av)
{
	int *tmp;
	long long int ch;
	int i;

	i = count;
	if (!(tmp = malloc(sizeof(int) * count)))
		return NULL;
	while (--count >= 0)
	{
		ch = ft_atoi(av[ac]);
		if (!ft_check_digit(av[ac]) || ch > 2147483647 || ch < (-2147483647))
			error();
		if (ft_check_digit(av[ac]) == 2){
			ft_read_string(tmp, ac, av, &count);
		}
		else{
			tmp[count] = ch;
		}
		ac--;
	}
	if (!ft_check_repeat(tmp, i))
		error();
	return tmp;
}

// int		*ft_valid_digit(int ac, int count, char **av)
// {
// 	int *tmp;
// 	long long int ch;
// 	int i;

// 	i = ac;
// 	if (!(tmp = malloc(sizeof(int) * count)))
// 		return NULL;
// 	while (ac > 0)
// 	{
// 		ch = ft_atoi(av[ac]);
// 		if (!ft_check_digit(av[ac]) || ch > 2147483647 || ch < (-2147483647))
// 			error();
// 		tmp[ac - 1] = ch;
// 		ac--;
// 	}
// 	if (!ft_check_repeat(tmp, i))
// 		error();
// 	return tmp;
// }
