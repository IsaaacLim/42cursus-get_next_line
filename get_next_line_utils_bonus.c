#include "get_next_line_bonus.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*mal;
	char	*str;

	mal = (void *)malloc(count * size);
	if (!mal)
		return (NULL);
	str = (char *)mal;
	while (count-- > 0)
		*str++ = 0;
	return (mal);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	char	*str;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen (s2);
	str = (char *)malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	i = -1;
	while (s1[++i])
		str[i] = s1[i];
	j = -1;
	while (s2[++j])
		str[i++] = s2[j];
	str[i] = '\0';
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0' && *s != (char)c)
		s++;
	if (*s == (char)c)
		return ((char *)s);
	else
		return (NULL);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	size_t			strlen;
	unsigned int	i;

	if (!s)
		return (NULL);
	strlen = ft_strlen(s);
	if (start >= strlen)
		len = 0;
	else if (len > strlen - start)
		len = strlen - start;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i = -1;
	while (s[start + ++i] && i < len)
		str[i] = s[start + i];
	str[i] = '\0';
	return (str);
}
