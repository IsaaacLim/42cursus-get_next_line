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
		get_next_line(fd, &line);
		printf("1: %s\n", line);
		free (line);
		get_next_line(fd, &line);
		printf("2: %s\n", line);
		free (line);
	}
	else
		printf("Input != 2\n");
}