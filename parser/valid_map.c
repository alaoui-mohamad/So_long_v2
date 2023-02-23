#include "../so_long.h"

void check_heads(char *line)
{
	int j;

	j = 0;

	while (line[j])
	{
		printf("%c", line[j]);
		if (line[j] != '1')
		{
			printf("map not valid (not wall)");
			exit(0);
		}
		j++;
	}
}
int check_allowed_char(char *line)
{
	int i;
	int n;

	i = 0;
	n = strlen(line);
	while (i < n)
	{
		if (line[i] != '1' && line[i] != '0' && line[i] != 'C' && line[i] != 'E' && line[i] != 'P')
		{
			printf("map not valid (not allowed char)");
			exit(0);
		}
		i++;
	}
	return (1);
}
void delete_backslash(char *line)
{
	int i;
	int n;

	i = 0;
	n = strlen(line);
	while (i < n)
	{
		if (line[i] == '\n')
			line[i] = '\0';
		i++;
	}
}
int check_map_equal(char **line)
{
	int i;
	int j;
	int n;

	i = 0;
	j = 0;
	n = ft_strlen(line[0]);
	while (line[i])
	{
		if (ft_strlen(line[i]) != n)
		{
			printf("map not valid (not equal)");
			exit(0);
		}
		i++;
	}
	return (1);
}
int check_map_valid(char **line)
{
	t_st b;

	b.i = 0;
	b.j = 0;
	b.start = 0;
	b.end = 0;
	while (line[b.i])
	{
		while (line[b.i][b.j])
		{
			if (line[b.i][b.j] == 'P')
				b.start++;
			if (line[b.i][b.j] == 'E')
				b.end++;
			b.j++;
		}
		b.j = 0;
		b.i++;
	}
	if (b.start != 1 || b.end != 1)
	{
		printf("map not valid (more then one start or end))");
		exit(0);
	}
	return (1);
}