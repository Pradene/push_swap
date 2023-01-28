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

void	ft_push(t_list *from, t_list *to)
{
	t_element	*e;

	if (!ft_lstsize(from))
		return ;
	e = from->first;
	from->first = from->first->next;
	e->next = to->first;
	to->first = e;
}
