/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 14:23:16 by abonnel           #+#    #+#             */
/*   Updated: 2020/11/30 13:42:37 by abonnel          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memset(void *b, int c, size_t len)
{
	size_t		i;
	char		*bis;

	bis = (char *)b;
	i = 0;
	while (i < len)
		bis[i++] = (unsigned char)c;
	return (bis);
}
