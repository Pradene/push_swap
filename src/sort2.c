/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpradene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 04:12:41 by lpradene          #+#    #+#             */
/*   Updated: 2023/01/26 04:12:42 by lpradene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_sort2a(t_list *a)
{
	t_element	*element;

	element = a->first;
	if (element->index > element->next->index)
		ft_swap(a, "sa\n");
}

void	ft_sort2b(t_list *b)
{
	t_element	*element;

	element = b->first;
	if (element->index < element->next->index)
		ft_swap(b, "sb\n");
}
