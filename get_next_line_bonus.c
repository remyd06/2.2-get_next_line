/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdedola <rdedola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 11:43:11 by rdedola           #+#    #+#             */
/*   Updated: 2024/05/20 10:48:11 by rdedola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*free_box(char *buffer, char *stash)
{
	if (stash)
		free(stash);
	if (buffer)
		free(buffer);
	return (NULL);
}

char	*get_line(char *stash)
{
	int		i;
	char	*line;

	i = 0;
	if (stash[0] == '\0')
		return (NULL);
	while (stash[i] != '\n' && stash[i] != '\0')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (stash[i] != '\n' && stash[i] != '\0')
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
	{
		line[i] = stash[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*get_backup(char *stash)
{
	int		i;
	int		j;
	char	*temp_stash;

	i = 0;
	if (!stash)
		return (NULL);
	while (stash[i] != '\n' && stash[i] != '\0')
		i++;
	if (stash[i] == '\0')
	{
		free(stash);
		return (NULL);
	}
	i++;
	temp_stash = (char *)malloc(sizeof(char) * (strlen(stash) - i + 1));
	if (!temp_stash)
		return (NULL);
	j = 0;
	while (stash[i])
		temp_stash[j++] = stash[i++];
	temp_stash[j] = '\0';
	free(stash);
	return (temp_stash);
}

char	*read_file(int fd, char *stash)
{
	char	*buffer;
	int		bytes_read;

	bytes_read = 1;
	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (!(strchr(stash, '\n')) && bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free_box(buffer, stash));
		buffer[bytes_read] = '\0';
		stash = ft_strjoin(stash, buffer);
		if (stash == NULL)
			return (free_box(buffer, NULL));
	}
	free(buffer);
	if (bytes_read == 0 && stash[0] == '\0')
		return (free_box(NULL, stash));
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash[4096];
	char		*line;

	if (BUFFER_SIZE > 2147483647 || fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	if (!stash[fd])
		stash[fd] = ft_strdup("");
	stash[fd] = read_file(fd, stash[fd]);
	if (!stash[fd])
		return (NULL);
	line = get_line(stash[fd]);
	stash[fd] = get_backup(stash[fd]);
	return (line);
}

// int	main(void)
//{
//	char *line;
//	int fd;

//	fd = open("./montexte.txt", O_RDONLY);
//	if (fd == -1)
//	{
//		perror("Erreur lors de l'ouverture du fichier");
//		return (1);
//	}

//	printf("Contenu du fichier :\n");

//	line = get_next_line(fd);
//	while (line != NULL)
//	{
//		printf("-------\n");
//		printf("%s", line);
//		free(line);
//		line = get_next_line(fd);
//	}

//	close(fd);
//	return (0);
//}