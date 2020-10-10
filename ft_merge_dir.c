/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_merge_dir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheidy <vheidy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 21:38:00 by vheidy            #+#    #+#             */
/*   Updated: 2020/10/10 23:04:18 by vheidy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_push_swap.h"

void	ft_create_dir(int i, int j, char **dir, int fl)
{
	if (fl  == 1 && ((i == 0 && j == 2) || (i == 1 && j == 1) || \
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

void	ft_merge_dir(char **str, int size, int fl)
{
	int		i;
	int		j;
	char	**dir;
	char	**tmp;

	i = -1;
	tmp = str;
	dir = (char**)malloc(sizeof(char*) * size);
	while (++i < size - 1)
	{
		j = -1;
		dir[i] = (char*)malloc(sizeof(char) * 12);
		while(++j < 11)
			ft_create_dir(i, j, dir, fl);
		dir[i][j] = '\0';
	}
	dir[size - 1] = NULL;
	while (*dir)
	{
		*tmp = ft_strjoin_free(*tmp, *dir, 0, 1);
		tmp++;
		dir++;
	}
}