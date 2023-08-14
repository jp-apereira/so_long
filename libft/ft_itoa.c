/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaopereira <joaopereira@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 22:37:03 by joaopereira       #+#    #+#             */
/*   Updated: 2023/04/09 21:37:19 by joaopereira      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_len(long long n, char *str)
{
	if (n >= 10)
		str = ft_len(n / 10, str);
	*str++ = (n % 10) + '0';
	*str = 0;
	return (str);
}

char	*ft_itoa(int n)
{
	char	str[15];

	if (n < 0)
	{
		str[0] = '-';
		ft_len(((long long)n * -1), &str[1]);
	}
	else
		ft_len(n, str);
	return (ft_substr(str, 0, (ft_strlen(str))));
}

/*  int main()
{
	long int a;
	a = -3000000000000000;
	printf("%s", ft_itoa(a));
}  */