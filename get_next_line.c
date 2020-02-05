#include    "get_next_line.h"

int		last_line(char **str, char *buff, char **line)
{
	*line = ft_strdup(*str);
	free(*str);
	*str = NULL;
	free(buff);
	return (0);
}

int		one_line(char **str, char **line, char *buff, char *tmp)
{
	int len;

	len = 0;
	tmp = *str;
	while ((*str)[len] != '\n') 
		len++;
	*line = ft_substr(*str, 0, len);
	*str = ft_strdup(*str + len + 1);
	free(tmp);
	free(buff);
	return (1);
}

int		my_free(char *buff)
{
	free(buff);
	return (-1);
}

int		get_next_line(int fd, char **line)
{
	char		*buff;
	static char	*str;
	char		*tmp;
	int			r;

	if (fd < 0 || line == NULL || (read(fd, NULL, 0) < 0))
		return (-1);
	buff = (char*)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!str)
		str = ft_strdup("");
	while (!ft_strchr(str, '\n'))
	{
		tmp = str;
		if ((r = read(fd, buff, BUFFER_SIZE)) < 0)
			return (my_free(buff));
		buff[r] = '\0';
		str = ft_strjoin(str, buff);
		free(tmp);
		if (r == 0)
			return (last_line(&str, buff, line));
	}
	if (ft_strchr(str, '\n'))
		return (one_line(&str, line, buff, tmp));
	else
		return (last_line(&str, buff, line));
}