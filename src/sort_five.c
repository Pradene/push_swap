#include "push_swap.h"

static void push_until_three_elements_remain(t_list **stack_a, t_list **stack_b) {
    int     stack_size;
    int     target_index;
    int     target_position;

    if (!stack_a || !(*stack_a) || !stack_b) {
        return;
    }
    
    target_index = 0;
    stack_size = ft_lstsize(*stack_a);
    while (stack_size > 3) {
        target_position = get_position_of_element_with_index(*stack_a, target_index);
        
        if (target_position < 2) {
            while (--target_position >= 0)
                ra(stack_a);
        } else {
            while (++target_position <= stack_size)
                rra(stack_a);
        }
        pb(stack_a, stack_b);
        ++target_index;
        --stack_size;
    }
}

void sort_five_elements(t_list **stack_a, t_list **stack_b) {
    push_until_three_elements_remain(stack_a, stack_b);
    sort_three_elements(stack_a);
    while (*stack_b) {
        pa(stack_b, stack_a);
    }
}