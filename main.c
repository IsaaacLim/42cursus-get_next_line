#include <sys/stat.h>
#include <fcntl.h>
#include "get_next_line.h"

int	main(int argc, char **argv)
{
	int		fd;
	char	*line;
	int		ret;
	int		count;

	count = 1;
	ret = 0;
	line = NULL;
	if (argc == 2)
	{
		fd = open("sample.txt", O_RDONLY);
		while ((ret = get_next_line(fd, &line)) > 0)
		{
			printf("%s\n", line);
			free(line);
		}
		if (ret == 0)
			printf("EOF has reached\n");
		else if (ret == -1)
			printf("ret -1: Error\n");
	}
	else
		printf("Input argument\n");
	close(fd);
}