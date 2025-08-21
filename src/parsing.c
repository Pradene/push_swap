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

static bool	contains_number(t_list *stack, int value) {
	while (stack) {
		if (((t_data *)stack->content)->n == value) {
			return (true);
        }
		stack = stack->next;
	}
	return (false);
}

static void	compute_final_index(t_list *lst) {
	t_list	*tmp;
	int		min;
	int		size;
	int		i;

	size = ft_lstsize(lst);
	min = get_min(lst);
	i = 0;
	while (i < size) {
		tmp = lst;
		while (tmp) {
			if (((t_data *)tmp->content)->n >= min) {
				((t_data *)tmp->content)->index = i;
            }
			tmp = tmp->next;
		}
		min = get_min_above(lst, min);
        ++i;
	}
}

bool	parse_args(char **av, t_list **stack_a) {
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
		if (contains_number(*stack_a, data->n) == true) {
			free(data);
			return (false);
        }
		tmp = ft_lstnew((void *)data);
        if (tmp == NULL) {
			free(data);
            return (false);
        }
		ft_lstadd_back(stack_a, tmp);
		i++;
	}
    compute_final_index(*stack_a);
	return (true);
}