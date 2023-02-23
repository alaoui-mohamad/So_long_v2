
#include "../so_long.h"


int player_position(char **line)
{
	int i;
	int j;
	int n;

	i = 0;
	j = 0;
	n = ft_strlen(line[0]);
	while (line[i])
	{
		while (line[i][j])
		{
			if (line[i][j] == 'P')
			{
				return (i * n + j);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}
char *check_path_valid(char *line, int position, int n)
{
	line[position] = '1';
	if (line[position - 1] == '0' || line[position - 1] == 'C')
		check_path_valid(line, position - 1, n);
	if (line[position + 1] == '0' || line[position + 1] == 'C')
		check_path_valid(line, position + 1, n);
	if (line[position - n] == '0'  || line[position - n] == 'C')
		check_path_valid(line, position - n, n);
	if (line[position + n] == '0' || line[position + n] == 'C')
		check_path_valid(line, position + n, n);
	
	return (line);
}

int check_path(char *line)
{
	int i;

	i = 0;
	while(line[i])
	{
		if (line[i] == 'C')
		{
			printf("Error map not valid (not path) \n");
			exit(0);
		}
		i++;
	}
	return (1);
}
// int exit_isblocked(char *line , int pos_e)
// {
//     // int i;

//     // i = 0;
//     // while(line[i])
//     // {
//     //     if 
//     // }
//     // return (1);
// }