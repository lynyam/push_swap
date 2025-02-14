/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynyamets <ynyamets@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 06:04:49 by ynyamets          #+#    #+#             */
/*   Updated: 2025/02/14 07:48:17 by ynyamets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "utils.h"

int	get_min_position(t_stack *a)
{
	t_node	*current;
	int		min;
	int		pos;
	int		min_pos;

	current = a->top;
	min = current->value;
	pos = 0;
	min_pos = 0;
	while (current)
	{
		if (current->value < min)
		{
			min = current->value;
			min_pos = pos;
		}
		pos++;
		current = current->next;
	}
	return (min_pos);
}

void	bring_min_to_top(t_stack *a)
{
	int	pos;

	pos = get_min_position(a);
	if (pos <= a->size / 2)
	{
		while (pos-- > 0)
			rotate(a, 'a');
	}
	else
	{
		pos = a->size - get_min_position(a);
		while (pos-- > 0)
			reverse_rotate(a, 'a');
	}
}

void sort_int_array(int *arr, int n)
{
	int i;
	int j;
	int min_idx;
	int tmp;

	i = 0;
	while (i < n - 1)
	{
		min_idx = i;
		j = i + 1;
		while (j < n)
		{
			if (arr[j] < arr[min_idx])
				min_idx = j;
			j++;
		}
		if (min_idx != i)
		{
			tmp = arr[i];
			arr[i] = arr[min_idx];
			arr[min_idx] = tmp;
		}
		i++;
	}
}

void fill_array_with_values(t_stack *a, int *arr)
{
	t_node *curr;
	int i;

	curr = a->top;
	i = 0;
	while (curr)
	{
		arr[i] = curr->value;
		curr = curr->next;
		i++;
	}
}

void update_stack_with_indexes(t_stack *a, int *arr, int size)
{
	t_node *curr;
	int i;

	curr = a->top;
	while (curr)
	{
		i = 0;
		while (i < size)
		{
			if (curr->value == arr[i])
			{
				curr->value = i;
				break;
			}
			i++;
		}
		curr = curr->next;
	}
}