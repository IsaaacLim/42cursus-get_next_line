#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int get_next_line();

int	main (int argc, char **argv)
{
	int	fd;
	int	ret;
	int	line_count;
	char	*line;

	line_count = 1;
	ret = 0;
	line = NULL;
	if(argc == 2)
	{
		fd = open("sample.txt", O_RDONLY);
		get_next_line(fd, &line);
	}
	else
		printf("Input != 2\n");
}