/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linuxlite <linuxlite@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 12:16:56 by linuxlite         #+#    #+#             */
/*   Updated: 2022/02/23 17:52:29 by linuxlite        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wordle.h"

int	score_word(char *word)
{
	int i;
	int score;
	char *prevs;

	prevs = ft_strnew(5);
	score = 0;
	i = 0;
	while(i++ < 5)
	{
		if (word[i] == prevs[0] || word[i] == prevs[1] || word[i] == prevs[2] || word[i] == prevs[3])
			continue ;
		else if (word[i] == 'e')
			score += 26;
		else if (word[i] == 's')
			score += 25;
		else if (word[i] == 'i')
			score += 24;
		else if (word[i] == 'a')
			score += 23;
		else if (word[i] == 'r')
			score += 22;
		else if (word[i] == 'n')
			score += 21;
		else if (word[i] == 't')
			score += 20;
		else if (word[i] == 'o')
			score += 19;
		else if (word[i] == 'l')
			score += 18;
		else if (word[i] == 'c')
			score += 17;
		else if (word[i] == 'd')
			score += 16;
		else if (word[i] == 'u')
			score += 15;
		else if (word[i] == 'g')
			score += 14;
		else if (word[i] == 'p')
			score += 13;
		else if (word[i] == 'm')
			score += 12;
		else if (word[i] == 'k')
			score += 11;
		else if (word[i] == 'h')
			score += 10;
		else if (word[i] == 'b')
			score += 9;
		else if (word[i] == 'y')
			score += 8;
		else if (word[i] == 'f')
			score += 7;
		else if (word[i] == 'v')
			score += 6;
		else if (word[i] == 'w')
			score += 5;
		else if (word[i] == 'z')
			score += 4;
		else if (word[i] == 'x')
			score += 3;
		else if (word[i] == 'q')
			score += 2;
		else if (word[i] == 'j')
			score += 1;
		prevs[i] = word[i];
	}
	return (score);
}

t_word *t_word_new(char *str, int score)
{
	t_word *new_word;

	new_word = (t_word *)malloc(sizeof(t_word *));
	new_word->word = ft_strdup(str);
	new_word->score = score;

	return (new_word);
}

char *find_best_word(t_word **dictionary)
{
	int		high_score;
	int		i;
	char	*best_word;

	high_score = 0;
	i = 0;
	while (i++ < 2314)
	{
		if (dictionary[i]->score > high_score && !dictionary[i]->excluded)
		{
			high_score = dictionary[i]->score;
			best_word = ft_strdup(dictionary[i]->word);
		}
	}
	return (best_word);
}

t_word	**exclude_words_containing_letter(t_word **dictionary, char c)
{
	int i, j;

	i = 0;
	while (i < 2315)
	{
		j = 0;
		while (j < 5)
		{
			if (dictionary[i]->word[j] == c)
			{
				dictionary[i]->excluded = 1;
				break ;
			}
			j++;
		}
		i++;
	}
	return (dictionary);
}

t_word	**exclude_words_lacking_letter(t_word **dictionary, char c)
{
	int i, j;

	i = 0;
	while (i < 2315)
	{
		j = 0;
		while (j < 5)
		{
			if (dictionary[i]->word[j] == c)
				break ;
			else if(j == 4)
			{
				dictionary[i]->excluded = 1;
			}
			j++;
		}
		i++;
	}
	return (dictionary);
}

t_word	**exclude_words(t_word **dictionary, char *template)
{
	int i, j;

	i = 0;
	while (i < 2315)
	{
		j = 0;
		while (j < 5)
		{
			if (!(dictionary[i]->word[j] == template[j] || template[j] == '-'))
			{
				dictionary[i]->excluded = 1;
				break ;
			}
			j++;
		}
		i++;
	}
	return (dictionary);
}