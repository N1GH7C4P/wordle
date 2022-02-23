/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wordle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linuxlite <linuxlite@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 10:50:39 by linuxlite         #+#    #+#             */
/*   Updated: 2022/02/23 14:11:16 by linuxlite        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wordle.h"

int main(int argc, char **argv)
{ 
    t_word	**dictionary;

	if (argc != 2)
		ft_putstr("Wrong number of args.");
	dictionary = read_dictionary(argv);
	print_dictionary(dictionary);
	ft_putstr("\nbest word: ");
	ft_putstr(find_best_word(dictionary));
	dictionary = exclude_words(dictionary, "-ee--");
	ft_putstr("\nnew best word: ");
	ft_putstr(find_best_word(dictionary));

	return (0);
}

void print_dictionary(t_word **dictionary)
{
	int i;

	i = 0;
	while (i++ < 2314)
	{
		ft_putstr(dictionary[i]->word);
		ft_putchar(' ');
		ft_putnbr(dictionary[i]->score);
		ft_putendl("");
	}
}

t_word **read_dictionary(char **argv)
{
	int     fd;
    int     ret;
    int     i;
    char    *line;
	t_word	**dictionary;

	dictionary = (t_word **)malloc(sizeof(t_word *) * 2315);
    fd = open(argv[1], O_RDONLY);
    ret = ft_get_next_line(fd, &line);
    i = 0;
    while(ret >= -2)
    {
		if (line)
			dictionary[i] = t_word_new(line, score_word(line));
		i++;
        ret = ft_get_next_line(fd, &line);
        if(ret < 1)
            break;
    }
    ft_strdel(&line);
    close(fd);
	return (dictionary);
}