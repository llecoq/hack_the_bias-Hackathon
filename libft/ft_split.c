/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 12:41:24 by abonnel           #+#    #+#             */
/*   Updated: 2020/12/07 10:37:24 by abonnel          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			nb_parts(char const *s, char c)
{
	int		i;
	int		nb;

	i = 0;
	nb = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i])
		{
			nb++;
			while (s[i] != c && s[i])
				i++;
		}
	}
	return (nb);
}

static char			*fill_parts(char const *s, char c, int *b)
{
	char			*part;
	int				i;
	int				e;

	while (s[*b] == c && s[*b])
		*b += 1;
	e = *b;
	while (s[e] != c && s[e])
		e++;
	if (!(part = (char *)malloc(sizeof(char) * (e - *b + 1))))
		return (0);
	i = -1;
	while (++i < e - *b)
		part[i] = s[*b + i];
	part[i] = '\0';
	*b = e;
	return (part);
}

char				**ft_split(char const *s, char c)
{
	char		**parts;
	int			count;
	int			i;
	int			b;

	if (!s)
		return (0);
	count = nb_parts(s, c);
	if (!(parts = (char **)malloc(sizeof(char *) * (count + 1))))
		return (0);
	parts[count] = NULL;
	b = 0;
	i = -1;
	while (++i < count)
		if (!(parts[i] = fill_parts(s, c, &b)))
			return (0);
	return (parts);
}
