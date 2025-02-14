/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynyamets <ynyamets@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 06:05:00 by ynyamets          #+#    #+#             */
/*   Updated: 2025/02/14 07:31:22 by ynyamets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

#include <stdlib.h>
#include <unistd.h>
#include "push_swap.h"

void    sort_three(t_stack *a);
int get_min_position(t_stack *a);
void	bring_min_to_top(t_stack *a);
void    sort_int_array(int *arr, int n);
void    fill_array_with_values(t_stack *a, int *arr);
void    update_stack_with_indexes(t_stack *a, int *arr, int size);
void    index_stack(t_stack *a);
int get_max_position(t_stack *stack);
void	sort_large_stack(t_stack *a, t_stack *b);
void	move_elements_to_b(t_stack *a, t_stack *b, int *current_limit, int *pushed,
    int initial_total, int chunk_size);
void	move_elements_from_b_to_a(t_stack *a, t_stack *b);
int	is_sorted(t_stack *stack);

#endif
