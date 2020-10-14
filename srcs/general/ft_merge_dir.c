/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_merge_dir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheidy <vheidy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 21:38:00 by vheidy            #+#    #+#             */
/*   Updated: 2020/10/12 15:58:52 by vheidy           ###   ########.fr       */
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

void	ft_create_dir(int i, int j, char **dir, int fl)
{
	if (fl == 1 && ((i == 0 && j == 2) || (i == 1 && j == 1) || \
	(i == 1 && j == 3) || (i == 1 && j == 5) || \
	(i == 1 && j == 7) || (i == 1 && j == 9) || (i == 2 && j == 2)))
		dir[i][j] = '.';
	else if (fl == 2 && ((i == 0 && j == 8) || (i == 1 && j == 1) || \
	(i == 1 && j == 3) || (i == 1 && j == 5) || \
	(i == 1 && j == 7) || (i == 1 && j == 9) || (i == 2 && j == 8)))
		dir[i][j] = '.';
	else if (fl == 3 && ((i == 0 && j == 5) || (i == 1 && j == 7) || \
	(i == 1 && j == 3) || (i == 1 && j == 5) || \
	(i == 2 && j == 5) || (i == 3 && j == 5)))
		dir[i][j] = '.';
	else if (fl == 4 && ((i == 0 && j == 5) || (i == 2 && j == 5) || \
	(i == 2 && j == 3) || (i == 1 && j == 5) || \
	(i == 2 && j == 7) || (i == 3 && j == 5)))
		dir[i][j] = '.';
	else
		dir[i][j] = ' ';
}

void	ft_merge(char ***dir, char ***tmp)
{
	while (**dir)
	{
		**tmp = ft_strjoin_free_all(*tmp, *dir);
		(*tmp)++;
		(*dir)++;
	}
}

void	ft_merge_dir(char **str, int size, int fl)
{
	int		i;
	int		j;
	char	**dir;
	char	**tmp;
	char	**head;

	i = -1;
	tmp = str;
	dir = (char**)malloc(sizeof(char*) * size);
	head = dir;
	while (++i < size - 1)
	{
		j = -1;
		dir[i] = (char*)malloc(sizeof(char) * 12);
		while (++j < 11)
			ft_create_dir(i, j, dir, fl);
		dir[i][j] = '\0';
	}
	dir[size - 1] = NULL;
	ft_merge(&dir, &tmp);
	free(head);
}

void	ft_merge_output(char **tmp, char **output, char *str, int size)
{
	char **head;

	head = output;
	if (!ft_strcmp(str, "pa"))
		ft_merge_dir(tmp, size, 1);
	else if (!ft_strcmp(str, "pb"))
		ft_merge_dir(tmp, size, 2);
	else if (!ft_strcmp(str, "sa") || !ft_strcmp(str, "sb") \
	|| !ft_strcmp(str, "ss") || !ft_strcmp(str, "rra") ||
	!ft_strcmp(str, "rrb") || !ft_strcmp(str, "rrr"))
		ft_merge_dir(tmp, size, 4);
	else if (!ft_strcmp(str, "rb") || !ft_strcmp(str, "ra") \
	|| !ft_strcmp(str, "rr"))
		ft_merge_dir(tmp, size, 3);
	while (*tmp)
	{
		*head = ft_strjoin_free_all(tmp, head);
		tmp++;
		head++;
	}
}
