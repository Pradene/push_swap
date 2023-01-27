/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpradene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 17:32:46 by lpradene          #+#    #+#             */
/*   Updated: 2022/12/07 16:33:16 by lpradene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int argc, char **argv)
{
	t_list		a;
	t_list		b;

	if (argc == 1)
		return (0);
	a.first = NULL;
	b.first = NULL;
	ft_init(&a, argc, argv);
	if (!ft_check(&a))
		ft_push_swap(&a, &b, argc - 1);
	ft_lstclear(&a);
	ft_lstclear(&b);

	return (0);
}
