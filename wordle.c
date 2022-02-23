/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wordle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linuxlite <linuxlite@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 10:50:39 by linuxlite         #+#    #+#             */
/*   Updated: 2022/02/23 11:48:26 by linuxlite        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wordle.h"

int main(int argc, char **argv)
{ 
    char	**dictionary;

	if (argc != 2)
		ft_putstr("Wrong number of args.");
	dictionary = read_dictionary(argc, argv);
	return (0);
}

char **read_dictionary(int argc, char **argv)
{
	int     fd;
    int     ret;
    int     i;
    char    *line;
	char	**dictionary;

	dictionary = (char **)malloc(sizeof(char *) * 2315);
    fd = open(argv[1], O_RDONLY);
    ret = ft_get_next_line(fd, &line);
    i = 0;
    while(ret >= -2)
    {
        ft_strdel(&line);
		if (line)
		{
			ft_putendl(line);
			dictionary[i] = ft_strdup(line);
		}
        i++;
        ret = ft_get_next_line(fd, &line);
        if(ret < 1)
            break;
    }
    ft_strdel(&line);
    close(fd);
	return (dictionary);
}