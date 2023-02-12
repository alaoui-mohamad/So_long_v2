 
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <memory.h>

#define WIDTH 256
#define HEIGHT 256

typedef struct l_st
{
	void			*mlx;
	void			*win;
	void			*img;
	int				coins;
	int				x;
	int				y;
	int				row;
	int				columns;
	int				width;
	int				height;

	char			**arr;
	char			*str;
	int				p_i;
	int				p_j;
	int				j;
	int				i;
}				t_st;

#include <string.h>
#include "get_next_line/get_next_line_bonus.h"


size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (s1[i] && (s1[i] == s2[i]) && n--)
		i++;
	if (n == 0)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
char	*ft_strrchr(const char *s, int c)
{
	char	*str;

	int		len;

	str = (char *)s;
	len = ft_strlen(s);
	if ((char)c == '\0')
		return (str + len);
	while (len >= 0)
	{
		if (str[len] == (char)c)
			return (str + len);
		len--;
	}
	return (0);
}
void	ft_putstr_fd(char *s, int fd)
{
	int	i;
	if(!s)
		return ((void)0);
	i = ft_strlen(s);
	write(fd, s, i);
}
int read_file(char *path)
{
	char *extension;
	int fd;
	extension = ft_strrchr(path , '.');
	if (extension == 0  || ft_strncmp(".ber", extension, ft_strlen(extension)))
	{
		ft_putstr_fd("Error", 2);
	}
	fd = open(path, O_RDONLY | O_NOFOLLOW);
	
	return (fd);
}

char	**read_map(int ac , char **av)
{
	int i;
	static char *line;
	
	int  fd;
	fd = read_file(av[1]);

	char *str = get_next_line(fd);
	while (line)
	{
		if (ft_strchr(line, '\n') && ft_linelen(line) == 1)
		{
			printf("new line found");
			exit(0);
		}
		free(line);
		line = get_next_line(fd);
	}
	return (line);
}

int main(int ac, char **av)
{
	t_st *b;
	
	printf ("%s", read_map(ac, av));

}