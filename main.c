#include "hackaton.h"

int		counter_employee(t_employee *data)
{
	int				i;

	i = 0;
	while (data[i].age)
		i++;
	return (i);
}

void	discrimination_detector(int median_male, int median_female, int counter_male, int counter_female)
{
	double	difference;
	double	marge_ok;
	double	reliable;

	difference = ((double)median_male / (double)median_female);
	marge_ok = (1.000000/(counter_male > counter_female ? counter_female : counter_male));
	reliable = 100 - (1000.000 /(double)(counter_male > counter_female ? counter_female : counter_male));
	if ((difference > (marge_ok + 1.000000) || difference < (-marge_ok + 1.000000)) && reliable > 5.000)
	{
		printf("\033[0;31m");
		printf("\t\t\tDISCRIMINATION DUE TO BIAS\n");
		if (difference > 1)
			printf("\t\t\tMALES EARN %f %% MORE THAN FEMALES\n", (difference - 1.0000) * 100.000);
		else
			printf("\t\t\tFEMALES EARN %f %% MORE THAN MALES\n", (((double)median_female / (double)median_male) - 1.0000) * 100.000);
		printf("\t\t\tOUR RESULT IS %f %% RELIABLE\n", reliable);
		printf("\033[0m");
	}
}

int		main(int argc, char **argv)
{
	t_employee		*data;
	t_employee		*filtered;
	char			**countries;
	char			jobs[6][20] = {"Back-end", "Front-end", "Full-stack", "DevOps", "Mobile ", "Data "};
	int				min_max[4][2] = {{0, 2},{3, 5},{6, 11}, {12, 1000}};
	int				counter_male;
	int				counter_female;

	data = parse(argv[1]);
	countries = find_countries(data);
	int i = 0;
	int j = 0;
	int	x = 0;
	if (argc == 2 || argv[2][0] == 'E')
	{
	printf("EXPERIENCE PRECISION :\n\n");
	while (countries[i])
	{
		j = 0;
		while (j < 6)
		{
			x = 0;
			while (x < 4)
			{
				filtered = key_finder(countries[i], jobs[j], data, min_max[x][0], min_max[x][1]);
				if (counter_employee(filtered) > 50 && median_salary(1, filtered, &counter_male) && counter_male > 5)
					{
						printf("- %s\n", countries[i]);
						printf("\t- %s :\n", jobs[j]);
						printf("\t\t- EXPERIENCE : %d - %d Y :\n", min_max[x][0], min_max[x][1]);
						printf("\t\t\t- Female median salary : %d (for %d persons)\n", median_salary(1, filtered, &counter_female), counter_female);
						printf("\t\t\t- Male median salary : %d (for %d persons)\n", median_salary(0, filtered, &counter_male), counter_male);
						discrimination_detector(median_salary(0, filtered, &counter_male), median_salary(1, filtered, &counter_female), counter_male, counter_female);
					}
				free(filtered);
				x++;
			}
			j++;
		}
		i++;
	}
	}
	else if (argv[2][0] == 'D')
	{
	i = 0;
	printf("DEVTYPE PRECISION :\n\n");
	while (countries[i])
	{
		j = 0;
		while (j < 6)
		{
			filtered = key_finder(countries[i], jobs[j], data, 0, 1000);
			if (counter_employee(filtered) > 50 && median_salary(1, filtered, &counter_male) && counter_male > 5)
				{
					printf("- %s\n", countries[i]);
					printf("\t- %s :\n", jobs[j]);
					printf("\t\t\t- Female median salary : %d (for %d persons)\n", median_salary(1, filtered, &counter_female), counter_female);
					printf("\t\t\t- Male median salary : %d (for %d persons)\n", median_salary(0, filtered, &counter_male), counter_male);
					discrimination_detector(median_salary(0, filtered, &counter_male), median_salary(1, filtered, &counter_female), counter_male, counter_female);
				}
			free(filtered);
			j++;
		}
		i++;
	}
	}
	else if (argv[2][0] == 'C')
	{
		i = 0;
		printf("COUNTRY PRECISION :\n\n");
		while (countries[i])
		{
			filtered = key_finder(countries[i], "", data, 0, 1000);
			if (counter_employee(filtered) > 50 && median_salary(1, filtered, &counter_male) && counter_male > 5)
				{
					printf("- %s\n", countries[i]);
					printf("\t\t\t- Female median salary : %d (for %d persons)\n", median_salary(1, filtered, &counter_female), counter_female);
					printf("\t\t\t- Male median salary : %d (for %d persons)\n", median_salary(0, filtered, &counter_male), counter_male);
					discrimination_detector(median_salary(0, filtered, &counter_male), median_salary(1, filtered, &counter_female), counter_male, counter_female);
				}
			free(filtered);
			i++;
		}
	}
}