#include "push_swap.h"

void	swap(t_stack *stack, char c)
{
	int temp;

	if (!stack ||  stack->size < 2)
		return ;
	temp = stack->top->value;
	stack->top->value = stack->top->next->value;
	stack->top->next->value = temp;
	printf("s%c\n", c);
}

void	sswap(t_stack *a, t_stack *b)
{
	swap(a, 'a');
	swap(b, 'b');
}

void	push(t_stack *a, t_stack *b, char c)
{
	if (!b || !a || b->size == 0)
		return ;
	int value = pop_stack(b);
	push_stack(a, value);
	printf("p%c\n", c);
}

void	rotate(t_stack *stack, char c)
{
	t_node	*first;
	t_node	*current;

	if (!stack || stack->size < 2)
		return ;
	first = stack->top;
	stack->top = stack->top->next;
	first->next = NULL;
	current = stack->top;
	while (current->next)
	{
		current = current->next;
	}
	current->next = first;
	printf("r%c\n", c);
}

void	rrotate(t_stack *a, t_stack *b)
{
	rotate(a, 'a');
	rotate(b, 'b');
}

void	reverse_rotate(t_stack *stack, char c)
{
	t_node	*last;
	t_node	*prev;

    	if (!stack || stack->size < 2)
		return ;
	last = stack->top;
	prev = NULL;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	if (prev)
		prev->next = NULL;
	last->next = stack->top;
	stack->top = last;
	printf("rr%c\n", c);;
}

void	rreverse_rotate(t_stack *a, t_stack *b)
{
	reverse_rotate(a, 'a');
	reverse_rotate(b, 'b');
}
