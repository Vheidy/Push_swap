#include "checker_push_swap.h"
#include <stdio.h>
// #include "libft/libft.h"

int		ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}


int		ft_count_digit(char **av, int ac)
{
	int i;
	int count;

	count = 0;
	while (--ac)
	{
		i = -1;
		while (av[ac][++i])
			if ((ft_isdigit(av[ac][i]) && i == 0) \
			|| (av[ac][i] == ' ' && ft_isdigit(av[ac][i + 1])) || \
			(av[ac][i] == '-' && i > 0 && av[ac][i - 1] == ' ' && ft_isdigit(av[ac][i + 1])))
				count++;
	}
	return count;
}

int main(int ac, char **av)
{
	int res;
	if (ac == 1)
		return 0;
	if ((res = ft_count_digit(av, ac))){
		printf("Count: %d\n", res);
	} else {
		printf("Count: 0\n");
	}
}