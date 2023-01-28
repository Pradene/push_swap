/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpradene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 00:52:24 by lpradene          #+#    #+#             */
/*   Updated: 2023/01/28 00:52:26 by lpradene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_chunk(t_list *a, t_list *b, int chunk)
{
	t_element	*element;
	int			pivot;
	int			size;
	int			i;

	element = a->first;
	size = ft_lstsize(a);
	i = 0;
	while (size * (++i) / chunk <= size)
	{
		pivot = size * i / chunk;
		while (ft_getmin(a, 0) < pivot)
		{
			element = a->first;
			if (!element)
				return ;
			if (element->index < pivot)
                ft_instruction(a, b, "pb");
			else
                ft_instruction(a, b, "ra");
		}
	}
}
