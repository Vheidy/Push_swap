/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_visual_part_two.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheidy <vheidy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 18:17:47 by vheidy            #+#    #+#             */
/*   Updated: 2020/10/11 20:41:08 by vheidy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_push_swap.h"

void	ft_full_elem(int space, char **res, int *i, int elem)
{
	char *str_elem;
	char *beg;

	str_elem = ft_itoa(elem);
	beg = str_elem;
	while (*str_elem)
		(*res)[(*i)++] = *str_elem++;
	free(beg);
	while (space-- - ft_int_len(elem))
		(*res)[(*i)++] = ' ';
}

void	ft_full_part(char **str, int elem, int fl)
{
	int		space;
	int		i;
	char	*res;

	i = 0;
	space = 11;
	res = (char *)malloc(sizeof(char) * 14);
	res[i++] = '|';
	if (!fl)
		ft_full_elem(space, &res, &i, elem);
	else
		while (space--)
			res[i++] = ' ';
	res[i++] = '|';
	res[i] = '\0';
	*str = ft_strjoin_free_all(str, &res);
}

void	ft_create_parts(int i, t_stack *st, char **output)
{
	if (i <= st->a->size && i <= st->b->size)
	{
		ft_full_part(&output[i], st->a->arr[i - 1], 0);
		ft_full_part(&output[i], st->b->arr[i - 1], 0);
	}
	else if (i <= st->a->size)
	{
		ft_full_part(&output[i], st->a->arr[i - 1], 0);
		ft_full_part(&output[i], 0, 1);
	}
	else if (i <= st->b->size)
	{
		ft_full_part(&output[i], 0, 1);
		ft_full_part(&output[i], st->b->arr[i - 1], 0);
	}
	else
	{
		ft_full_part(&output[i], 0, 1);
		ft_full_part(&output[i], 0, 1);
	}
}

char	**ft_full_output(char **output, t_stack *st, int end)
{
	int		i;
	char	**tmp;

	i = 0;
	tmp = output;
	tmp[end + 2] = NULL;
	while (++i < end + 1)
		tmp[i] = ft_strnew(27);
	i = 0;
	tmp[0] = ft_strdup("-----A------  -----B------");
	while (++i < end + 1)
		ft_create_parts(i, st, tmp);
	tmp[i] = ft_strdup("--------------------------");
	return (tmp);
}

void	ft_create_output(int end, t_stack *st, char **tmp, char *str)
{
	char **output;

	output = (char**)malloc(sizeof(char*) * (end + 3));
	ft_full_output(output, st, end);
	ft_merge_output(tmp, output, str, end + 3);
	if (!st->fl_c)
		ft_print_output(output);
	else
		ft_print_with_color(output, end + 1, str);
	ft_free_delim(&output);
}
