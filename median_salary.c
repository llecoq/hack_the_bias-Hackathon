#include "hackaton.h"

void		sort_tab(int **tab)
{
	int 	i;
	int		tmp;
	int		j;

	i = 0;
	while ((*tab)[i])
	{
		j = i + 1;
		while ((*tab)[j])
		{
			if ((*tab)[i] > (*tab)[j])
			{
				tmp = (*tab)[i];
				(*tab)[i] = (*tab)[j];
				(*tab)[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

int			median_salary(int gender,  t_employee *data, int *counter)
{
	int		*salaries;
	int		i;
	int		j;

	salaries = malloc(sizeof(int) * (counter_employee(data) + 1));
	i = 0;
	j = 0;
	while (data[i].age)
	{
		if (data[i].gender == gender)
		{
			salaries[j] = data[i].salary;
			j++;
		}
		i++;
	}
	salaries[j] = 0;
	*counter = j;
	sort_tab(&salaries);
	return (salaries[(int)(j / 2)]);
}