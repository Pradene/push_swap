#include "push_swap.h"

static void	rotate(t_list **lst) {
	t_list	*tmp;
	t_list	*last;

	if (!lst || !(*lst) || !(*lst)->next) {
		return ;
	}
	tmp = (*lst);
	(*lst) = (*lst)->next;
	last = (*lst);
	while (last->next) {
		last = last->next;
	}
	last->next = tmp;
	tmp->next = NULL;
}

void	ra(t_list **lst) {
	rotate(lst);
	write(1, "ra\n", 3);
}

void	rb(t_list **lst) {
	rotate(lst);
	write(1, "rb\n", 3);
}

void	rr(t_list **a, t_list **b) {
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}