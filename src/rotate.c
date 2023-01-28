/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpradene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 05:23:58 by lpradene          #+#    #+#             */
/*   Updated: 2022/12/07 16:30:07 by lpradene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_rotate(t_list *lst)
{
	t_element	*tmp;
	t_element	*last;

	if (!lst || !lst->first || ft_lstsize(lst) == 1)
		return ;
	tmp = lst->first;
	lst->first = lst->first->next;
	last = ft_lstlast(lst);
	last->next = tmp;
	tmp->next = NULL;
}
