/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circular_move.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynyamets <ynyamets@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 06:10:54 by ynyamets          #+#    #+#             */
/*   Updated: 2025/02/14 06:10:55 by ynyamets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	if (c) {
		write(1, "r", 1);
		write(1, &c, 1);
		write(1, "\n", 1);
	}
}

void	rrotate(t_stack *a, t_stack *b)
{
	if (!a || !b || a->size < 2 || b->size < 2)
		return ;
	rotate(a, 0);
	rotate(b, 0);
	write(1, "rr\n", 3);
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
	else
		return ;
	last->next = stack->top;
	stack->top = last;
	if (c) {
		write(1, "rr", 2);
		write(1, &c, 1);
		write(1, "\n", 1);
	}
}

void	rreverse_rotate(t_stack *a, t_stack *b)
{
	if (!a || !b || a->size < 2 || b->size < 2)
		return ;
	reverse_rotate(a, 0);
	reverse_rotate(b, 0);
	write(1, "rrr\n", 4);
}