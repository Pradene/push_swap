#include "push_swap.h"

static void ft_lstsplit(t_list **a, t_list **b) {
    t_list  *element;
    int     size;
    t_data  *data;

    size = ft_lstsize(*a);
    element = *a;
    while (element && ft_getmin(*a, 0) < size / 2) {
        data = (t_data *)element->content;
        if (data->index < size / 2) {
            pb(a, b);
        } else {
            ra(a);
        }
        element = *a;
    }
}

void    ft_sort5(t_list **a, t_list **b) {
    ft_lstsplit(a, b);
    if (ft_lstsize(*a) == 3) {
        ft_sort3a(a, b);
    } else {
        ft_sort2a(a, b);
    }
    if (ft_lstsize(*b) == 3) {
        ft_sort3b(a, b);
    } else {
        ft_sort2b(a, b);
    }
    while (*b) {
        pa(b, a);
    }
}