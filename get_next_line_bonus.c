#include "get_next_line_bonus.h"

int	line_sep(char **arr, char **line, int ret)
{
	char	*temp;
	int		i;

	i = 0;
	while ((*arr)[i] != '\n' && (*arr)[i] != '\0')
		i++;
	if ((*arr)[i] == '\n')
	{
		*line = ft_substr(*arr, 0, i);
		temp = ft_substr(*arr, i + 1, ft_strlen((*arr) + i + 1));
		free(*arr);
		*arr = temp;
	}
	else if ((*arr)[i] == '\0')
	{
		*line = ft_substr(*arr, 0, ft_strlen((*arr) + 1));
		while (i-- > 0)
			*arr++ = '\0';
		free(*arr);
		*arr = NULL;
	}
	return (1);
}
int get_next_line(int fd, char **line)
{
	static char	*arr[1000];
	char		*temp;
	char		buf[BUFFER_SIZE + 1];
	int			ret;

	if(fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	ret = read(fd, buf, BUFFER_SIZE);
	while (ret > 0)
	{
		buf[ret] = '\0';
		if (!arr[fd])
			arr[fd] = (char *)ft_calloc(1, 1);
		temp = ft_strjoin(arr[fd], buf);
		free(arr[fd]);
		arr[fd] = temp;
		if (ft_strchr(arr[fd], '\n'))
			break;
		ret = read(fd, buf, BUFFER_SIZE);
	}
	if (ret < 0)
		return (-1);
	else if (!ret && !arr[fd])
		return (0);
	return (line_sep(&arr[fd], line, ret));
}