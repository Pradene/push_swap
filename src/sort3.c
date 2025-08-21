#include "push_swap.h"

void    ft_sort3a(t_list **a, t_list **b) {
    if (ft_get_pos(*a, ft_getmax(*a)) == 0) {
        ra(a);
    } else if (ft_get_pos(*a, ft_getmax(*a)) == 1) {
        rra(a);
    }
    if (!is_sorted(*a)) {
        ft_sort2a(a, b);
    }
}

void    ft_sort3b(t_list **a, t_list **b) {
    if (ft_get_pos(*b, ft_getmax(*b)) == 0) {
        rb(b);
    } else if (ft_get_pos(*b, ft_getmax(*b)) == 1) {
        rrb(b);
    }
    ft_sort2b(a, b);
    rrb(b);
}