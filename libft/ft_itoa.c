/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 15:27:16 by abonnel           #+#    #+#             */
/*   Updated: 2020/12/02 08:47:04 by abonnel          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*create_a(int n, int *digits)
{
	long int				n_bis;
	char					*a_nb;

	*digits = 1;
	n_bis = n;
	if (n_bis < 0)
	{
		*digits += 1;
		n_bis *= -1;
	}
	while (n_bis >= 10)
	{
		*digits += 1;
		n_bis /= 10;
	}
	if (!(a_nb = (char *)malloc(sizeof(char) * (*digits + 1))))
		return (NULL);
	if (n < 0)
		a_nb[0] = '-';
	a_nb[*digits] = '\0';
	return (a_nb);
}

char			*ft_itoa(int n)
{
	char					*a_nb;
	int						digits;
	long int				n_bis;

	if (!(a_nb = create_a(n, &digits)))
		return (NULL);
	n_bis = n;
	if (n_bis < 0)
		n_bis *= -1;
	while (digits >= 0)
	{
		digits--;
		if ((n < 0 && digits == 0) || (digits < 0))
			break ;
		a_nb[digits] = n_bis % 10 + 48;
		n_bis /= 10;
	}
	return (a_nb);
}
