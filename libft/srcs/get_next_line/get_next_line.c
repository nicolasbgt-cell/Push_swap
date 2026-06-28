/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annlecre <annlecre@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 07:23:18 by annlecre          #+#    #+#             */
/*   Updated: 2026/05/14 11:41:46 by annlecre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

char	*ft_join_free(char *static_buf, char *tmp_buf)
{
	char	*temp;

	temp = ft_strjoin(static_buf, tmp_buf);
	free(static_buf);
	return (temp);
}

char	*ft_read_file(int fd, char *static_buf)
{
	char	*tmp_buf;
	int		bytes_read;

	if (!static_buf)
		static_buf = ft_calloc(1, 1);
	tmp_buf = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, tmp_buf, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(tmp_buf);
			return (NULL);
		}
		tmp_buf[bytes_read] = 0;
		static_buf = ft_join_free(static_buf, tmp_buf);
		if (ft_strchr(tmp_buf, '\n'))
			break ;
	}
	free(tmp_buf);
	return (static_buf);
}

char	*ft_get_line(char *static_buf)
{
	char	*line;
	int		i;

	i = 0;
	if (!static_buf[i])
		return (NULL);
	while (static_buf[i] && static_buf[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	i = 0;
	while (static_buf[i] && static_buf[i] != '\n')
	{
		line[i] = static_buf[i];
		i++;
	}
	if (static_buf[i] && static_buf[i] == '\n')
		line[i++] = '\n';
	return (line);
}

char	*ft_leftover(char *static_buf)
{
	int		i;
	int		j;
	char	*new_line;

	i = 0;
	j = 0;
	while (static_buf[i] && static_buf[i] != '\n')
		i++;
	if (!static_buf[i])
	{
		free(static_buf);
		return (NULL);
	}
	new_line = ft_calloc(ft_strlen(static_buf) - i + 1, sizeof(char));
	i += 1;
	while (static_buf[i])
		new_line[j++] = static_buf[i++];
	free(static_buf);
	return (new_line);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer = ft_read_file(fd, buffer);
	if (!buffer)
		return (NULL);
	line = ft_get_line(buffer);
	buffer = ft_leftover(buffer);
	return (line);
}
/*
int	main(void)
{
	int fd = open("test.txt", O_RDONLY);
	char *line;

	while ((line = get_next_line(fd)))
	{
		printf("%s", line);
		free(line);
	}
	return (0);

}*/
