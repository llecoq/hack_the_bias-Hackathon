#include "hackaton.h"

int		not_in_list(char *country, char **countries)
{
	int		i;

	i = 0;
	while (countries[i])
	{
		if (strcmp(country, countries[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

char	**find_countries(t_employee *data)
{
	char	**countries;
	int		i;
	int		j;

	countries = malloc(sizeof(char *) * counter_employee(data));
	countries[0] = NULL;
	i = 0;
	j = 0;
	while (data[i].age)
	{
		if (not_in_list(data[i].country, countries))
		{
			countries[j] = ft_strdup(data[i].country);
			j++;
			countries[j] = NULL;
		}
		i++;
	}
	return (countries);
}

char	**find_jobs(t_employee *data)
{
	char	**devtypes;
	int		i;
	int		j;

	devtypes = malloc(sizeof(char *) * counter_employee(data));
	devtypes[0] = NULL;
	i = 0;
	j = 0;
	while (data[i].age)
	{
		if (not_in_list(data[i].devtype, devtypes))
		{
			devtypes[j] = ft_strdup(data[i].devtype);
			j++;
			devtypes[j] = NULL;
		}
		i++;
	}
	return (devtypes);
}