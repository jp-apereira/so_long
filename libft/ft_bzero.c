/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaopereira <joaopereira@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 18:52:23 by joaopereira       #+#    #+#             */
/*   Updated: 2023/03/27 18:52:23 by joaopereira      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_bzero - fill memory with null, equal to memset
*/

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, '\0', n);
}
