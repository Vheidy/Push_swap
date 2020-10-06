void	ft_put_up(int elem, t_stack *st)
{
	int pos;

	pos = -1;
	while (++pos < st->A->size)
		if (st->A->arr[pos] == elem)
			break;
	if (pos <= st->A->size / 2)
		while (pos--)
			ft_print_command(ft_strdup("ra"), st);
	else
		while (st->A->size - (pos++))
			ft_print_command(ft_strdup("rra"), st);
}

void	ft_find_place(int elem, t_stack *st)
{
	int i;
	int min_more;
	int fl;
	int *sort;

	i = -1;
	fl = 0;
	min_more = 0;
	while (++i < st->A->size)
		if (st->A->arr[i] > elem) {
			if (!fl){
				min_more = st->A->arr[i];
				fl = 1;
			}
			else if (fl && st->A->arr[i] < min_more)
				min_more = st->A->arr[i];
		}
	if (fl)
		ft_put_up(min_more, st);
	else
	{
		sort = ft_sorting_stack(st->A->arr, st->A->size);
		ft_put_up(sort[0], st);
	}
}

void	ft_push_A_B(t_stack *st)
{
	int mid;
	int *sort;
	int count;

	mid = st->A->size / 2;
	count = 0;
	sort = ft_sorting_stack(st->A->arr, st->A->size);
	if (st->A->size > 2 && !ft_check_order(st->A, st->B, 0))
		while(count < mid && !ft_check_order(st->A, st->B, 0))
		{
			if (st->A->arr[0] < sort[mid])
			{
				// ft_find_place(st->A->arr[0], st);
				ft_print_command(ft_strdup("pb"), st);
				count++;
			}
			else if (st->A->arr[st->A->size - 1] < sort[mid])
				ft_print_command(ft_strdup("rra"), st);
			else
			{
				ft_print_command(ft_strdup("ra"), st);
			}
		}
	else if (!ft_check_order(st->A, st->B, 0))
		ft_print_command(ft_strdup("sa"), st);
	// printf("--ok--\n");
	if (!ft_check_order(st->A, st->B, 0))
		ft_push_A_B(st);
}

void	ft_algorithm(t_stack *st)
{
	int *sort;
	
	// printf("--ok--\n");
	if (!ft_check_order(st->A, st->B, 0))
		ft_push_A_B(st);
	
	while (st->B->size){
		ft_find_place(st->B->arr[0], st);
		ft_print_command(ft_strdup("pa"), st);
	}
	if (!ft_check_order(st->A, st->B, 0))
	{
		sort = ft_sorting_stack(st->A->arr, st->A->size);
		ft_put_up(sort[0], st);
	}
}