#include "push_swap.h"

int	main(int argc, char **argv) {
	t_list	*a;
	t_list	*b;

	--argc;
	++argv;
	if (argc == 0) {
		return (EXIT_SUCCESS);
	}
	a = NULL;
	b = NULL;
	if (!parse_args(argv, &a)) {
		ft_lstclear(&a, free);
		return (EXIT_FAILURE);
	}
	push_swap(&a, &b, argc);
	ft_lstclear(&a, free);
	return (EXIT_SUCCESS);
}
