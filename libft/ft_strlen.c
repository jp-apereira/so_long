/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaopereira <joaopereira@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 18:46:52 by joaopereira       #+#    #+#             */
/*   Updated: 2023/03/27 18:46:52 by joaopereira      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** 		The strlen() function computes the length of the string str.
*/

#include "libft.h"
#include "stddef.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
