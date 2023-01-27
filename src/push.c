/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpradene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 16:13:42 by lpradene          #+#    #+#             */
/*   Updated: 2022/12/07 16:26:31 by lpradene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_push_a(t_list *a, t_list *b)
{
	t_element	*tmp;

	if (!ft_lstsize(b))
		return ;
	tmp = b->first;
	b->first = b->first->next;
	tmp->next = a->first;
	a->first = tmp;
	write(1, "pa\n", 3);
}

void	ft_push_b(t_list *a, t_list *b)
{
	t_element	*tmp;

	if (!ft_lstsize(a))
		return ;
	tmp = a->first;
	a->first = a->first->next;
	tmp->next = b->first;
	b->first = tmp;
	write(1, "pb\n", 3);
}
