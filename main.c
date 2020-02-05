#include    "get_next_line.h"

int main()
{
	char	*buffer;
	int		r;
	int		fd;

	fd = open("yoo.txt", O_RDONLY);
	while ((r = get_next_line(fd, &buffer) > 0))
	{
		printf("%d || %s\n", r, buffer);
		free(buffer);
	}
	printf("%d || %s\n", r, buffer);
	free(buffer);
}