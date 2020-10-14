/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_visual_part_one.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheidy <vheidy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 16:49:57 by vheidy            #+#    #+#             */
/*   Updated: 2020/10/12 16:08:21 by vheidy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_push_swap.h"

int		ft_check_place_green(char *str, int i, int j, int end)
{
	if ((i == 1 && j == 38 && (!ft_strcmp(str, "pa") || \
	!ft_strcmp(str, "rra") || !ft_strcmp(str, "rrr"))) || \
	(i == 1 && j == 51 && (!ft_strcmp(str, "pb") || \
	!ft_strcmp(str, "rrb") || !ft_strcmp(str, "rrr"))) || \
	(i == 2 && j == 38 && (!ft_strcmp(str, "sa") || \
	!ft_strcmp(str, "ss"))) || (i == 2 && j == 51 && \
	(!ft_strcmp(str, "sb") || !ft_strcmp(str, "ss"))) || \
	(i == end - 1 && j == 38 && (!ft_strcmp(str, "ra") || \
	!ft_strcmp(str, "rr"))) || (i == end - 1 && j == 51 && \
	(!ft_strcmp(str, "rb") || !ft_strcmp(str, "rr"))))
		return (1);
	return (0);
}

int		ft_check_place_blue(char *str, int i, int j, int end)
{
	if ((i == 1 && j == 1 && (!ft_strcmp(str, "pb") || \
	!ft_strcmp(str, "ra") || !ft_strcmp(str, "sa") \
	|| !ft_strcmp(str, "ss") || !ft_strcmp(str, "rr"))) ||
	(i == end - 1 && j == 1 && (!ft_strcmp(str, "rra") || \
	!ft_strcmp(str, "rrr"))) || (i == 1 && j == 14 && \
	(!ft_strcmp(str, "pa") || !ft_strcmp(str, "ss") || \
	!ft_strcmp(str, "rb") || !ft_strcmp(str, "sb") || \
	!ft_strcmp(str, "rr"))) || (i == end - 1 && j == 14 && \
	(!ft_strcmp(str, "rrb") || !ft_strcmp(str, "rrr"))))
		return (1);
	return (0);
}

void	ft_check_place(char *str, int i, int j, int end)
{
	if (ft_check_place_green(str, i, j, end) || ((j == 26) && \
	(!i || i == 1 || i == 2 || i == 3)))
		write(1, ANSI_GREEN, 5);
	else if (ft_check_place_blue(str, i, j, end))
		write(1, ANSI_BLUE, 5);
	else if ((j == 12 || j == 25 || j == 36 || j == 49 || \
	j == 62) && i && i != end)
		write(1, ANSI_YELLOW, 5);
	if ((!i || i == end) && (!j || j == 35))
		write(1, ANSI_RED, 5);
}

void	ft_print_with_color(char **output, int end, char *str)
{
	int i;
	int j;

	i = 0;
	while (output[i])
	{
		j = 0;
		if ((!i || i == end))
			write(1, ANSI_RED, 5);
		else
			write(1, ANSI_YELLOW, 5);
		while (output[i][j])
		{
			ft_check_place(str, i, j, end);
			write(1, &output[i][j++], 1);
			if (i == end && j == 63)
				write(1, ANSI_RESET, 5);
		}
		write(1, "\n", 1);
		i++;
	}
}

void	ft_print_command(char *str, t_stack *st, int fl)
{
	int		end;
	char	**tmp;

	tmp = NULL;
	if (!fl)
	{
		ft_putstr(str);
		write(1, "\n", 1);
	}
	end = (st->a->size > st->b->size) ? st->a->size : st->b->size;
	if ((!ft_strcmp(str, "pa") && end == st->a->size) || \
	(!ft_strcmp(str, "pb") && end == st->b->size))
		end++;
	tmp = (char**)malloc(sizeof(char*) * (end + 3));
	tmp = ft_full_output(tmp, st, end);
	if (!ft_choose_command(str, st->a, st->b, 0))
		error();
	if (st->fl_v)
		ft_create_output(end, st, tmp, str);
	if (tmp && !st->fl_v)
		ft_free_delim(&tmp);
	else if (st->fl_v)
		free(tmp);
	ft_strdel(&str);
}
