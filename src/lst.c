/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpradene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 15:45:54 by lpradene          #+#    #+#             */
/*   Updated: 2022/12/06 15:48:27 by lpradene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_element	*ft_lstlast(t_list *lst)
{
	t_element	*element;

	if (!lst || !lst->first)
		return (NULL);
	element = lst->first;
	while (element->next)
		element = element->next;
	return (element);
}

t_element	*ft_lstslast(t_list *lst)
{
	t_element	*element;

	if (!lst || !lst->first)
		return (NULL);
	element = lst->first;
	if (!element->next)
		return (element);
	if (!element->next->next)
		return (element->next);
	while (element->next->next)
		element = element->next;
	return (element);
}

int	ft_lstsize(t_list *lst)
{
	int			count;
	t_element	*current;

	if (!lst->first)
		return (0);
	count = 0;
	current = lst->first;
	while (++count && current->next)
		current = current->next;
	return (count);
}

void	ft_lstadd(t_list *lst, int n)
{
	t_element	*element;

	element = malloc(sizeof(*element));
	if (element == NULL)
		return ;
	element->n = n;
	element->index = 0;
	element->next = NULL;
	if (lst->first == NULL)
		lst->first = element;
	else
		ft_lstlast(lst)->next = element;
}

void	ft_lstclear(t_list *lst)
{
	t_element	*tmp;

	while (lst->first)
	{
		tmp = lst->first;
		lst->first = tmp->next;
		free(tmp);
	}
}

// void	ft_lstprint(t_list *a, t_list *b)
// {
// 	t_element	*ae;
// 	t_element	*be;

// 	ae = a->first;
// 	be = b->first;
// 	while (ae || be)
// 	{
// 		if (ae)
// 			printf("%d %d", ae->index, ae->n);
// 		else
// 			printf(" ");
// 		printf(" | ");
// 		if (be)
// 			printf("%d %d\n", be->index, be->n);
// 		else
// 			printf("\n");
// 		if (ae)
// 			ae = ae->next;
// 		if (be)
// 			be = be->next;
// 	}
// }
