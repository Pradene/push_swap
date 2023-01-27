/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpradene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 04:14:25 by lpradene          #+#    #+#             */
/*   Updated: 2023/01/26 04:14:27 by lpradene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_sort3a(t_list *a)
{
	if (ft_get_pos(a, ft_getmax(a)) == 0)
		ft_rotate(a, "ra\n");
	else if (ft_get_pos(a, ft_getmax(a)) == 1)
		ft_reverse_rotate(a, "rra\n");
	if (!ft_check(a))
		ft_sort2a(a);
}

void	ft_sort3b(t_list *b)
{
	t_element	*element;

	element = b->first;
	if (ft_get_pos(b, ft_getmax(b)) == 0)
		ft_rotate(b, "rb\n");
	else if (ft_get_pos(b, ft_getmax(b)) == 1)
		ft_reverse_rotate(b, "rrb\n");
	ft_sort2b(b);
	ft_reverse_rotate(b, "rrb\n");
}
