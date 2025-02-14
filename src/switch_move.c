/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switch_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynyamets <ynyamets@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 06:11:44 by ynyamets          #+#    #+#             */
/*   Updated: 2025/02/14 06:11:46 by ynyamets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack, char c)
{
	int temp;

	if (!stack ||  stack->size < 2)
		return ;
	temp = stack->top->value;
	stack->top->value = stack->top->next->value;
	stack->top->next->value = temp;
	if (c) {
		write(1, "s", 1);
		write(1, &c, 1);
		write(1, "\n", 1);
	}
}

void	sswap(t_stack *a, t_stack *b)
{
	if (a && b) {
		swap(a, 0);
		swap(b, 0);
		write(1, "ss\n", 3);
	}

}

void	push(t_stack *a, t_stack *b, char c)
{
	if (!b || !a || b->size == 0)
		return ;
	int value = pop_stack(b);
	push_stack(a, value);
	write(1, "p", 1);
		write(1, &c, 1);
		write(1, "\n", 1);
}