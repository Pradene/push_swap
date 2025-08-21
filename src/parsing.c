#include "push_swap.h"

static bool	safe_atoi(char *str, int *out) {
	int		i;
	int		sign;
	int		result;
	long	n;

	n = 0;
	i = 0;
	sign = 1;
	result = false;
	if (str[i] == '-' || str[i] == '+') {
		if (str[i] == '-') {
			sign = -1;
        }
		i++;
	}
	while (ft_isdigit(str[i])) {
		result = true;
		n = n * 10 + str[i] - '0';
		if ((n * sign > INT_MAX) || (n * sign < INT_MIN)) {
			return (false);
        }
		i++;
	}
	*out = (int)n * sign;
	return (i == (int)ft_strlen(str) && result);
}

static bool	stack_contains_n(t_list *stack, int value) {
	while (stack) {
		if (((t_data *)stack->content)->n == value) {
			return (true);
        }
		stack = stack->next;
	}
	return (false);
}

void	compute_final_index(t_list *stack) {
	t_list	*tmp;
	int		min;
	int		size;
	int		i;

	size = ft_lstsize(stack);
	min = get_min_value(stack);
	i = 0;
	while (i < size) {
		tmp = stack;
		while (tmp) {
			if (((t_data *)tmp->content)->n >= min) {
				((t_data *)tmp->content)->index = i;
            }
			tmp = tmp->next;
		}
		min = get_min_value_above_n(stack, min);
        ++i;
	}
}

bool	parse_args(char **av, t_list **stack) {
	int		i;
	t_data	*data;
	t_list	*tmp;

	i = 0;
	while (av[i]) {
		data = malloc(sizeof(t_data));
		if (!data) {
			return (false);
        }
		if (safe_atoi(av[i], &data->n) == false) {
			free(data);
			return (false);
        }
		if (stack_contains_n(*stack, data->n) == true) {
			free(data);
			return (false);
        }
		tmp = ft_lstnew((void *)data);
        if (tmp == NULL) {
			free(data);
            return (false);
        }
		ft_lstadd_back(stack, tmp);
		i++;
	}
	return (true);
}