#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# define INT_MIN -2147483648
# define INT_MAX 2147483647
typedef struct s_node
{
	int		value;
	struct s_node	*next;
}			t_node;

typedef struct s_stack
{
	t_node	*top;
	int	size;
}		t_stack;

void	parse_args(int ac, char **av, t_stack *a);
t_stack	*init_stack(void);
int	pop_stack(t_stack *stack);
void	push_stack(t_stack *stack, int value);
void	print_stack(t_stack  *stack);
int	is_sorted(t_stack *stack);


void    push(t_stack *a, t_stack *b, char c);
void    swap(t_stack *stack, char c);
void    sswap(t_stack *a, t_stack *b);
void	rotate(t_stack *stack, char c);
void    rrotate(t_stack *a, t_stack *b);
void	reverse_rotate(t_stack *stack, char c);
void    rreverse_rotate(t_stack *a, t_stack *b);

void    sort_stack(t_stack *a, t_stack *b);
void	sort_small_stack(t_stack *a);
void    sort_medium_stack(t_stack *a, t_stack *b);
void    sort_large_stack(t_stack *a, t_stack *b);
void	radix_sort(t_stack *a, t_stack *b);


void	free_stack(t_stack *stack);

#endif
