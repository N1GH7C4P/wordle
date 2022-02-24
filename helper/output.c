/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linuxlite <linuxlite@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 13:54:41 by linuxlite         #+#    #+#             */
/*   Updated: 2022/02/24 15:24:22 by linuxlite        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wordle.h"

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

void print_valid_words(t_word **dictionary)
{
	int i;

	i = 0;
	while (i++ < 2314)
	{
		if (!dictionary[i]->excluded)
		{
			//"\e[0;31m"
			ft_putstr("\e[0;3");
			ft_putnbr(dictionary[i]->score/14);
			ft_putstr("m");
			ft_putstr(dictionary[i]->word);
			ft_putchar(' ');
			ft_putnbr(dictionary[i]->score);
			ft_putendl("\e[0;37m");
		}
	}
}
