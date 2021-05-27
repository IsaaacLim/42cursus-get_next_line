#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	static char	*arr;
	char	*buf;
	char	*temp;
	int		ret;

	if (!arr)
		arr = NULL;
	while (ret = read(fd, buf, BUFFER_SIZE) > 0)
	{
		arr = ft_strjoin(arr, buf);
		if (ft_strchr(buf, '\n'))
			break;
	}
	printf("arr: %s", arr);
	return (1);

}