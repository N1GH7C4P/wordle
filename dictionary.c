/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dictionary.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linuxlite <linuxlite@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 12:16:56 by linuxlite         #+#    #+#             */
/*   Updated: 2022/02/24 15:16:16 by linuxlite        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wordle.h"

t_word *t_word_new(char *str, int score)
{
	t_word *new_word;

	new_word = (t_word *)malloc(sizeof(t_word *));
	new_word->word = ft_strdup(str);
	new_word->score = score;

	return (new_word);
}

t_word	**exclude_words_containing_letter_in_postion_n(t_word **dictionary, char c, int n)
{
	int i;

	i = 0;
	while (i < 2315)
	{
		if (dictionary[i]->word[n] == c)
			dictionary[i]->excluded = 1;
		i++;
	}
	return (dictionary);
}

t_word	**exclude_words_containing_letter(t_word **dictionary, char c, char* template)
{
	int i, j;

	i = 0;
	while (i < 2315)
	{
		j = 0;
		while (j < 5)
		{
			if (dictionary[i]->word[j] == c && template[j] == '-')
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