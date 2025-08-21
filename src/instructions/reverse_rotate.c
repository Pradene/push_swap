#include "push_swap.h"

static void	reverse_rotate(t_list **lst) {
	t_list	*prev;
	t_list	*last;

	if (!lst || !(*lst) || !(*lst)->next) {
		return ;
	}
	prev = NULL;
	last = (*lst);
	while (last->next) {
		prev = last;
		last = last->next;
	}
	if (prev) {
		prev->next = NULL;
	}
	last->next = (*lst);
	(*lst) = last;
}

void	rra(t_list **lst) {
	reverse_rotate(lst);
	write(1, "rra\n", 4);
}

void	rrb(t_list **lst) {
	reverse_rotate(lst);
	write(1, "rrb\n", 4);
}

void	rrr(t_list **a, t_list **b) {
	reverse_rotate(a);
	reverse_rotate(b);
	write(1, "rrr\n", 4);
}