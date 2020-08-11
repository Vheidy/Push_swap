/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheidy <vheidy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 14:29:48 by vheidy            #+#    #+#             */
/*   Updated: 2020/08/11 17:24:43 by vheidy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "libft/libft.h"

typedef struct		s_stack {
	int				*stack_A;
	int				*stack_B;
	int				size_A;
	int				size_B;
	int				flag;
}					t_stack;

int		ft_choose_command(char *str, t_stack *st);
int		*ft_valid_digit(int ac, char **av);
void	error();
int		ft_check_order(t_stack *st);

#endif
