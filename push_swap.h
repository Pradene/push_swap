/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpradene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 04:18:58 by lpradene          #+#    #+#             */
/*   Updated: 2022/12/12 21:02:30 by lpradene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

# include <stdio.h>

typedef struct s_element
{
	int					n;
	int					index;
	struct s_element	*next;
}	t_element;

typedef struct s_list
{
	t_element	*first;
}	t_list;

t_element	*ft_lstlast(t_list *lst);
t_element	*ft_lstslast(t_list *lst);
int			ft_lstsize(t_list *lst);
void		ft_lstadd(t_list *lst, int n);
void		ft_lstclear(t_list *lst);

void		ft_lstprint(t_list *a, t_list *b);

int			ft_check(t_list *lst);
void		ft_check_dup(t_list *lst, int n);
void		ft_check_args(t_list *lst, int n, char *str);

void		ft_init(t_list *a, int argc, char **argv);

void		ft_rotate(t_list *lst);
void		ft_swap(t_list *lst);
void		ft_reverse_rotate(t_list *lst);
void		ft_push(t_list *from, t_list *to);
void		ft_instruction(t_list *a, t_list *b, char *s);

int			ft_getmax(t_list *lst);
int			ft_getmin(t_list *lst, int n);
int			ft_get_pos(t_list *lst, int n);
int			ft_get_move(t_list *lst, int n);
int			ft_get_nmove(t_list *lst, int n);

void		ft_chunk(t_list *a, t_list *b, int chunk);
void		ft_push_swap(t_list *a, t_list *b, int arg);

int			ft_strlen(const char *s);
int			ft_atoi(const char *str);
char		*ft_itoa(int n);
int			ft_strncmp(const char *str1, const char *str2, size_t n);

void		ft_sort2a(t_list *a, t_list *b);
void		ft_sort2b(t_list *a, t_list *b);
void		ft_sort3a(t_list *a, t_list *b);
void		ft_sort3b(t_list *a, t_list *b);
void		ft_sort5(t_list *a, t_list *b);

#endif
