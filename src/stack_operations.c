/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynyamets <ynyamets@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 06:05:23 by ynyamets          #+#    #+#             */
/*   Updated: 2025/02/14 06:06:24 by ynyamets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*init_stack(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
	{
		write(1, "Error\n", 6);
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
		write(1, "Error\n", 6);
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
		write(1, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	t_node *temp = stack->top;
	value = temp->value;
	stack->top = stack->top->next;
	free(temp);
	stack->size--;
	return (value);
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
