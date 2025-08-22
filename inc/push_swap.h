#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "libft.h"

#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

typedef struct s_data {
	int	n;
	int	index;
}	t_data;

// Instructions
void	pa(t_list **stack_b, t_list **stack_a);
void	pb(t_list **stack_a, t_list **stack_b);

void	ra(t_list **stack_a);
void	rb(t_list **stack_b);
void	rr(t_list **stack_a, t_list **stack_b);

void	rra(t_list **stack_a);
void	rrb(t_list **stack_b);
void	rrr(t_list **stack_a, t_list **stack_b);

void	sa(t_list **stack_a);
void	sb(t_list **stack_b);
void	ss(t_list **stack_a, t_list **stack_b);

// Utils
int		get_max_index_in_stack(t_list *stack);
int		get_min_index_above_n(t_list *stack, int n);
int		get_position_of_element_with_index(t_list *stack, int n);
int		calculate_rotation_cost(t_list *stack, int n);
int		calculate_insertion_cost(t_list *stack, int n);
int		get_min_value(t_list *stack);
int		get_min_value_above_n(t_list *stack, int n);

bool	is_stack_sorted(t_list *stack);
void	print_stack(t_list *stack);

// Parsing
bool	parse_args(char **av, t_list **stack_a);
void	compute_final_index(t_list *stack);

// Sort
void	sort_three_elements(t_list **stack_a);
void	sort_five_elements(t_list **stack_a, t_list **stack_b);
void	sort(t_list **stack_a, t_list **stack_b);

#endif
