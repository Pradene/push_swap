/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpradene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 03:31:15 by lpradene          #+#    #+#             */
/*   Updated: 2023/01/28 03:31:57 by lpradene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_check_dup(t_list *lst, int n)
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

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{																				
	size_t	i;

	i = 0;
	while (i < n)
	{
		if ((unsigned char)str1[i] != (unsigned char)str2[i])
			return ((unsigned char)str1[i] - (unsigned char)str2[i]);
		i++;
	}
	return (0);
}

void	ft_check_args(t_list *lst, int n, char *str)
{
	char	*s;

	s = ft_itoa(n);
	if (ft_strncmp(s, str, ft_strlen(str)))
		return (write(2, "Error\n", 6), free(s), ft_lstclear(lst),
			exit(EXIT_FAILURE));
	free(s);
}

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
