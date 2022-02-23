/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wordle.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linuxlite <linuxlite@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 10:49:33 by linuxlite         #+#    #+#             */
/*   Updated: 2022/02/23 13:55:45 by linuxlite        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORDLE_H
# define WORDLE_H

# include "libft/libft.h"
# include <unistd.h>
# include <fcntl.h>

typedef struct t_word
{
	char	*word;
	int		score;
	int		excluded;

}	t_word;

int		score_word(char *word);
t_word	*t_word_new(char *str, int score);
t_word	**read_dictionary(char **argv);
void	 print_dictionary(t_word **dictionary);
char	*find_best_word(t_word **dictionary);
t_word	**exclude_words(t_word **dictionary, char *template);

#endif