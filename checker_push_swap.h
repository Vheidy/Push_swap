/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_push_swap.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheidy <vheidy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 14:29:48 by vheidy            #+#    #+#             */
/*   Updated: 2020/09/25 18:52:22 by vheidy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_PUSH_SWAP_H
# define CHECKER_PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "libft/libft.h"

// typedef struct		s_stack {
// 	int				*stack_A;
// 	int				*stack_B;
// 	int				size_A;
// 	int				size_B;
// 	int				flag;
// }					t_stack;
typedef struct		s_chunk
{
	int				*arr;
	int				size;
}					t_chunk;

typedef struct		s_stack
{
	t_chunk			*A;
	t_chunk			*B;
}					t_stack;



typedef struct		s_lst
{
	t_chunk			*ch;
	struct s_lst	*next;
	struct s_lst	*before;
}					t_lst;

int		ft_check_back_order(t_chunk *tmp_st);
t_stack	*ft_create_stack(int ac);
t_lst	*ft_new_list(int content_size, t_lst *before);
void	ft_print_command(char *str, t_stack *st, t_lst *A, t_lst *B);
int		*ft_sorting_stack(int *stack, int size);
void	ft_push(int **from, int **where, int *size_fr, int *size_wr);
int		ft_check_order(t_chunk *A, t_chunk *B, int fl);
int		ft_choose_command(char *str, t_chunk *stack_A, t_chunk *stack_B, int flag);
// int		ft_choose_command(char *str, t_stack *st);
int		*ft_valid_digit(int ac, char **av);
void	error();
int		ft_create_struct(t_stack *st, int ac);

#endif
