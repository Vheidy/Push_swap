/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_visual_part_one.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheidy <vheidy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 16:49:57 by vheidy            #+#    #+#             */
/*   Updated: 2020/10/09 22:17:02 by vheidy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_push_swap.h"

void	ft_print_output(char **output)
{
	int i;
	int j;

	i = 0;
	while (output[i])
	{
		j = 0;
		while (output[i][j])
			write(1, &(output[i][j++]), 1);
		write(1, "\n", 1);
		i++;
	}
}

int		ft_check_place(char *str, int i, int j, int end)
{
	if (((!ft_strcmp(str, ft_strdup("pa")) || !ft_strcmp(str, ft_strdup("rra"))\
	|| !ft_strcmp(str, ft_strdup("rrr"))) && i == 1 && j == 1) || \
	((!ft_strcmp(str, ft_strdup("pb")) || !ft_strcmp(str, ft_strdup("rrb")) || \
	!ft_strcmp(str, ft_strdup("rrr"))) && i == 1 && j == 13) || \
	((!ft_strcmp(str, ft_strdup("sa")) || !ft_strcmp(str, ft_strdup("ss"))) \
	&& i == 2 && j == 1) || \
	((!ft_strcmp(str, ft_strdup("sb")) || !ft_strcmp(str, ft_strdup("ss"))) \
	&& i == 2 && j == 13) || \
	((!ft_strcmp(str, ft_strdup("ra")) || !ft_strcmp(str, ft_strdup("rr"))) \
	&& (i == (end - 1) && j == 1)) || \
	((!ft_strcmp(str, ft_strdup("rb")) || !ft_strcmp(str, ft_strdup("rr"))) \
	&& i == (end - 1) && j == 13))
		return (1);
	return (0);
}

void	ft_print_with_color(char **output, int end, char *str)
{
	int i;
	int j;

	i = 0;
	while (output[i])
	{
		j = 0;
		if (!i || i == end)
			write(1, "\x1b[31m", 5);
		else
			write(1, "\x1b[33m", 5);
		while (output[i][j])
		{
			if (ft_check_place(str, i, j, end))
				write(1, "\x1b[32m", 5);
			if ((j == 11 || j == 23) && i && i != end)
				write(1, "\x1b[33m", 5);
			write(1, &output[i][j++], 1);
			if (i == end && j == 24)
				write(1, "\x1b[0m", 5);
		}
		write(1, "\n", 1);
		i++;
	}
}


void	ft_merge_output(char **tmp, char **output, char *str, int size)
{
	char **beg_tmp;
	char **head;

	head = output;
	if (!ft_strcmp(str, ft_strdup("pa")))
		ft_merge_dir(tmp, size, 1);
	else if (!ft_strcmp(str, ft_strdup("pb")))
		ft_merge_dir(tmp, size, 2);
	else if (!ft_strcmp(str, ft_strdup("sa")) || !ft_strcmp(str, ft_strdup("sb")) \
	|| !ft_strcmp(str, ft_strdup("ss")) || !ft_strcmp(str, ft_strdup("rra")) ||
	!ft_strcmp(str, ft_strdup("rrb")) || !ft_strcmp(str, ft_strdup("rrr")))
		ft_merge_dir(tmp, size, 4);
	else if (!ft_strcmp(str, ft_strdup("rb")) || !ft_strcmp(str, ft_strdup("ra")) \
	|| !ft_strcmp(str, ft_strdup("rr")))
		ft_merge_dir(tmp, size, 3);
	// printf("--ok--\n");
	while (*tmp)
	{
		*head = ft_strjoin_free(*tmp, *head, 1, 1);
		tmp++;
	}
}

void	ft_print_command(char *str, t_stack *st, int fl)
{
	int		end;
	int		space;
	char	**output;
	char	**tmp;

	space = 11;
	if (!fl)
	{
		ft_putstr(str);
		write(1, "\n", 1);
		end = (st->a->size > st->b->size) ? st->a->size : st->b->size;
		tmp = (char**)malloc(sizeof(char*) * (end + 3));
		ft_full_output(tmp, st, end);
		if (!ft_choose_command(str, st->a, st->b, 0))
			error();
	}
	if (st->fl_v)
	{
		// end = (st->a->size > st->b->size) ? st->a->size : st->b->size;
		output = (char**)malloc(sizeof(char*) * (end + 3));
		ft_full_output(output, st, end);
		ft_merge_output(tmp, output, str, end + 3);
		
		if (!st->fl_c)
			ft_print_output(output);
		else
			ft_print_with_color(output, end + 1, str);
	}
	free(str);
}
//   |          
//   |     -- -- > |
//  \|/     ^     \|/
//   v     /|\     v      
//          |            |
//  ,,,,,,,

//    .            .
//    .      . . . . .
//  . . .          . 
//    .       
//       . 
// . . . . .
//       .
	  