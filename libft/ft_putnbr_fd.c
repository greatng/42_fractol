/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pngamcha <pngamcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 22:49:13 by pngamcha          #+#    #+#             */
/*   Updated: 2022/02/18 23:24:20 by pngamcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int	nbr;
	char		c;
	int			div;

	div = 1000000000;
	nbr = n;
	if (nbr < 0)
	{
		nbr = nbr * (-1);
		write(fd, "-", 1);
	}
	while (!(nbr / div) && div != 1)
		div = div / 10;
	while (div)
	{
		c = (nbr / div) + 48;
		write(fd, &c, 1);
		nbr = nbr % div;
		div = div / 10;
	}
}
