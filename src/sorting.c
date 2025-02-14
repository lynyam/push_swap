/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynyamets <ynyamets@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 06:04:41 by ynyamets          #+#    #+#             */
/*   Updated: 2025/02/14 06:27:42 by ynyamets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "utils.h"

void	sort_stack(t_stack *a, t_stack *b)
{
	if (a->size == 2)
	{
		if (a->top->value > a->top->next->value)
			swap(a, 'a');
		return ;
	}
	if (a->size == 3)
	{
		sort_three(a);
		return ;
	}
	if (a->size <= 5)
	{
		sort_small_stack(a, b);
		return ;
	}
	if (a->size <= 100)
	{
		sort_medium_stack(a, b);
		return ;
	}
	else
		sort_large_stack(a, b);
}

void	sort_three(t_stack *a)
{
	int	first;
	int	second;
	int	third;

	first = a->top->value;
	second = a->top->next->value;
	third = a->top->next->next->value;
	if (first > second && second < third && first < third)
		swap(a, 'a');
	else if (first > second && second > third)
	{
		swap(a, 'a');
		reverse_rotate(a, 'a');
	}
	else if (first > second && second < third && first > third)
		rotate(a, 'a');
	else if (first < second && second > third && first < third)
	{
		swap(a, 'a');
		rotate(a, 'a');
	}
	else if (first < second && second > third && first > third)
		reverse_rotate(a, 'a');
}

void	sort_small_stack(t_stack *a, t_stack *b)
{
	if (a->size == 4)
	{
		bring_min_to_top(a);
		push(b, a, 'b');
		sort_three(a);
		push(a, b, 'a');
		return;
	}
	if (a->size == 5)
	{
		bring_min_to_top(a);
		push(b, a, 'b');
		bring_min_to_top(a);
		push(b, a, 'b');
		sort_three(a);
		if (b->size == 2 && b->top->value < b->top->next->value)
			swap(b, 'b');
		push(a, b, 'a');
		push(a, b, 'a');
		return;
	}
}

void sort_medium_stack(t_stack *a, t_stack *b)
{
    int initial_total;
    int chunk_size;
    int current_limit;
    int pushed;

    index_stack(a);
    initial_total = a->size;
    chunk_size = 15;
    current_limit = chunk_size - 1;
    pushed = 0;
    while (a->size > 0)
    {
        if (a->top->value <= current_limit)
        {
            push(b, a, 'b');
            pushed++;
            if (b->size > 1 && b->top->value < current_limit - (chunk_size / 2))
                rotate(b, 'b');
        }
        else
        	rotate(a, 'a');
        if (pushed == current_limit + 1 && current_limit < initial_total - 1)
        {
            current_limit += chunk_size;
            if (current_limit > initial_total - 1)
                current_limit = initial_total - 1;
        }
    }
    while (b->size > 0)
    {
        int max_pos = get_max_position(b);
        if (max_pos <= b->size / 2)
        {
            while (max_pos-- > 0)
                rotate(b, 'b');
        }
        else
        {
            int r = b->size - max_pos;
            while (r-- > 0)
                reverse_rotate(b, 'b');
        }
        push(a, b, 'a');
    }
}