/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wordle.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linuxlite <linuxlite@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 10:49:33 by linuxlite         #+#    #+#             */
/*   Updated: 2022/02/23 17:39:39 by linuxlite        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORDLE_H
# define WORDLE_H

# include "libft/libft.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct t_word
{
	char	*word;
	int		score;
	int		excluded;
}	t_word;

typedef struct t_alphabet
{
	char *alphabet;
}	t_alphabet;

int			score_word(char *word);
t_word		*t_word_new(char *str, int score);
t_word		**read_dictionary(char **argv);
void		print_dictionary(t_word **dictionary);
char		*find_best_word(t_word **dictionary);
t_word		**exclude_words(t_word **dictionary, char *template);
t_word		**exclude_words_lacking_letter(t_word **dictionary, char c);
t_word		**exclude_words_containing_letter(t_word **dictionary, char c);
void		process_word(t_alphabet *abc, t_word **dictionary, char *guess, char *response, char* extra_characters);
t_alphabet	*t_alphabet_new(int size);
void		print_alphabet(t_alphabet *abc);

#endif