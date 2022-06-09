/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grosendo <grosendo@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 14:51:45 by abonnel           #+#    #+#             */
/*   Updated: 2021/03/05 11:46:49 by grosendo         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char			*ft_strdup(const char *s1)
{
	int				s_len;
	char			*s_bis;
	int				i;

	s_len = strlen(s1);
	if (!(s_bis = (char *)malloc(sizeof(char) * (s_len + 1))))
		return (0);
	i = -1;
	while (s1[++i])
		s_bis[i] = s1[i];
	s_bis[i] = '\0';
	return (s_bis);
}

char			*ft_strjoin(char *s1, char *s2)
{
	int				s1_len;
	int				s2_len;
	char			*r;
	int				i;

	if (!s2)
		return (0);
	if (!s1)
	{
		r = ft_strdup(s2);
		return (r);
	}
	s1_len = strlen(s1);
	s2_len = strlen(s2);
	if (!(r = (char *)malloc((s1_len + s2_len + 1) * sizeof(char))))
		return (0);
	i = -1;
	while (++i < s1_len)
		r[i] = s1[i];
	i = -1;
	while (++i < s2_len)
		r[s1_len + i] = s2[i];
	r[s1_len + i] = '\0';
	free_set_null(&s1);
	return (r);
}

char			*ft_substr(char *s, unsigned int start, size_t len)
{
	char			*new;
	size_t			i;
	size_t			s_len;

	if (!s)
		return (0);
	s_len = strlen(s);
	if (start >= s_len)
		len = 0;
	if (len > s_len)
		len = s_len;
	if ((!(new = (char *)malloc(len + 1))))
		return (0);
	i = -1;
	while (++i < len)
		new[i] = s[start + i];
	new[i] = '\0';
	if (start != 0)
		free_set_null(&s);
	return (new);
}
