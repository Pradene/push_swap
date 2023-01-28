/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpradene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 16:29:20 by lpradene          #+#    #+#             */
/*   Updated: 2022/12/07 16:29:45 by lpradene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_reverse_rotate(t_list *lst)
{
	t_element	*tmp;

	if (!lst->first->next)
		return ;
	tmp = ft_lstlast(lst);
	ft_lstslast(lst)->next = NULL;
	tmp->next = lst->first;
	lst->first = tmp;
}
