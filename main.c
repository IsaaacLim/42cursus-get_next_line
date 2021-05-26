#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>


int	main (int argc, char **argv)
{
	int	fd;
	int	ret;
	int	line_count;

	line_count = 1;
	ret = 0;
	line = NULL;
	if(argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		printf("");
	}
	else
		return (0); 
}