#ifndef HACKATON_H
# define HACKATON_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <string.h>
# include <ctype.h>
# include <math.h>
# include "libft/libft.h"
# include "gnl/get_next_line.h"

typedef struct 	s_employee
{
	int		id;
	int		age;
	int		salary;
	int		gender;
	int     years_coding;
    int     years_coding_pro;
	char    *country;
    int     student;
    char    *devtype;
}				t_employee;

t_employee		*parse(char *file);
t_employee		*key_finder(char *key_country, char *key_devtype, t_employee *initial_data, int min, int max);
int				counter_employee(t_employee *data);
void			print_data(t_employee *data);
char			**find_countries(t_employee *data);
char			**find_jobs(t_employee *data);
int				median_salary(int gender,  t_employee *data, int *counter);

#endif