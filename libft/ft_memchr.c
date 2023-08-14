/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaopereira <joaopereira@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 21:04:31 by joaopereira       #+#    #+#             */
/*   Updated: 2023/03/30 21:04:31 by joaopereira      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdlib.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*source;
	size_t			i;

	source = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (*(unsigned char *)(s + i) == (unsigned char)c)
			return (source + i);
		i++;
	}
	return (0);
}

/* int main()
{
const char str[] = "apartirdaqui.achoqueesta.certo";
   const char ch = '.';
   char *ret;
   ret = ft_memchr(str, ch, 40);
   printf("String after |%c| is - |%s|\n", ch, ret);
   return(0);
} */ 