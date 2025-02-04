#include "push_swap.h"

t_stack	*init_stack(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
	{
		printf("Error\n");
		exit(EXIT_FAILURE);
	}
	stack->top = NULL;
	stack->size = 0;
	return (stack);
}

t_node	*create_node(int value)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
	{
		printf("Error\n");//to do: pas besoin de free la stack ???
		exit(EXIT_FAILURE);
	}
	node->value = value;
	node->next = NULL;
	return (node);
}

void	push_stack(t_stack *stack, int value)
{
	t_node	*node;

	node = create_node(value);
	node->next = stack->top;
	stack->top = node;
	stack->size++;
}

int	pop_stack(t_stack *stack)
{
	int	value;

	if (!stack || !stack->top)
	{
		printf("Error\n");
		exit(EXIT_FAILURE);
	}
	t_node *temp = stack->top;
	value = temp->value;
	stack->top = stack->top->next;
	free(temp);
	stack->size--;
	return (value);
}

void	print_stack(t_stack *stack)
{
	t_node	*current;

	current = stack->top;
	while (current)
	{
		printf("%d\n", current->value);
		current = current->next;
	}
}

void	free_stack(t_stack *stack)
{
	t_node	*current;

	current = stack->top;
	while (current)
	{
		t_node *temp = current;
		current = current->next;
		free(temp);
	}
	free(stack);
}
