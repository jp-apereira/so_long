/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaopereira <joaopereira@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 18:52:07 by joaopereira       #+#    #+#             */
/*   Updated: 2023/03/27 18:52:07 by joaopereira      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n, size_t size)
{
	size_t	i;
	void	*dest;

	dest = malloc(n * size);
	i = n * size;
	if (dest == NULL)
	{
		return (dest);
	}
	ft_memset(dest, 0, i);
	return (dest);
}
