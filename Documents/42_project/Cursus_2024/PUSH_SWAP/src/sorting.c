#include "push_swap.h"
#include "utils.h"

void	sort_stack(t_stack *a, t_stack *b)
{
	if (a->size <= 3)
		sort_small_stack(a);
	else if (a->size <= 100)
		sort_medium_stack(a, b);
	else
		sort_large_stack(a, b);
}

void	sort_small_stack(t_stack *a)
{
	int	first;
	int	second;
	int	third;
	char	c;

	c = 'a';
	if (a->size == 2 && a->top->value > a->top->next->value)
	{		
		swap(a, 'a');
	}
	else if (a->size == 3)
	{
		first = a->top->value;
		second = a->top->next->value;
		third = a->top->next->next->value;

		if (first > second && second < third && first < third)
			swap(a, c);
		else if (first > second && second > third && first > third)
			swap(a, c), reverse_rotate(a, c);
		else if (first > second && second < third && first > third)
			rotate(a, c);
		else if (first < second && second > third && first < third)
			reverse_rotate(a, c);
		else if (first < second && second > third && first < third)
			swap(a, c), rotate(a, c);		
	}
}

void	sort_medium_stack(t_stack *a, t_stack *b)
{
	int	chunck_count;
	int	*limits;
	int	i;

	chunck_count = 5;
	i = 0;
	limits = get_chunk_limits(a, chunck_count);

	while (i < chunck_count)
	{
//		printf("limits : %d - %d\n", limits[i], limits[i + 1]); 
		push_chunk_to_b(a, b, limits[i], limits[i + 1] - 1);
		i++;
	}

	push_back_to_a(a, b);
	free(limits);
}

void	sort_large_stack(t_stack *a, t_stack *b)
{
	(void)a;
	(void)b;
}
