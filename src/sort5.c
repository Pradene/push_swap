/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpradene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 04:13:44 by lpradene          #+#    #+#             */
/*   Updated: 2023/01/26 04:13:49 by lpradene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	ft_lstsplit(t_list *a, t_list *b)
{
	t_element	*element;
	int			size;

	size = ft_lstsize(a);
	while (ft_getmin(a, 0) < size / 2)
	{
		element = a->first;
		if (element->index < 2)
			ft_push_b(a, b);
		else
			ft_rotate(a, "ra\n");
	}
}

void	ft_sort5(t_list *a, t_list *b)
{
	ft_lstsplit(a, b);
	if (ft_lstsize(a) == 3)
		ft_sort3a(a);
	else
		ft_sort2a(a);
	if (ft_lstsize(b) == 3)
		ft_sort3b(b);
	else
		ft_sort2b(b);
	while (b->first)
		ft_push_a(a, b);
}
