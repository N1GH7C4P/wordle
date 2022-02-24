/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alphabet.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linuxlite <linuxlite@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 15:43:21 by linuxlite         #+#    #+#             */
/*   Updated: 2022/02/24 20:45:27 by linuxlite        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wordle.h"

t_alphabet *t_alphabet_new(void)
{
	t_alphabet *new_alphabet = (t_alphabet *)malloc(sizeof(t_alphabet *));
	new_alphabet->alphabet = ft_strnew(26);
	return (new_alphabet);
}

void	print_alphabet(t_alphabet *abc)
{
	int i;

	ft_putendl("Alphabet: (letter guessed: !, letter unlocated: ?)");
	i = 0;
	while (i<26)
	{
		if (i>0)
			ft_putstr(", ");
		ft_putchar('a'+i);
		ft_putstr(": ");
		ft_putchar(abc->alphabet[i]);
		i++;
	}
	ft_putendl("");
}
