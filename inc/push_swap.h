#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "libft.h"

#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

typedef struct s_data {
	int	n;
	int	index;
}	t_data;

// Instructions
void	pa(t_list **b, t_list **a);
void	pb(t_list **a, t_list **b);

void	ra(t_list **a);
void	rb(t_list **b);
void	rr(t_list **a, t_list **b);

void	rra(t_list **a);
void	rrb(t_list **b);
void	rrr(t_list **a, t_list **b);

void	sa(t_list **a);
void	sb(t_list **b);
void	ss(t_list **a, t_list **b);

int		ft_getmax(t_list *lst);
int		ft_getmin(t_list *lst, int n);
int		ft_get_pos(t_list *lst, int n);
int		ft_get_move(t_list *lst, int n);
int		ft_get_nmove(t_list *lst, int n);
int		get_min(t_list *lst);
int		get_min_above(t_list *lst, int n);

bool	is_sorted(t_list *lst);
void	ft_chunk(t_list **a, t_list **b, int chunk);

void	ft_sort2a(t_list **a, t_list **b);
void	ft_sort2b(t_list **a, t_list **b);
void	ft_sort3a(t_list **a, t_list **b);
void	ft_sort3b(t_list **a, t_list **b);
void	ft_sort5(t_list **a, t_list **b);
void	print_stack(t_list *lst);

void	push_swap(t_list **a, t_list **b, int arg);
bool	parse_args(char **av, t_list **stack_a);

#endif
