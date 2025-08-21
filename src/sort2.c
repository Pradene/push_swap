#include "push_swap.h"

void	ft_sort2a(t_list **a, t_list **b) {
	(void)b;
	if (!a || !*a || ft_lstsize(*a) < 2) {
		return ;
	}
	if (((t_data *)(*a)->content)->index > ((t_data *)(*a)->next->content)->index) {
		sa(a);
	}
}

void	ft_sort2b(t_list **a, t_list **b) {
	(void)a;
	if (!b || !*b || ft_lstsize(*b) < 2) {
		return ;
	}
	if (((t_data *)(*b)->content)->index < ((t_data *)(*b)->next->content)->index) {
		sb(b);
	}
}
