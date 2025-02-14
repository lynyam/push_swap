/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynyamets <ynyamets@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 06:04:22 by ynyamets          #+#    #+#             */
/*   Updated: 2025/02/14 06:34:23 by ynyamets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc > 1)
	{
		stack_a = init_stack();
		parse_args(argc, argv, stack_a);
		if (is_sorted(stack_a)) {
			free_stack(stack_a);
			return (0);
		}
	}
	else
	{
		printf("Veuillez fournir des arguments a trier.\n");
	}
	
	stack_b = init_stack();
	sort_stack(stack_a, stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
