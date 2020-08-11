/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheidy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 18:18:22 by vheidy            #+#    #+#             */
/*   Updated: 2019/09/17 19:51:31 by vheidy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	str[11];
	int		i;

	i = 0;
	if (n < 0)
		ft_putchar_fd('-', fd);
	while (n >= 10 || n <= -10)
	{
		if (n > 0)
			str[i++] = n % 10 + '0';
		else
			str[i++] = n % 10 * -1 + '0';
		n = n / 10;
	}
	if (n < 0)
		n = n * -1;
	str[i] = n % 10 + '0';
	while (i >= 0)
		ft_putchar_fd(str[i--], fd);
}
