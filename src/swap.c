/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpradene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 05:13:24 by lpradene          #+#    #+#             */
/*   Updated: 2022/12/07 16:27:28 by lpradene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_swap(t_list *lst, char *s)
{
	int	tmp_n;
	int	tmp_i;

	if (ft_lstsize(lst) <= 1)
		return ;
	tmp_n = lst->first->n;
	tmp_i = lst->first->index;
	lst->first->n = lst->first->next->n;
	lst->first->index = lst->first->next->index;
	lst->first->next->n = tmp_n;
	lst->first->next->index = tmp_i;
	write(1, s, 3);
}
