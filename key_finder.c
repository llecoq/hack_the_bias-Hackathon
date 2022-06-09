#include "hackaton.h"

t_employee		*key_finder(char *key_country, char *key_devtype, t_employee *initial_data, int min, int max)
{
	int			i;
	int			j;
	t_employee	*data;

	data = malloc(sizeof(t_employee) * (counter_employee(initial_data) + 1));
	i = 0;
	j = 0;
	while (initial_data[i].age)
	{
		if (strstr(initial_data[i].country, key_country)
			&& strstr(initial_data[i].devtype, key_devtype)
			&& initial_data[i].years_coding_pro >= min
			&& initial_data[i].years_coding_pro <= max)
			{
				data[j] = initial_data[i];
				j++;
			}
		i++;
	}
	data[j].age = 0;
	return (data);
}