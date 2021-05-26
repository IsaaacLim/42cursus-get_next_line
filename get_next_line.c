#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
void *ft_calloc();
void ft_strdel();
char	*ft_strjoin();
char	*ft_strchr();
int BUFF_SIZE = 32;

static int	ft_str_op(int fd, char **line, char **arr)
{

}

int	get_next_line(int fd, char **line)
{
	int			i;
	char 		buf[BUFF_SIZE + 1];
	static char *arr[10000];
	char		*temp;

	while ((i = read(fd, buf, BUFF_SIZE)) > 0) //fd = 3 all the way; copy text to buf
	{
		buf[i] = '\0'; //i = # of bytes read. Fill end of arr with NULL
		if (!arr[fd]) //if first arr
			arr[fd] = (char *)ft_calloc(1, 1); //initiate it
		temp = ft_strjoin(arr[fd], buf); //append arr[] (existing) with buf (latest)
		ft_strdel(&arr[fd]); //free *arr (not sure why)
		arr[fd] = temp; //stores appended string to arr[]
		if (ft_strchr(buf, '\n')) //breaks loop from first '\n' encountered
			break;
	}
	ft_str_op(fd, line, arr);
	return (1);
}

