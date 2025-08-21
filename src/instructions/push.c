#include "push_swap.h"

static void	push(t_list **from, t_list **to) {
	t_list	*tmp;

	if (!from || !(*from)) {
		return ;
	}
	tmp = (*from);
	(*from) = (*from)->next;
	tmp->next = (*to);
	(*to) = tmp;
}

void	pa(t_list **from, t_list **to) {
	push(from, to);
	write(1, "pa\n", 3);
}

void	pb(t_list **from, t_list **to) {
	push(from, to);
	write(1, "pb\n", 3);
}