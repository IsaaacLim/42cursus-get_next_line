#include "get_next_line.h"

void	line_sep(char **line, char **arr)
{	
	char	*temp;
	int 	i;
	char	*str;

	str = *arr;
	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (str[i] == '\n')
	{
		*line = ft_substr(*arr, 0, i);
		temp = ft_strdup(*arr + i + 1);
		free(*arr);
		*arr = temp;
	}
	else if (str[i] == '\0')
	{
		*line = ft_strdup(*arr);
		ft_bzero(*arr, ft_strlen(*arr));
		free(*arr);
		*arr = NULL;
	}
}

int	get_next_line(int fd, char **line)
{
	static char	*arr;
	char		buf[BUFFER_SIZE + 1];
	char		*temp;
	int			ret;

	while ((ret = read(fd, buf, BUFFER_SIZE)) > 0 )
	{
		buf[ret] = '\0';
		if (!arr)
			arr = (char *)ft_calloc(1,1);
		temp = ft_strjoin(arr, buf);
		free(arr);
		arr = temp;
		if (ft_strchr(buf, '\n'))
			break;
	}
	if (!arr)
		return (0);
	else if (ret < 0)
		return (-1);
	line_sep(line, &arr);
	return (1);
}