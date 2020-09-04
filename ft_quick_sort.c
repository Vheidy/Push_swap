/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quick_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheidy <vheidy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 14:25:31 by vheidy            #+#    #+#             */
/*   Updated: 2020/09/03 12:42:30 by vheidy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void	ft_quick_sort(int *begin, int *left, int *right)
{
	int	tmp;
	int	*tmp_right;

	tmp_right = right;
	while (left < right) {
		while (*left < *begin && left < tmp_right)
			left++;
		while (*right > *begin && right > begin)
			right--;
		if (left < right) {
			tmp = *left;
			*left = *right;
			*right = tmp;
		}
	}
	if ((left != right) || (left == right && *begin > *right)) {
		tmp = *begin;
		*begin = *right;
		*right = tmp;
	}
	if (right - begin > 1)
		ft_quick_sort(begin, (begin + 1), (right - 1));
	if (tmp_right - right > 1)
		ft_quick_sort(left, (left + 1), tmp_right);
}

int		main() {
	int arr[3] = {3, 8, 6};
	int *left;
	// int *begin;
	// int *right;
	
	left = malloc(sizeof(int) * 3);
	left = arr;
	left[0] = 4;
	// arr[0] = 2;
	// right = &arr[2];
	// ft_quick_sort(begin, left, right);
	// printf("1\n");
	int x = 0;
	while (x < 3)
		printf("%d\n", arr[x++]);
	// int *tmp = left;
	// printf("First:\nleft: %d\ntmp: %d\n", *left, *tmp);
	// left++;
	// printf("First:\nleft: %d\ntmp: %d\n", *left, *tmp);
	return 0;
}