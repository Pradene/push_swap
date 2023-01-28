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

void	ft_move_b(t_list *a, t_list *b, int n)
{
	int	pos;
	int	size;

	size = ft_lstsize(b);
	pos = ft_get_pos(b, n);
	if (pos > size / 2)
		while (b->first->index != n)
			ft_instruction(a, b, "rrb");
	else
		while (b->first->index != n)
			ft_instruction(a, b, "rb");
}

void	ft_move_a(t_list *a, t_list *b, int n)
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
			ft_instruction(a, b, "ra");
	else if (pos > size / 2)
		while (a->first->index != min)
			ft_instruction(a, b, "rra");
	else
		while (a->first->index != min)
			ft_instruction(a, b, "ra");
}

void	ft_sort(t_list *a, t_list *b, int n)
{
	int	elem_index;

	while (ft_getmax(b) >= n)
	{
		elem_index = ft_get_elemindex(a, b, n);
		ft_move_b(a, b, elem_index);
		ft_move_a(a, b, elem_index);
		ft_instruction(a, b, "pa");
	}
}

void	ft_push_swap(t_list *a, t_list *b, int arg)
{
	int	chunk;
	int	i;

	if (arg == 2)
		return ((void)ft_sort2a(a, b));
	else if (arg == 3)
		return ((void)ft_sort3a(a, b));
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
		ft_instruction(a, b, "rra");
}
