#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = init_stack();
	stack_b = init_stack();

	if (argc > 1)
	{
		parse_args(argc, argv, stack_a);
		printf("Pile A apres parsing : \n");
		print_stack(stack_a);
		if (is_sorted(stack_a))
			printf("La pile est déja triée. \n");
		else
			printf("La pile n'est pas triée. \n");
	}
	else
	{
		printf("Veuillez fournir des arguments a trier.\n");
	}
	sort_stack(stack_a, stack_b);
	free_stack(stack_a);
	return (0);
}
