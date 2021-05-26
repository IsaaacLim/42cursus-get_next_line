#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
void *ft_calloc();
void ft_strdel();
char	*ft_strjoin();
char	*ft_strchr();
char	*ft_substr();
char	*ft_strdup();
int BUFF_SIZE = 32;

static int	ft_str_op(int fd, char **line, char **arr)
{
	int		i;
	char	*temp;

	i = 0;
	while (arr[fd][i] != '\n' && arr[fd][i] != '\0') //look for '\n' or '\0'
		i++;
	if (arr[fd][i] == '\n')
	{
		*line = ft_substr(arr[fd], 0, i); //copy text until '\n' - 1 to arr given from main
		temp = ft_strdup(arr[fd] + i + 1); //store remaining text (skip '\n') to temp
		ft_strdel(&arr[fd]); //free *arr to be replaced
		arr[fd] = temp; //replace arr with the remaining text (no '\n')
	}
	else //else it's just the last line
	{
		*line = ft_strdup(arr[fd]);
		ft_strdel(&arr[fd]);
	}
	return (1); //read with no error
}

int	get_next_line(int fd, char **line)
{
	int			i;
	char 		buf[BUFF_SIZE + 1];
	static char *arr[10000]; //supposedly stores the remaining str from the prev func call
	char		*temp;

	while ((i = read(fd, buf, BUFF_SIZE)) > 0) //fd = 3 all the way; copy text to buf (buf continues from where it left off)
	{
		buf[i] = '\0'; //i = # of bytes read. Fill end of arr with NULL
		if (!arr[fd]) //if first arr
			arr[fd] = (char *)ft_calloc(1, 1); //initiate it
		temp = ft_strjoin(arr[fd], buf); //append arr[] (existing) with buf (latest)
		ft_strdel(&arr[fd]); //free *arr (not sure why, to be replaced?)
		arr[fd] = temp; //stores appended string to arr[]
		if (ft_strchr(buf, '\n')) //breaks loop from first '\n' encountered
			break;
	}
	if (i < 0) //if fail to read
		return (-1);
	else if (!i && !arr[fd]) //EOF has reached
		return (0);
	return (ft_str_op(fd, line, arr)); // returns 1
}

