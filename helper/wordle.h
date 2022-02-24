/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wordle.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linuxlite <linuxlite@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 10:49:33 by linuxlite         #+#    #+#             */
/*   Updated: 2022/02/24 23:37:33 by linuxlite        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORDLE_H
# define WORDLE_H

# include "../libft/libft.h"
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

void		exclude_words_containing_letter_in_postion_n(t_word **dictionary, char c, int n);
int			score_word(char *word, char *template, char *extras);
t_word		*t_word_new(char *str, int score);
t_word		**read_dictionary(char *data);
void		print_dictionary(t_word **dictionary);
char		*find_best_word(t_word **dictionary);
void		exclude_words(t_word **dictionary, char *template);
void		exclude_words_lacking_letter(t_word **dictionary, char c);
void		exclude_words_containing_letter(t_word **dictionary, char c, char *template);
void		process_word(t_alphabet *abc, t_word **dictionary, char *guess, char *response, char* extra_characters);
t_alphabet	*t_alphabet_new(void);
void		print_alphabet(t_alphabet *abc);
void		print_valid_words(t_word **dictionary);
void		print_words_with_score_n(t_word **dictionary, int n);
int			find_biggest_score(t_word **dictionary);
void		print_words_with_score_n(t_word **dictionary, int n);
int			count_valid_words(t_word **dictionary);
int			validate_inputs(char *input, char *output, char *extras);

#endif