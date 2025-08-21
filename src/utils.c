#include "push_swap.h"

int ft_getmax(t_list *lst) {
    t_list  *element;
    int     max;
    t_data  *data;

    max = INT_MIN;
    element = lst;
    while (element) {
        data = (t_data *)element->content;
        if (data->index > max) {
            max = data->index;
        }
        element = element->next;
    }
    return (max);
}

int ft_getmin(t_list *lst, int n) {
    t_list  *element;
    int     min;
    t_data  *data;

    min = INT_MAX;
    element = lst;
    while (element) {
        data = (t_data *)element->content;
        if (data->index < min && data->index >= n) {
            min = data->index;
        }
        element = element->next;
    }
    return (min);
}

int ft_get_pos(t_list *lst, int n) {
    t_list  *element;
    int     pos;
    t_data  *data;

    element = lst;
    pos = 0;
    while (element) {
        data = (t_data *)element->content;
        if (data->index == n) {
            break ;
        }
        ++pos;
        element = element->next;
    }
    return (pos);
}

int ft_get_move(t_list *lst, int n) {
    int size;
    int pos;

    size = ft_lstsize(lst);
    pos = ft_get_pos(lst, n);
    if (size / 2 > pos) {
        return (pos);
    }
    return (size - pos);
}

int ft_get_nmove(t_list *lst, int n) {
    if (ft_getmin(lst, n) == INT_MAX) {
        return (0);
    }
    return (ft_get_move(lst, ft_getmin(lst, n)));
}

int get_min(t_list *lst) {
    int     min;
    t_data  *data;

    min = INT_MAX;
    while (lst) {
        data = (t_data *)lst->content;
        if (data->n < min)
            min = data->n;
        lst = lst->next;
    }
    return (min);
}

int get_min_above(t_list *lst, int n) {
    int     min;
    t_data  *data;

    min = INT_MAX;
    while (lst) {
        data = (t_data *)lst->content;
        if (data->n > n && data->n < min)
            min = data->n;
        lst = lst->next;
    }
    return (min);
}

bool	is_sorted(t_list *lst) {
	while (lst->next) {
		if (((t_data *)lst->content)->n > ((t_data *)lst->next->content)->n) {
			return (false);
		}
		lst = lst->next;
	}
	return (true);
}

void	print_stack(t_list *lst) {
	int n;
	while (lst) {
		n = ((t_data *)lst->content)->n;
		ft_printf("%d\n", n);
		lst = lst->next;
	}
}