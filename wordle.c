/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wordle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linuxlite <linuxlite@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 10:50:39 by linuxlite         #+#    #+#             */
/*   Updated: 2022/02/24 16:09:50 by linuxlite        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wordle.h"

void	process_word(t_alphabet *abc, t_word **dictionary, char *guess, char *response, char* extra_characters)
{
	int i;
	
	i = 0;
	while (i < 5)
	{
		if (response[i] == '-')
			dictionary = exclude_words_containing_letter_in_postion_n(dictionary, guess[i], i);
		i++;
	}
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
		if (!abc->alphabet[guess[i] - 'a'] || abc->alphabet[guess[i] - 'a'] == '!' || abc->alphabet[guess[i] - 'a'] == '+')
		{
			dictionary = exclude_words_containing_letter(dictionary, guess[i], response);
			abc->alphabet[guess[i] - 'a'] = '!';
		}
		i++;
	}
	dictionary = exclude_words(dictionary, response);
	print_alphabet(abc);
	i = 0;
	while (i < 2315)
	{
		dictionary[i]->score = score_word(dictionary[i]->word, response, extra_characters);
		i++;
	}
	ft_putendl("all valid wods: ");
	print_valid_words(dictionary);
	ft_putendl("best word(s): ");
	print_words_with_score_n(dictionary, find_biggest_score(dictionary));
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
	while (ft_strcmp(input, "pquit"))
	{
		ft_putendl("Give the word you guessed (lower case)");
		scanf("%s", input);
		if (ft_strlen(input) != 5)
		{
			ft_putendl("invalid input!");
			continue ;
		}
		ft_putendl("Give the response you received. (example: '-a--e')");
		scanf("%s", output);
		if (ft_strlen(output) != 5)
		{
			ft_putendl("invalid input!");
			continue ;
		}
		if(!ft_strcmp(input, output))
		{
			ft_putendl("You found the right word! Congratulazions!");
			return(1);
		}
		ft_putendl("Give the unlocated characters found or '.' if there are none.");
		scanf("%s", extras);
		process_word(abc, dictionary, input, output, extras);
	}

	return (0);
}

t_word **read_dictionary(char **argv)
{
	int     fd;
    int     ret;
    int     i;
    char    *line;
	char	*template;
	t_word	**dictionary;

	template = ft_strdup("-----");
	dictionary = (t_word **)malloc(sizeof(t_word *) * 2315);
    fd = open(argv[1], O_RDONLY);
    ret = ft_get_next_line(fd, &line);
    i = 0;
    while(ret >= -2)
    {
		if (line)
			dictionary[i] = t_word_new(line, score_word(line, template, ""));
		i++;
        ret = ft_get_next_line(fd, &line);
        if(ret < 1)
            break;
    }
    ft_strdel(&line);
    close(fd);
	return (dictionary);
}
