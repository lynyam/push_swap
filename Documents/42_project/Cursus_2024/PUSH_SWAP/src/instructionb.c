#include "push_swap.h"

void	sa(t_stack *a)
{
	int temp;

	if (!a ||  a->size < 2)
		return ;
	temp = a->top->value;
	a->top->value = a->top->next->value;
	a->top->next->value = temp;
}

void    sb(t_stack *b)
{
        int temp;
        
        if (!b || b->size < 2)
                return ;
        temp = b->top->value;
        b->top->value = b->top->next->value;
        b->top->next->value = temp;
}

void	ss(t_stack *a, t_stack *b)
{
	sa(a);
	sb(b);
}

void	pa(t_stack *a, t_stack *b)
{
	if (!b || !a || b->size == 0)
		return ;
	int value = pop(b);
	push(a, value);
}

void	pb(t_stack *a, t_stack *b)
{
	if (!a || !b || a->size == 0)
		return ;
	int value = pop(a);
	push(b, value);
}

void	ra(t_stack *a)
{
	t_node	*first;
	t_node	*current;

	if (!a || a->size < 2)
		return ;
	first = a->top;
	a->top = a->top->next;
	first->next = NULL;
	current = a->top;
	while (current->next)
	{
		current = current->next;
	}
	current->next = first;
}

void    rb(t_stack *b)
{
        t_node  *first;
        t_node  *current;

        if (!b || b->size < 2)
                return ;
        first = b->top;
        b->top = b->top->next;
        first->next = NULL;
        current = b->top;
        while (current->next)
        {
                current = current->next;
        }
        current->next = first;
}

void	rr(t_stack *a, t_stack *b)
{
	ra(a);
	rb(b);
}

void	rra(t_stack *a)
{
	t_node	*last;
	t_node	*prev;

    	if (!a || a->size < 2)
		return;
	last = a->top;
	prev = NULL;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	if (prev)
		prev->next = NULL;
	last->next = a->top;
	a->top = last;
}

void    rrb(t_stack *b)
{
        t_node *last;
        t_node *prev;

        if (!b || b->size < 2)
                return;
        last = b->top;
        prev = NULL;
        while (last->next)
        {       
                prev = last;
                last = last->next;
        }
        if (prev)
                prev->next = NULL;
        last->next = b->top;
        b->top = last;
}

void	rrr(t_stack *a, t_stack *b)
{
	rra(a);
	rrb(b);
}
