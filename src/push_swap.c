/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpradene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 04:18:45 by lpradene          #+#    #+#             */
/*   Updated: 2022/12/16 16:40:25 by lpradene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_get_elemindex(t_list *a, t_list *b, int n)
{
	t_element	*element;
	int			elem_index;
	int			move;

	element = b->first;
	elem_index = element->index;
	move = INT_MAX;
	while (element)
	{
		if (element->index >= n)
		{
			if (ft_get_move(b, element->index)
				+ ft_get_nmove(a, element->index) < move)
			{
				elem_index = element->index;
				move = ft_get_move(b, element->index)
					+ ft_get_nmove(a, element->index);
			}
		}
		element = element->next;
	}
	return (elem_index);
}

void	ft_move_b(t_list *b, int n)
{
	int	pos;
	int	size;

	size = ft_lstsize(b);
	pos = ft_get_pos(b, n);
	if (pos > size / 2)
		while (b->first->index != n)
			ft_reverse_rotate(b, "rrb\n");
	else
		while (b->first->index != n)
			ft_rotate(b, "rb\n");
}

void	ft_move_a(t_list *a, int n)
{
	int	size;
	int	pos;
	int	min;

	min = ft_getmin(a, n);
	pos = ft_get_pos(a, min);
	size = ft_lstsize(a);
	if (!size)
		return ;
	if (min == INT_MAX)
		while (a->first->index != ft_getmin(a, 0))
			ft_rotate(a, "ra\n");
	else if (pos > size / 2)
		while (a->first->index != min)
			ft_reverse_rotate(a, "rra\n");
	else
		while (a->first->index != min)
			ft_rotate(a, "ra\n");
}

void	ft_sort(t_list *a, t_list *b, int n)
{
	int	elem_index;

	while (ft_getmax(b) >= n)
	{
		elem_index = ft_get_elemindex(a, b, n);
		ft_move_b(b, elem_index);
		ft_move_a(a, elem_index);
		ft_push_a(a, b);
	}
}

void	ft_push_swap(t_list *a, t_list *b, int arg)
{
	int	chunk;
	int	i;

	if (arg == 2)
		return ((void)ft_sort2a(a));
	else if (arg == 3)
		return ((void)ft_sort3a(a));
	else if (arg < 6)
		return ((void)ft_sort5(a, b));
	else if (arg < 100)
		chunk = 2;
	else if (arg < 500)
		chunk = 5;
	else
		chunk = 10;
	i = 0;
	ft_chunk(a, b, chunk);
	while (chunk - ++i >= 0)
		ft_sort(a, b, arg * (chunk - i) / chunk);
	while (a->first->index != 0)
		ft_reverse_rotate(a, "rra\n");
}
