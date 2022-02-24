/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scoring.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linuxlite <linuxlite@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 13:52:44 by linuxlite         #+#    #+#             */
/*   Updated: 2022/02/24 15:45:03 by linuxlite        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wordle.h"

void print_words_with_score_n(t_word **dictionary, int n)
{
	int		i;

	i = 0;
	while (i++ < 2314)
	{
		if (dictionary[i]->score == n && !dictionary[i]->excluded)
			ft_putendl(dictionary[i]->word);
	}
}

int find_biggest_score(t_word **dictionary)
{
	int		high_score;
	int		i;

	high_score = 0;
	i = 0;
	while (i++ < 2314)
	{
		if (dictionary[i]->score > high_score && !dictionary[i]->excluded)
			high_score = dictionary[i]->score;
	}
	return (high_score);
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

int	score_word(char *word, char* template, char* extras)
{
	int i, j;
	int score;
	char *prevs;
	int extra_in_word;

	prevs = ft_strnew(5);
	score = 0;
	i = 0;
	while(i++ < 5)
	{
		extra_in_word = 0;
		if (template[i] != '-')
			continue ;
		if (word[i] == prevs[0] || word[i] == prevs[1] || word[i] == prevs[2] || word[i] == prevs[3])
		{
			j = 0;
			while(extras[j])
				if (extras[j++] == word[i])
					extra_in_word = 1;
			if(!extra_in_word)
				continue ;
		}
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
