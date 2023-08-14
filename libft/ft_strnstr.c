/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaopereira <joaopereira@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 22:38:27 by joaopereira       #+#    #+#             */
/*   Updated: 2023/03/27 18:46:29 by joaopereira      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s, const char *search, size_t len)
{
	size_t	h;
	size_t	n;

	h = 0;
	if (search[0] == '\0')
		return ((char *)s);
	while (s[h] != '\0')
	{
		n = 0;
		while (s[h + n] == search[n] && (h + n) < len)
		{
			if (s[h + n] == '\0' && search[n] == '\0')
				return ((char *)&s[h]);
			n++;
		}
		if (search[n] == '\0')
			return ((char *)s + h);
		h++;
	}
	return (0);
}
