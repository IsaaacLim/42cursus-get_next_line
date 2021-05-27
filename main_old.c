#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int get_next_line();

int	main (int argc, char **argv)
{
	int	fd;
	int	ret;
	int	line_count;
	char	*line;

	line_count = 1;
	ret = 0;
	line = NULL; //initiate array
	if(argc == 2)
	{
		fd = open("sample.txt", O_RDONLY); //fd = 3
		while ((ret = get_next_line(fd, &line)) > 0)
		{
			printf("%d: %d, %s\n", line_count++, ret, line);
			free (line);
		}
		if (ret == 0)
		{
			printf("EOF has reached\n");
			//free(line);
		}
		else if (ret == -1)
			printf("ret -1: Error\n");
	}
	else
		printf("Input != 2\n");
	close(fd);
}