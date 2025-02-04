#include "utils.h"
#include "push_swap.h"

int	*get_chunk_limits(t_stack *a, int chunck_count)
{
	int	*sorted_values;
	int	*limits;
	int	chunck_size;
	int i;

	sorted_values = stack_to_array(a);
	limits = malloc(sizeof(int) * (chunck_count + 1));
	chunck_size = a->size / chunck_count;
	if (chunck_size == 0)
		chunck_size = 1;
	sort_array(sorted_values, a->size);
	i = 0;
	while (i <= chunck_count)
	{
		limits[i] = sorted_values[i * chunck_size];
		i++;
	}
	free(sorted_values);
	return limits;
}

void	push_chunk_to_b(t_stack *a, t_stack *b, int min, int max)
{
	int	rotations;
	int	i;

	rotations = 0;
	i = 0;
	while (i < a->size)
	{
		if (a->top->value >= min && a->top->value <= max)
			push(b, a, 'b');
		else
		{
			rotate(a, 'a');
			rotations++;
		}
		i++;
	}
	i = 0;
	while (i < rotations)
	{
		reverse_rotate(a, 'a');
		i++;
	}
}

void	push_back_to_a(t_stack *a, t_stack *b)
{
	while (!is_empty(b))
	{
		int max;

		max = find_max(b);
		move_to_top(b, max, 'b');
		push(a, b, 'a');
	}
}

int	*stack_to_array(t_stack *stack)
{
	int     *array;
	t_node	*current;
	int	i;
	
	i = 0;
	array = malloc(sizeof(int) * stack->size);//to-do: protection malloc
	current = stack->top;
	while (i < stack->size) 
	{
		array[i++] = current->value;
		current = current->next;
	}
	return (array);
}

void	sort_array(int *array, int size)
{//to-do: ameliorer ce trie avec un tableau de bucket sort
	int i;
	int j;
	int temp;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (array[i] > array[j])
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
			j++;
		}
		i++;
	}
}

int	find_max(t_stack *stack)
{
	t_node	*current;
	int	max;

	current = stack->top;
	max = current->value;
	while (current) {
		if (current->value > max) {
			max = current->value;
		}
		current = current->next;
	}
	return (max);
}

void	move_to_top(t_stack *stack, int value, char c)
{
	int	rotations;
	int	i;

	i = 0;
	rotations = 0;
	while (stack->top->value != value)
	{
		rotate(stack, c);
		rotations++;
	}
	if (rotations > stack->size / 2)
	{
		i = 0;
		while (i < stack->size - rotations)
		{
			reverse_rotate(stack, c);
			i++;
		}
	}
}

int	is_empty(t_stack *stack)
{
	if (!stack)
		return (1);
	return (stack->size);
}
