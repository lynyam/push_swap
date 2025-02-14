/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynyamets <ynyamets@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 06:36:23 by ynyamets          #+#    #+#             */
/*   Updated: 2025/02/14 07:40:59 by ynyamets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_valid_integer(const char *str)
{
	long	num;
	char	*end;

	if (!str || *str == '\0')
		return (0);
	num = strtol(str, &end, 10);
	if (*end != '\0'|| num < INT_MIN || num > INT_MAX)
		return (0);
	return (1);
}

int	has_duplicates(t_stack *stack, int value)
{
	t_node	*current;

	current = stack->top;
	while (current)
	{
		if (current->value == value)
			return (1);
		current = current->next;
	}
	return (0);
}

static void process_single_argument(char **split_args, int *i, t_stack *a)
{
	int value;

	if (!is_valid_integer(split_args[*i]))
	{
		write(1, "Error\n", 6);
		free_stack(a);
		exit(EXIT_FAILURE);
	}
	value = atoi(split_args[*i]);
	if (has_duplicates(a, value))
	{
		write(1, "Error\n", 6);
		free_stack(a);
		exit(EXIT_FAILURE);
	}
	push_stack(a, value);
}

void handle_split_args(int ac, char **av, char ***split_args, int *count)
{
	if (ac == 2)
	{
		*split_args = ft_split(av[1], ' ');
		while ((*split_args)[*count])
			(*count)++;
	}
	else
	{
		*split_args = av + 1;
		*count = ac - 1;
	}
}

void parse_args(int ac, char **av, t_stack *a)
{
	int count;
	char **split_args;
	int	i;

	count = 0;
	handle_split_args(ac, av, &split_args, &count);
	i = count - 1;
	while (i >= 0)
	{
		process_single_argument(split_args, &i, a);
		i--;
	}
	if (ac == 2)
		free_split(split_args);
}
