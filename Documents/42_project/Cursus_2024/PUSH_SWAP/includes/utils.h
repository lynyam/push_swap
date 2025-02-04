#ifndef UTILS_H
# define UTILS_H

#include <stdlib.h>
#include <unistd.h>
#include "push_swap.h"

int	ft_atoi(const char *str);
int	is_digit(char c);
int	is_valid_number(const char *str);
int	has_duplicates(int *arr, int size);

int	ft_strlen(const char *str);
char	**ft_split(const char *s, char c);
void	free_split(char **split);

int     *get_chunk_limits(t_stack *a, int chunk_count);
void    push_chunk_to_b(t_stack *a, t_stack *b, int min, int max);
void    push_back_to_a(t_stack *a, t_stack *b);
int     *stack_to_array(t_stack *stack);
void    sort_array(int *array, int size);
int     find_max(t_stack *stack);
void    move_to_top(t_stack *stack, int value, char c);
int     is_empty(t_stack *stack);
void	print_error_and_exit(void);

#endif
