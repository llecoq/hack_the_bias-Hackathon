/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 15:38:34 by abonnel           #+#    #+#             */
/*   Updated: 2020/12/02 11:01:10 by abonnel          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*s_bis;
	unsigned char	c_bis;

	if (n == 0)
		return (0);
	s_bis = (unsigned char *)s;
	c_bis = (unsigned char)c;
	i = 0;
	while (s_bis[i] != c_bis && i < n - 1)
		i++;
	if (s_bis[i] == c_bis)
		return ((void*)(s + i));
	return (0);
}
