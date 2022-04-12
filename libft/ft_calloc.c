/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pngamcha <pngamcha@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 21:28:53 by pngamcha          #+#    #+#             */
/*   Updated: 2022/04/12 20:42:16 by pngamcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*s;

	if (count * size < count || count * size < size)
		return (0);
	s = malloc(count * size);
	if (!s)
		return (0);
	else
		ft_bzero(s, count * size);
	return (s);
}
