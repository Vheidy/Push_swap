/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_push_swap.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheidy <vheidy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 14:29:48 by vheidy            #+#    #+#             */
/*   Updated: 2020/10/10 23:42:14 by vheidy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_PUSH_SWAP_H
# define CHECKER_PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "libft/libft.h"

# define ANSI_RED				"\x1b[31m"
# define ANSI_GREEN				"\x1b[32m"
# define ANSI_YELLOW			"\x1b[33m"
# define ANSI_BLUE				"\x1b[34m"
# define ANSI_CYAN				"\x1b[36m"
# define ANSI_RESET				"\x1b[0m"

typedef struct	s_chunk
{
	int			*arr;
	int			size;
}				t_chunk;

typedef struct	s_stack
{
	t_chunk		*a;
	t_chunk		*b;
	int			fl_v;
	int			fl_c;
}				t_stack;

void			ft_merge_dir(char **str, int size, int fl);
void			ft_algo_five_num(t_stack *st);
void			ft_algo_three_num(t_stack *st);
void			ft_find_place(int elem, t_stack *st, int f);
void			ft_put_up(int elem, t_stack *st, int fl);
void			ft_full_output(char **output, t_stack *st, int end);
void			ft_delete_stack(t_stack *st);
int				ft_check_back_order(t_chunk *tmp_st);
t_stack			*ft_create_stack(int ac);
void			ft_print_command(char *str, t_stack *st, int fl);
int				*ft_sorting_stack(int *stack, int size);
void			ft_push(int **from, int **where, int *size_fr, int *size_wr);
int				ft_check_order(t_chunk *a, t_chunk *b, int fl);
int				ft_choose_command(char *str, t_chunk *stack_a, \
				t_chunk *stack_b, int flag);
int				*ft_valid_digit(int ac, int count, char **av, int fl);
void			error(void);
int				ft_create_struct(t_stack *st, int ac);
int				ft_count_digit(char **av, int ac);

#endif
