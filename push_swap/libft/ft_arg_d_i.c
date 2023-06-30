/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_d_i.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecullier <ecullier@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 20:51:19 by ecullier          #+#    #+#             */
/*   Updated: 2023/03/01 11:26:35 by ecullier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* affiche un entier signe en base 10 (donc)
je gere donc la base 10 avec un putnbr
et ensuite ma fonction ft_arg  me retourne les entiers trouve
*/

static	void	ft_putnbr(int nbr)
{
	int	sum;

	sum = 0;
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr *= -1;
		if (nbr == -2147483648)
		{
			nbr--;
			sum = 1;
		}
	}
	if (nbr < 10)
		ft_putchar_fd(nbr + 48 + sum, 1);
	else
	{
		ft_putnbr(nbr / 10);
		ft_putnbr(nbr % 10 + sum);
	}
}

int	ft_arg_d_i(int c)
{
	ft_putnbr(c);
	return (ft_dec_len(c));
}
