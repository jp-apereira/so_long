/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-p <jalves-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 12:56:11 by jalves-p          #+#    #+#             */
/*   Updated: 2023/04/19 12:56:14 by jalves-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "ft_printf.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	ft_strlen(char *str);
int	ft_putchar(char ch);
int	ft_putstr(char *str);
int	ft_putnbr(int nb);
int	ft_put_u(unsigned int nb);
int	ft_puthex(unsigned int n, int is_lower);
int	ft_put_pointer(unsigned long n);

#endif
