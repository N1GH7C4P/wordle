/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wordle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linuxlite <linuxlite@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 10:50:39 by linuxlite         #+#    #+#             */
/*   Updated: 2022/02/24 23:42:32 by linuxlite        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wordle.h"

void	process_word(t_alphabet *abc, t_word **dictionary, char *guess, char *response, char *extra_characters)
{
	int i;
	
	i = 0;
	while (i < 5)
	{
		if (response[i] == '-')
			exclude_words_containing_letter_in_postion_n(dictionary, guess[i], i);
		else
			abc->alphabet[response[i] - 'a'] = '+';
		i++;
	}
	while (*extra_characters && *extra_characters != '.')
	{
		abc->alphabet[*extra_characters - 'a'] = '?';
		extra_characters++;
	}
	i = 0;
	while (i < 26)
	{
		if (abc->alphabet[i] == '+' || abc->alphabet[i] == '?')
			exclude_words_lacking_letter(dictionary, 'a' + i);
		i++;
	}
	i = 0;
	while (i < 5)
	{
		if (!abc->alphabet[guess[i] - 'a'] || abc->alphabet[guess[i] - 'a'] == '!' || abc->alphabet[guess[i] - 'a'] == '+')
		{
			exclude_words_containing_letter(dictionary, guess[i], response);
			abc->alphabet[guess[i] - 'a'] = '!';
		}
		i++;
	}
	exclude_words(dictionary, response);
	print_alphabet(abc);
	i = 0;
	while (i < 2315)
	{
		dictionary[i]->score = score_word(dictionary[i]->word, response, extra_characters);
		i++;
	}
	if(!count_valid_words(dictionary))
	{
		ft_putendl("No valid words with given input!");
		i = 0;
		while (i < 2315)
		{
			free(dictionary[i]->word);
			i++;
		}
		free(dictionary);
		free(guess);
		free(response);
		free(extra_characters);
		exit(1);
	}
	else
	{
		ft_putendl("All valid wods: ");
		print_valid_words(dictionary);
		ft_putendl("Best word(s): ");
		print_words_with_score_n(dictionary, find_biggest_score(dictionary));
	}
}

int main(void)
{ 
    t_word				**dictionary;
	t_alphabet			*abc;
	char				*input;
	char				*output;
	char				*extras;
	int					i;

	input = ft_strnew(5);
	output = ft_strnew(5);
	extras = ft_strnew(5);
	dictionary = read_dictionary("dictionary");
	abc = t_alphabet_new();
	while (ft_strcmp(input, "pquit"))
	{
		ft_putendl("Give the word you guessed (lower case)");
		scanf("%s", input);
		ft_putendl("Give the response you received. (example: '-a--e')");
		scanf("%s", output);
		ft_putendl("Give the unlocated characters found or '.' if there are none.");
		scanf("%s", extras);
		if (!validate_inputs(input, output, extras))
		{
			ft_putendl("One of the inputs was invalid!");
			continue ;
		}
		if (!ft_strcmp(input, output))
		{
			ft_putendl("You found the right word! Congratulazions!");
			i = 0;
			while (i < 2315)
			{
				free(dictionary[i]->word);
				i++;
			}
			free(dictionary);
			free(input);
			free(output);
			free(extras);
			exit(1);
		}
		process_word(abc, dictionary, input, output, extras);
	}
	return (0);
}

int		validate_inputs(char *input, char *output, char *extras)
{
	int i;

	if (ft_strlen(input) != 5 || ft_strlen(output) != 5)
		return (0);
	i = 0;
	while (i < 5)
	{
		if (input[i] > 'z' || input[i] < 'a')
			return (0);
		if ((output[i] > 'z' || output[i] < 'a') && output[i] != '-')
			return (0);
		if (extras[i] && i > 0)
			if (extras[i] > 'z' || extras[i] < 'a')
				return (0);
		i++;
	}
	return (1);
}

t_word **read_dictionary(char *data)
{
	int     fd;
    int     ret;
    int     i;
    char    *line;
	char	*template;
	t_word	**dictionary;

	line = malloc(6);
	template = ft_strdup("-----");
	dictionary = (t_word **)malloc(sizeof(t_word *) * 2315 + 1);
    fd = open(data, O_RDONLY);
    ret = ft_get_next_line(fd, &line);
    i = 0;
    while(ret >= -2)
    {
		if (line)
			dictionary[i] = t_word_new(line, score_word(line, template, ""));
		i++;
        ret = ft_get_next_line(fd, &line);
        if (ret < 1)
            break;
    }
	free(line);
    close(fd);
	free(template);
	return (dictionary);
}
