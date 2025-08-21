#include "push_swap.h"

int get_max_index_in_stack(t_list *stack) {
    t_list  *current;
    int     max;
    t_data  *data;

    max = INT_MIN;
    current = stack;
    while (current) {
        data = (t_data *)current->content;
        if (data->index > max) {
            max = data->index;
        }
        current = current->next;
    }
    return (max);
}

int get_min_index_above_n(t_list *stack, int n) {
    t_list  *current;
    int     min;
    t_data  *data;

    min = INT_MAX;
    current = stack;
    while (current) {
        data = (t_data *)current->content;
        if (data->index < min && data->index >= n) {
            min = data->index;
        }
        current = current->next;
    }
    return (min);
}

int get_position_of_element_with_index(t_list *stack, int n) {
    t_list  *current;
    int     pos;
    t_data  *data;

    current = stack;
    pos = 0;
    while (current) {
        data = (t_data *)current->content;
        if (data->index == n) {
            break ;
        }
        ++pos;
        current = current->next;
    }
    return (pos);
}

int ft_get_move(t_list *stack, int n) {
    int size;
    int pos;

    size = ft_lstsize(stack);
    pos = get_position_of_element_with_index(stack, n);
    if (size / 2 > pos) {
        return (pos);
    }
    return (size - pos);
}

int ft_get_nmove(t_list *stack, int n) {
    if (get_min_index_above_n(stack, n) == INT_MAX) {
        return (0);
    }
    return (ft_get_move(stack, get_min_index_above_n(stack, n)));
}

int get_min_value(t_list *stack) {
    int     min;
    t_data  *data;

    min = INT_MAX;
    while (stack) {
        data = (t_data *)stack->content;
        if (data->n < min) {
            min = data->n;
        }
        stack = stack->next;
    }
    return (min);
}

int get_min_value_above_n(t_list *stack, int n) {
    int     min;
    t_data  *data;

    min = INT_MAX;
    while (stack) {
        data = (t_data *)stack->content;
        if (data->n > n && data->n < min) {
            min = data->n;
        }
        stack = stack->next;
    }
    return (min);
}

bool	is_stack_sorted(t_list *stack) {
	while (stack->next) {
		if (((t_data *)stack->content)->n > ((t_data *)stack->next->content)->n) {
			return (false);
		}
		stack = stack->next;
	}
	return (true);
}

void	print_stack(t_list *stack) {
	int n;
	while (stack) {
		n = ((t_data *)stack->content)->n;
		ft_printf("%d\n", n);
		stack = stack->next;
	}
}