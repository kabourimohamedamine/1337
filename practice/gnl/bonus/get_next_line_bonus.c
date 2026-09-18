#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*block;
	char		a[BUFFER_SIZE];
	char		*c;
	int			bytes;

	block = NULL;
	while (!check_new_line(block))
	{
		bytes = read(fd, a, BUFFER_SIZE);
		if (bytes <= 0)
			break ;
		block = ft_store(a, block, bytes);
	}
	if (block == NULL)
		return (NULL);
	c = malloc(ft_strlen(block, 10) + 2);
	if (!c)
		return (NULL);
	c = ft_last_fill(block, c);
	block = ft_free(block);
	return (c);
}
