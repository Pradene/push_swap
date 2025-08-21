#include "push_swap.h"

static void	divide_stack_into_chunk(t_list **stack_a, t_list **stack_b, int chunk) {
	t_list	*current;
	int		pivot;
	int		size;
	int		i;

	if (!stack_a || !(*stack_a) || chunk <= 0) {
		return ;
	}

	i = 0;
	size = ft_lstsize((*stack_a));
	while (size * (++i) / chunk <= size) {
		pivot = size * i / chunk;
		while (get_min_index_above_n((*stack_a), 0) < pivot) {
			current = *stack_a;
			if (!current) {
				return ;
			}
			if (((t_data *)current->content)->index < pivot) {
				pb(stack_a, stack_b);
			} else {
				ra(stack_a);
			}
		}
	}
}

static int	find_best_element_index(t_list *stack_a, t_list *stack_b, int n) {
	t_list	*element;
	int		elem_index;
	int		move;

	if (!stack_b) {
		return (INT_MAX);
	}
	element = stack_b;
	elem_index = ((t_data *)element->content)->index;
	move = INT_MAX;
	while (element) {
		if (((t_data *)element->content)->index >= n) {
			int idx = ((t_data *)element->content)->index;
			int cost = ft_get_move(stack_b, idx) + ft_get_nmove(stack_a, idx);
			if (cost < move) {
				elem_index = idx;
				move = cost;
			}
		}
		element = element->next;
	}
	return (elem_index);
}

static void	move_element_to_stack_b(t_list **stack_a, t_list **stack_b, int n) {
	int	size;
	int	pos;

	(void)stack_a;
	if (!stack_b || !*stack_b) {
		return ;
	}
	size = ft_lstsize(*stack_b);
	pos = get_position_of_element_with_index(*stack_b, n);
	if (pos > size / 2) {
		while (((t_data *)(*stack_b)->content)->index != n) {
			rrb(stack_b);
		}
	} else {
		while (((t_data *)(*stack_b)->content)->index != n) {
			rb(stack_b);
		}
	}
}

static void	prepare_stack_a_for_insertion(t_list **stack_a, t_list **stack_b, int n) {
	int	size;
	int	pos;
	int	min;

	(void)stack_b;
	if (!stack_a || !(*stack_a)) {
		return ;
	}
	min = get_min_index_above_n(*stack_a, n);
	pos = get_position_of_element_with_index(*stack_a, min);
	size = ft_lstsize(*stack_a);
	if (min == INT_MAX) {
		while (((t_data *)(*stack_a)->content)->index != get_min_index_above_n(*stack_a, 0))
			ra(stack_a);
	} else if (pos > size / 2) {
		while (((t_data *)(*stack_a)->content)->index != min)
			rra(stack_a);
	} else {
		while (((t_data *)(*stack_a)->content)->index != min)
			ra(stack_a);
	}
}

static void	chunk_sort(t_list **stack_a, t_list **stack_b, int n) {
	int	elem_index;

	while (get_max_index_in_stack(*stack_b) >= n) {
		elem_index = find_best_element_index(*stack_a, *stack_b, n);
		move_element_to_stack_b(stack_a, stack_b, elem_index);
		prepare_stack_a_for_insertion(stack_a, stack_b, elem_index);
		pa(stack_b, stack_a);
	}
}

void	push_swap(t_list **stack_a, t_list **stack_b) {
	int	chunk;
	int size;
	int	i;

	size = ft_lstsize(*stack_a);
	if (size == 2) {
		return ((void)sa(stack_a));
	} else if (size == 3) {
		return ((void)sort_three_elements(stack_a));
	} else if (size <= 5) {
		return ((void)sort_five_elements(stack_a, stack_b));
	} else if (size < 100) {
		chunk = 2;
	} else if (size < 500) {
		chunk = 5;
	} else {
		chunk = 10;
	}
	i = 0;
	divide_stack_into_chunk(stack_a, stack_b, chunk);
	while (chunk - ++i >= 0) {
		chunk_sort(stack_a, stack_b, size * (chunk - i) / chunk);
	}
	while (((t_data *)(*stack_a)->content)->index != 0) {
		rra(stack_a);
	}
}
