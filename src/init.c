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

static int	ft_small(t_list *lst, int n)
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
	min = INT_MIN;
	i = -1;
	while (++i < size)
	{
		element = lst->first;
		while (element)
		{
			if (element->n > min)
				element->index = i;
			element = element->next;
		}
		min = ft_small(lst, min);
	}
}

static void	ft_check_dup(t_list *lst, int n)
{
	t_element	*element;

	element = lst->first;
	while (element)
	{
		if (n == element->n)
		{
			write(2, "Error\n", 6);
			ft_lstclear(lst);
			exit(EXIT_FAILURE);
		}
		element = element->next;
	}
}

static void	ft_check_args(t_list *lst, int n, char *str)
{
	char	*s;

	s = ft_itoa(n);
	if (ft_strlen(s) != ft_strlen(str) || ((*str == '-' || *str == '+')
			&& ft_strlen(str) == 1))
		return (write(2, "Error\n", 6), free(s), ft_lstclear(lst),
			exit(EXIT_FAILURE));
	free(s);
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
