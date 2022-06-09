#include "hackaton.h"

void	print_data(t_employee *data)
{
	int	i;

	i = 0;
	while (data[i].age)
	{
		dprintf(1, "%10d | %20.20s | %20d | %80.80s | %8d | %10d | %10d | %40d | %40d |\n", data[i].id, data[i].country, data[i].age, data[i].devtype, data[i].salary, data[i].student, data[i].gender, data[i].years_coding, data[i].years_coding_pro);
		i++;
	}
	printf("%10s | %20s | %20s | %80s | %8s | %10s | %10s | %40s | %40s |\n", "ID", "COUNTRY", "AGE", "DEVTTYPE", "SALARY", "STUDENT", "GENDER", "Y_CODING", "YCPRO");
	printf("\n\n%d lines\n\n", i);
}