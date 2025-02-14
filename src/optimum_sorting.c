/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimum_sorting.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynyamets <ynyamets@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 06:22:46 by ynyamets          #+#    #+#             */
/*   Updated: 2025/02/14 07:47:41 by ynyamets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "utils.h"

int get_max_position(t_stack *stack)
{
    t_node *current;
    int max;
    int pos;
    int max_pos;

    if (!stack || stack->size == 0)
        return (-1);
    current = stack->top;
    max = current->value;
    pos = 0;
    max_pos = 0;
    while (current)
    {
        if (current->value > max)
        {
            max = current->value;
            max_pos = pos;
        }
        pos++;
        current = current->next;
    }
    return (max_pos);
}

void	move_elements_from_b_to_a(t_stack *a, t_stack *b)
{
	while (b->size > 0)
	{
		int	max_pos;

		max_pos = get_max_position(b);
		if (max_pos <= b->size / 2)
		{
			while (max_pos-- > 0)
				rotate(b, 'b');
		}
		else
		{
			int	r;

			r = b->size - max_pos;
			while (r-- > 0)
				reverse_rotate(b, 'b');
		}
		push(a, b, 'a');
		if (a->size > 1 && a->top->value > a->top->next->value)
			swap(a, 'a');
	}
}


void	move_elements_to_b(t_stack *a, t_stack *b, int *current_limit, int *pushed, int initial_total, int chunk_size)
{
	while (a->size > 0)
	{
		if (a->top->value <= *current_limit)
		{
			push(b, a, 'b');
			(*pushed)++;
			if (b->size > 1 && b->top->value < *current_limit - (chunk_size / 2))
				rotate(b, 'b');
		}
		else
			rotate(a, 'a');
		if (*pushed == *current_limit + 1 && *current_limit < initial_total - 1)
		{
			*current_limit += chunk_size;
			if (*current_limit > initial_total - 1)
				*current_limit = initial_total - 1;
			if (initial_total - *current_limit < chunk_size)
				chunk_size = initial_total - *current_limit;
		}
	}
}

void index_stack(t_stack *a)
{
	int size;
	int *arr;

	size = a->size;
	arr = malloc(size * sizeof(int));
	if (!arr)
	{
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	fill_array_with_values(a, arr);
	sort_int_array(arr, size);
	update_stack_with_indexes(a, arr, size);
	free(arr);
}

void	sort_large_stack(t_stack *a, t_stack *b)
{
	int	initial_total;
	int	chunk_size;
	int	current_limit;
	int	pushed;

	initial_total = a->size;
	chunk_size = 52;
	current_limit = chunk_size - 1;
	pushed = 0;
	index_stack(a);
	move_elements_to_b(a, b, &current_limit, &pushed, initial_total, chunk_size);
	move_elements_from_b_to_a(a, b);
}