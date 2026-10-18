#include <stdio.h>
#include <stdlib.h>

void	quicksort(int *nbrs, int len)
{
	int	low, high, part_elem;

	low = 0;
	high = len - 1;
	if (len < 2 || low == high) // Base cases
		return ;
	part_elem = nbrs[0];
	while (1)
	{
		while (high > low && nbrs[high] >= part_elem)
			high--;
		if (high == low)
			break ;
		nbrs[low] = nbrs[high];
		while (low < high && nbrs[low] <= part_elem)
			low++;
		if (high == low)
			break ;
		nbrs[high] = nbrs[low];
	}
	nbrs[low] = part_elem;
	quicksort(nbrs, low); // Sort lower half
	quicksort(nbrs + (low + 1), len - (high + 1)); // Sort upper half
	return ;
}

int	main(int ac, char *av[])
{
	int	*nbrs;
	int	i, j;

	if (ac < 2)
		return (0);
	nbrs = malloc(sizeof(int) * (ac - 1));
	if (!nbrs)
		return (1);
	for (i = 0, j = 1; av[j] != NULL; i++, j++)
		nbrs[i] = atoi(av[j]);
	quicksort(nbrs, i);
	for (i = 0; i < ac - 1; i++)
		printf("%d ", nbrs[i]);
	printf("\n");
	free(nbrs);
	return (0);
}
