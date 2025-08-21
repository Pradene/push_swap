#include "push_swap.h"

void	ft_chunk(t_list **a, t_list **b, int chunk) {
	t_list	*tmp;
	int		pivot;
	int		size;
	int		i;

	if (!a || !(*a) || chunk <= 0) {
		return ;
	}

	size = ft_lstsize((*a));
	i = 0;
	while (size * (++i) / chunk <= size) {
		pivot = size * i / chunk;
		while (ft_getmin((*a), 0) < pivot) {
			tmp = *a;
			if (!tmp) {
				return ;
			}
			if (((t_data *)tmp->content)->index < pivot) {
				pb(a, b);
			} else {
				ra(a);
			}
		}
	}
}
