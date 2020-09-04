#include "checker_push_swap.h"
#include <stdio.h>

void	ft_push(int **from, int **where, int *size_fr, int *size_wr)
{
	int tmp;
	int *new_from;
	int *new_where;
	int j;
	int i;
	
	i = -1;
	j = 0;
	*size_fr -= 1;
	*size_wr += 1;
	tmp = (*from)[0];
	new_from = malloc(sizeof(int) * (*size_fr));
	while (++i < *size_fr)
		new_from[i] = (*from)[i + 1];
	new_where = malloc(sizeof(int) * (*size_wr));
	new_where[j] = tmp;
	while (++j < *size_wr)
		new_where[j] = (*where)[j - 1];
	free(*from);
	free(*where);
	*from = new_from;
	*where = new_where;
}

int main() {
	int *from;
	int *where;
	int size_fr = 2;
	int size_wr = 4;

	where = malloc(sizeof(int) * size_wr);
	from = malloc(sizeof(int) * size_fr);
	from[0]= 5;
	from[1] = 3;
	where[0] = 1;
	where[1] = 7;
	where[2] = 4;
	where[3] = 2;
	ft_push(&from, &where, &size_fr, &size_wr);
	int i = 0;
	printf("From:\n");
	while (i < size_fr)
		printf("%d\n", from[i++]);
	int j = 0;
	printf("Where:\n");
	while (j < size_wr)
		printf("%d\n", where[j++]);
	printf("Size_fr: %d, Size_wr: %d\n", size_fr, size_wr);
	return 0;
}