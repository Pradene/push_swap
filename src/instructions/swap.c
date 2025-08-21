#include "push_swap.h"

static void	swap(t_list **lst) {
	t_list	*first;
	t_list	*second;

	if (!lst || !(*lst) || !(*lst)->next) {
		return ;
	}
	first = (*lst);
	second = first->next;
	first->next = second->next;
	second->next = first;
	(*lst) = second;
}

void	sa(t_list **lst) {
	swap(lst);
	write(1, "sa\n", 3);
}

void	sb(t_list **lst) {
	swap(lst);
	write(1, "sb\n", 3);
}

void	ss(t_list **a, t_list **b) {
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
}