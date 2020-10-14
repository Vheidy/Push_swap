/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_delim.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheidy <vheidy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 17:56:28 by vheidy            #+#    #+#             */
/*   Updated: 2020/10/11 18:23:11 by vheidy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_delim(char ***tmp)
{
	int i;

	i = 0;
	while ((*tmp)[i])
		ft_strdel(&(*tmp)[i++]);
	free(*tmp);
	*tmp = NULL;
}
