#include "push_swap.h"

void    sort_three_elements(t_list **stack_a) {
    int max_index = get_max_index_in_stack(*stack_a);
    
    if (get_position_of_element_with_index(*stack_a, max_index) == 0) {
        ra(stack_a);
    } else if (get_position_of_element_with_index(*stack_a, max_index) == 1) {
        rra(stack_a);
    }
    if (!is_stack_sorted(*stack_a)) {
        sa(stack_a);
    }
}
