/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpradene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 00:37:39 by lpradene          #+#    #+#             */
/*   Updated: 2023/01/28 00:37:40 by lpradene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_strlen(const char *s)
{
	int	n;

	n = 0;
	while (s[n])
		++n;
	return (n);
}

static int	count(int n)
{
	int	len;
	int	on;

	on = 1;
	len = 0;
	if (n < 0)
		len++;
	while (n || on)
	{
		on = 0;
		n /= 10;
		len++;
	}
	return (len);
}

static void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = -1;
	while (++i < n)
		((char *)dest)[i] = ((char *)src)[i];
	return (dest);
}

static char	*ft_strdup(const char *s)
{
	char	*str;
	int		size;

	size = ft_strlen(s);
	str = malloc(sizeof(char) * (size + 1));
	if (!str)
		return (0);
	ft_memcpy(str, s, size);
	str[size] = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	int		i;
	int		len;
	char	*a;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	i = n;
	if (n < 0)
		i = -n;
	len = count(n);
	a = malloc(sizeof(char) + (len + 1));
	if (!a)
		return (NULL);
	a[len] = '\0';
	if (!n)
		a[0] = '0';
	else if (n < 0)
		a[0] = '-';
	while (i > 0)
	{
		--len;
		a[len] = i % 10 + '0';
		i = i / 10;
	}
	return (a);
}
