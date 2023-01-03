/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayagmur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 18:31:46 by ayagmur           #+#    #+#             */
/*   Updated: 2022/12/31 18:31:49 by ayagmur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	pui(int i)
{
	int	v;

	v = 1;
	while (i > 0)
	{
		v = v * 10;
		i--;
	}
	return (v);
}

static int	get_size(int i)
{
	int	size;

	size = 1;
	while (i > 9)
	{
		i /= 10;
		size++;
	}
	return (size);
}

char	*ft_itoa(unsigned int nb)
{
	int		size;
	int		i;
	int		save;
	char	*str;

	i = nb;
	size = get_size(i);
	save = size;
	str = malloc(sizeof(char) * (size + 2));
	if (!str)
		return (0);
	i = 0;
	while (size - 1 > 0)
	{
		str[i++] = (nb / pui(size - 1)) + '0';
		nb %= pui(size - 1);
		size--;
	}
	str[save - 1] = nb + '0';
	str[save] = '\n';
	str[save + 1] = '\0';
	return (str);
}
