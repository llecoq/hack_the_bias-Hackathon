/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grosendo <grosendo@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 11:01:25 by grosendo          #+#    #+#             */
/*   Updated: 2021/03/05 14:11:33 by grosendo         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../hackaton.h"

int				counter_lines(int *fd, char *file)
{
	int		i;
	char	*line;

	i = 0;
	while (get_next_line(*fd, &line) == 1)
		i++;
	close(*fd);
	*fd = open(file, O_RDONLY);
	return (i);
}

void			change_bad_coma(char *s)
{
	while (*s)
	{
		while (*s && *s != '"')	
			s++;
		if (*s)
			s++;
		while (*s && *s != '"')
		{
			if (*s == ',')
				*s = '.';
			s++;
		}
		if (*s)
			s++;
	}
}

int				check_ok(char **split)
{
	int		i;

	if (strcmp(split[26], "NA") == 0
		|| strcmp(split[3], "NA") == 0
		|| strcmp(split[9], "NA") == 0
		|| strcmp(split[10], "NA") == 0
		|| !(strcmp(split[56], "Female") == 0 || strcmp(split[56], "Male") == 0)
		|| strcmp(split[3], "NA") == 0
		|| strcmp(split[8], "NA") == 0
		|| !(strstr(split[5], "full-time") || strstr(split[5], "part-time"))
		|| atoi(split[60]) == 0
		|| atoi(split[26]) == 0)
	 	return (0);
	i = 0;
	while (isdigit(split[26][i]))
		i++;
	if (split[26][i] != 0)
		return (0);
	return (1);
}

void		fill_data(t_employee *employee, char **split)
{
	(*employee).id = atoi(split[0]);
	(*employee).country = ft_strdup(split[3]);
	(*employee).age = atoi(split[60]);
	(*employee).devtype = ft_strdup(split[8]);
	(*employee).salary = atoi(split[26]);
	(*employee).student = (strcmp(split[4], "No") == 0) ? 0 : 1;
	(*employee).gender = (strcmp(split[56], "Male") == 0) ? 0 : 1;
	(*employee).years_coding = atoi(split[9]);
	(*employee).years_coding_pro = atoi(split[10]);
}

t_employee		*parse(char *file)
{
	int			fd;
	int			i;
	char		*line;
	char		**split;
	t_employee	*data;

	fd = open(file, O_RDONLY);
	printf("---- PARSING START ... -----\n\n\n");
	data = malloc(sizeof(t_employee) * (i = counter_lines(&fd, file) + 1));
	i = 0;
	while (get_next_line(fd, &line))
	{
		change_bad_coma(line);
		split = ft_split(line, ',');
		if (check_ok(split))
		{
			fill_data(&data[i], split);
			i++;
		}
		free_split(split);
	}
	data[i].age = 0;
	printf("---- PARSING SUCCESS -----\n\n\n");
	return (data);
}