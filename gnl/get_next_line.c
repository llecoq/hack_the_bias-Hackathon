/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 07:39:56 by abonnel           #+#    #+#             */
/*   Updated: 2021/03/05 11:10:32 by abonnel          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int				n_in(char *str)
{
	int				i;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		return (i);
	if (str[i] == '\0')
		return (-1);
	return (-2);
}

void			free_set_null(char **ptr)
{
	if (*ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
}

int				get_next_line(int fd, char **line)
{
	char			buf[OPEN_MAX];
	int				n_pos;
	int				nb_bytes;
	static char		*stash = NULL;

	if (!line || fd < 0)
		return (-1);
	if (!stash)
		stash = calloc(2, sizeof(char));
	while ((n_pos = n_in(stash)) == -1)
	{
		nb_bytes = read(fd, buf, OPEN_MAX - 1);
		if (nb_bytes <= 0)
		{
			if (nb_bytes == 0)
				*line = ft_strdup(stash);
			free_set_null(&stash);
			return (nb_bytes);
		}
		buf[nb_bytes] = '\0';
		stash = ft_strjoin(stash, buf);
	}
	*line = ft_substr(stash, 0, n_pos);
	stash = ft_substr(stash, n_pos + 1, strlen(stash) - (n_pos + 1));
	return (1);
}

