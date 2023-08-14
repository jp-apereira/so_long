/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: joaopereira <joaopereira@student.42.fr>    +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2023/03/27 18:45:34 by joaopereira       #+#    #+#             */
/*   Updated: 2023/03/27 18:45:34 by joaopereira      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** LIBRARY: N/A 
** extract substring from string
** DESCRIPTION:
** 		Allocates (with malloc(3)) and returns a substring from the string ’s’.
**	The substring begins at index ’start’ and is of maximum size ’len’.
*/

#include "libft.h"
#include <stddef.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	i = 0;
	if (!s)
		return (NULL);
	if (start > ft_strlen(s) || len == 0)
	{
			str = malloc(1);
			*str = '\0';
		return (str);
	}
	if (ft_strlen(s) - start >= len)
			str = (char *)malloc(sizeof(char) * (len + 1));
	else
		str = (char *)malloc(sizeof(char) * (ft_strlen(s) - start + 1));
	if (!str)
		return (0);
	while (s[start] && i < len && start < ft_strlen(s))
	{	
		str[i] = s[start++];
		i++;
	}
	str[i] = '\0';
	return (str);
}
