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
t_stack		*init_stack(void);
int	pop(t_stack *stack);
void	push(t_stack *stack, int value);
void	swap(t_stack *stack);
void	rotate(t_stack *stack);
void	reverse_rotate(t_stack *stack);
void	print_stack(t_stack  *stack);
int	is_sorted(t_stack *stack);

void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);

void    sort_stack(t_stack *a, t_stack *b);
void	sort_small_stack(t_stack *a);
void    sort_medium_stack(t_stack *a, t_stack *b);
void    sort_large_stack(t_stack *a, t_stack *b);
void	radix_sort(t_stack *a, t_stack *b);


void	free_stack(t_stack *stack);

#endif
