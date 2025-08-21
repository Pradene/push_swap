#include "push_swap.h"

int	ft_get_elemindex(t_list *a, t_list *b, int n) {
	t_list	*element;
	int		elem_index;
	int		move;

	if (!b) {
		return (INT_MAX);
	}
	element = b;
	elem_index = ((t_data *)element->content)->index;
	move = INT_MAX;
	while (element) {
		if (((t_data *)element->content)->index >= n) {
			int idx = ((t_data *)element->content)->index;
			int cost = ft_get_move(b, idx) + ft_get_nmove(a, idx);
			if (cost < move) {
				elem_index = idx;
				move = cost;
			}
		}
		element = element->next;
	}
	return (elem_index);
}

void	ft_move_b(t_list **a, t_list **b, int n) {
	int	size;
	int	pos;

	(void)a;
	if (!b || !*b) {
		return ;
	}
	size = ft_lstsize(*b);
	pos = ft_get_pos(*b, n);
	if (pos > size / 2) {
		while (((t_data *)(*b)->content)->index != n) {
			rrb(b);
		}
	} else {
		while (((t_data *)(*b)->content)->index != n) {
			rb(b);
		}
	}
}

void	ft_move_a(t_list **a, t_list **b, int n) {
	int	size;
	int	pos;
	int	min;

	(void)b;
	if (!a || !(*a)) {
		return ;
	}
	min = ft_getmin(*a, n);
	pos = ft_get_pos(*a, min);
	size = ft_lstsize(*a);
	if (min == INT_MAX) {
		while (((t_data *)(*a)->content)->index != ft_getmin(*a, 0))
			ra(a);
	} else if (pos > size / 2) {
		while (((t_data *)(*a)->content)->index != min)
			rra(a);
	} else {
		while (((t_data *)(*a)->content)->index != min)
			ra(a);
	}
}

void	ft_sort(t_list **a, t_list **b, int n) {
	int	elem_index;

	while (ft_getmax(*b) >= n) {
		elem_index = ft_get_elemindex(*a, *b, n);
		ft_move_b(a, b, elem_index);
		ft_move_a(a, b, elem_index);
		pa(b, a);
	}
}

void	push_swap(t_list **a, t_list **b, int arg) {
	int	chunk;
	int	i;

	if (arg == 2) {
		return ((void)ft_sort2a(a, b));
	} else if (arg == 3) {
		return ((void)ft_sort3a(a, b));
	} else if (arg < 6) {
		return ((void)ft_sort5(a, b));
	} else if (arg < 100) {
		chunk = 2;
	} else if (arg < 500) {
		chunk = 5;
	} else {
		chunk = 10;
	}
	i = 0;
	ft_chunk(a, b, chunk);
	while (chunk - ++i >= 0) {
		ft_sort(a, b, arg * (chunk - i) / chunk);
	}
	while (((t_data *)(*a)->content)->index != 0) {
		rra(a);
	}
}
