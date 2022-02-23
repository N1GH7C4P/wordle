/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wordle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linuxlite <linuxlite@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 10:50:39 by linuxlite         #+#    #+#             */
/*   Updated: 2022/02/23 17:54:18 by linuxlite        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wordle.h"

void	process_word(t_alphabet *abc, t_word **dictionary, char *guess, char *response, char* extra_characters)
{
	int i;
	
	i = 0;
	while (i < 5)
		abc->alphabet[response[i++] - 'a'] = '+';
	while (*extra_characters)
		abc->alphabet[*extra_characters++ - 'a'] = '?';
	i = 0;
	while (i < 26)
	{
		if (abc->alphabet[i] == '+' || abc->alphabet[i] == '?')
			dictionary = exclude_words_lacking_letter(dictionary, 'a' + i);
		i++;
	}
	i = 0;
	while (i < 5)
	{
		if (!abc->alphabet[guess[i] - 'a'] || abc->alphabet[guess[i] - 'a'] == '!')
		{
			dictionary = exclude_words_containing_letter(dictionary, guess[i]);
			abc->alphabet[guess[i] - 'a'] = '!';
		}
		i++;
	}
	dictionary = exclude_words(dictionary, response);
	print_alphabet(abc);
	ft_putendl(find_best_word(dictionary));
}

int main(int argc, char **argv)
{ 
    static t_word		**dictionary;
	static t_alphabet	*abc;
	char				*input;
	char				*output;
	char				*extras;

	input = ft_strnew(5);
	output = ft_strnew(5);
	extras = ft_strnew(5);
	if (argc != 2)
		ft_putstr("Wrong number of args.");
	dictionary = read_dictionary(argv);
	abc = t_alphabet_new(26);
	while (ft_strcmp(input, "quit"))
	{
		ft_putendl("GIVE GUESSED WORD");
		scanf("%s", input);
		ft_putendl("GIVE RESPONSE");
		scanf("%s", output);
		ft_putendl("GIVE EXTRA CHARACTERS");
		scanf("%s", extras);
		process_word(abc, dictionary, input, output, extras);
	}

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