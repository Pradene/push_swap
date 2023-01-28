/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpradene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 00:33:26 by lpradene          #+#    #+#             */
/*   Updated: 2023/01/28 00:33:28 by lpradene         ###   ########.fr       */
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
