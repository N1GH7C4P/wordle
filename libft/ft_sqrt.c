/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolojar <kpolojar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 17:13:57 by kpolojar          #+#    #+#             */
/*   Updated: 2022/01/20 17:14:17 by kpolojar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	i;

	i = 1;
	if (nb == 0 || nb == 1)
	{
		return (nb);
	}
	while (i * i < nb)
	{
		i++;
	}
	if (i * i >= nb)
	{
		return (i);
	}
	else
	{
		return (0);
	}
}
