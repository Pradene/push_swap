#include "push_swap.h"

int	main(int argc, char **argv) {
	t_list	*stack_a;
	t_list	*stack_b;
	int		result;

	--argc;
	++argv;
	if (argc == 0) {
		return (EXIT_SUCCESS);
	}
	stack_a = NULL;
	stack_b = NULL;
	if (!parse_args(argv, &stack_a)) {
		ft_lstclear(&stack_a, free);
		return (EXIT_FAILURE);
	}
	compute_final_index(stack_a);
	if (!is_stack_sorted(stack_a)) {
		push_swap(&stack_a, &stack_b);
	}
	result = !(ft_lstsize(stack_a) == argc && is_stack_sorted(stack_a));
	ft_lstclear(&stack_a, free);
	return (result);
}
