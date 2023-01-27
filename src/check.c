/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpradene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 17:18:31 by lpradene          #+#    #+#             */
/*   Updated: 2022/12/04 22:47:01 by lpradene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_check(t_list *lst)
{
	t_element	*element;

	element = lst->first;
	while (element->next)
	{
		if (element->n > element->next->n)
			return (0);
		element = element->next;
	}
	return (1);
}
