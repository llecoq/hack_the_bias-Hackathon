/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 10:01:07 by abonnel           #+#    #+#             */
/*   Updated: 2020/12/02 08:12:36 by abonnel          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		is_set(char c, char const *set)
{
	int			j;

	j = -1;
	while (set[++j])
		if (c == set[j])
			return (1);
	return (0);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	char		*r;
	int			s;
	int			e;
	int			i;

	if (!s1 || !set)
		return (0);
	s = 0;
	while (is_set(s1[s], set) && s1[s])
		s++;
	e = ft_strlen(s1) - 1;
	while (is_set(s1[e], set) && e > 0)
		e--;
	if (e < s)
		e = s - 1;
	if (!(r = (char *)malloc(sizeof(char) * (e - s + 2))))
		return (0);
	i = -1;
	while (++i < (e - s + 1))
		r[i] = s1[s + i];
	r[i] = '\0';
	return (r);
}
