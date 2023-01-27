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

int	ft_getmax(t_list *lst)
{
	t_element	*element;
	int			max;

	max = INT_MIN;
	element = lst->first;
	while (element)
	{
		if (element->index > max)
			max = element->index;
		element = element->next;
	}
	return (max);
}

int	ft_getmin(t_list *lst, int n)
{
	t_element	*element;
	int			min;

	min = INT_MAX;
	element = lst->first;
	while (element)
	{
		if (element->index < min && element->index >= n)
			min = element->index;
		element = element->next;
	}
	return (min);
}

void	ft_chunk(t_list *a, t_list *b, int chunk)
{
	t_element	*element;
	int			pivot;
	int			size;
	int			i;

	element = a->first;
	size = ft_lstsize(a);
	i = 0;
	while (size * (++i) / chunk <= size)
	{
		pivot = size * i / chunk;
		while (ft_getmin(a, 0) < pivot)
		{
			element = a->first;
			if (!element)
				return ;
			if (element->index < pivot)
				ft_push_b(a, b);
			else
				ft_rotate(a, "ra\n");
		}
	}
}

int	ft_get_pos(t_list *lst, int n)
{
	t_element	*element;
	int			pos;

	element = lst->first;
	pos = 0;
	while (element)
	{
		if (element->index == n)
			break ;
		++pos;
		element = element->next;
	}
	return (pos);
}

int	ft_get_move(t_list *lst, int n)
{
	int			size;
	int			pos;

	size = ft_lstsize(lst);
	pos = ft_get_pos(lst, n);
	if (size / 2 > pos)
		return (pos);
	return (size - pos);
}

int	ft_get_nmove(t_list *lst, int n)
{
	if (ft_getmin(lst, n) == INT_MAX)
		return (0);
	return (ft_get_move(lst, ft_getmin(lst, n)));
}

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
