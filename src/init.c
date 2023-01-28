/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpradene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 17:44:49 by lpradene          #+#    #+#             */
/*   Updated: 2022/12/04 22:53:14 by lpradene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	ft_get_min(t_list* lst)
{
	t_element	*element;
	int			min;

	min = INT_MAX;
	element = lst->first;
	while (element)
	{
		if (element->n < min)
			min = element->n;
		element = element->next;
	}
	return (min);
}

static int	ft_get_minabove(t_list *lst, int n)
{
	t_element	*element;
	int			min;

	min = INT_MAX;
	element = lst->first;
	while (element)
	{
		if (element->n > n && element->n < min)
			min = element->n;
		element = element->next;
	}
	return (min);
}

static void	ft_init_index(t_list *lst)
{
	t_element	*element;
	int			min;
	int			size;
	int			i;

	size = ft_lstsize(lst);
	min = ft_get_min(lst);
	i = -1;
	while (++i < size)
	{
		element = lst->first;
		while (element)
		{
			if (element->n >= min)
				element->index = i;
			element = element->next;
		}
		min = ft_get_minabove(lst, min);
	}
}

static void	ft_init_n(t_list *a, int argc, char **argv)
{
	int			i;
	int			n;

	i = 0;
	while (++i < argc)
	{
		n = ft_atoi(argv[i]);
		ft_check_dup(a, n);
		ft_check_args(a, n, argv[i]);
		ft_lstadd(a, n);
	}
}

void	ft_init(t_list *a, int argc, char **argv)
{
	ft_init_n(a, argc, argv);
	ft_init_index(a);
}
