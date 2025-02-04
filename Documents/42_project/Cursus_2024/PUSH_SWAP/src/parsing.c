#include "push_swap.h"

int	is_valid_integer(const char *str)
{
	long	num;
	char	*end;

	if (!str || *str == '\0')
		return (0);
	num = strtol(str, &end, 10);
	if (*end != '\0'|| num < INT_MIN || num > INT_MAX)
		return (0);
	return (1);
}

int	has_duplicates(t_stack *stack, int value)
{
	t_node	*current;

	current = stack->top;
	while (current)
	{
		if (current->value == value)
			return (1);
		current = current->next;
	}
	return (0);
}

void	parse_args(int ac, char **av, t_stack *a)
{
	int	i;
	int	value;

	i = 1;
	while (i < ac)
	{
		if(!is_valid_integer(av[i]))
		{
			printf("Error\n");
			exit(EXIT_FAILURE);
		}
		value = atoi(av[i]);
		if (has_duplicates(a, value))
		{
			printf("Error\n");
			exit(EXIT_FAILURE);
		}
		push_stack(a, value);
		i++;
	}
}

int	is_sorted(t_stack *stack)
{
	t_node	*current;

	current = stack->top;
	while (current && current->next)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}
