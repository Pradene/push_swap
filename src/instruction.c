/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpradene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 03:29:57 by lpradene          #+#    #+#             */
/*   Updated: 2023/01/28 03:29:58 by lpradene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_instruction(t_list *a, t_list *b, char *s)
{
	if (!ft_strncmp(s, "rra", 3))
		ft_reverse_rotate(a);
	else if (!ft_strncmp(s, "rrb", 3))
		ft_reverse_rotate(b);
	else if (!ft_strncmp(s, "ra", 2))
		ft_rotate(a);
	else if (!ft_strncmp(s, "rb", 2))
		ft_rotate(b);
	else if (!ft_strncmp(s, "pa", 2))
		ft_push(b, a);
	else if (!ft_strncmp(s, "pb", 2))
		ft_push(a, b);
	else if (!ft_strncmp(s, "sa", 2))
		ft_swap(a);
	else if (!ft_strncmp(s, "sb", 2))
		ft_swap(b);
	else
		return ;
	write(1, s, ft_strlen(s));
	write(1, "\n", 1);
}
