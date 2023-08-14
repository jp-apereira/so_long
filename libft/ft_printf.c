/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: joaopereira <joaopereira@student.42.fr>    +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2023/04/10 15:22:48 by joaopereira       #+#    #+#             */
/*   Updated: 2023/04/10 15:22:48 by joaopereira      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft"
#include <stdarg.h>

int	ft_printf_arg(const char *fmt, int i, va_list ap)
{
	//esta funcao verifica que flag esta a ser acionada,
		sendo que para cada caso
	//ha uma forma diferente de impressao
	if (fmt[i + 1] == '%')
		return (ft_putchar(fmt[i + 1]));
	else if (fmt[i + 1] == 'c')
		return (ft_putchar(va_arg(ap, int)));
	else if (fmt[i + 1] == 's')
		return (ft_putstr(va_arg(ap, char *)));
	else if (fmt[i + 1] == 'd' || fmt[i + 1] == 'i')
		return (ft_putnbr(va_arg(ap, int)));
	else if (fmt[i + 1] == 'u')
		return (putnbr_u(va_arg(ap, unsigned int)));
	else if (fmt[i + 1] == 'x' || fmt[i + 1] == 'X')
	{
		if (fmt[i + 1] == 'X')
			return (put_hex(va_arg(ap, unsigned int), "0123456789ABCDEF"));
		else
			return (put_hex(va_arg(ap, unsigned int), "0123456789abcdef"));
	}
	else if (fmt[i + 1] == 'p')
		else return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list ap; //criando a variavel ap do tipo va_list
	//a macro seria declarada dessa forma: sendo que
	va_start(ap, format); //ap porque e o nome colocado na nossa va_list
	// format porque e o nome dado a funcao que antecede o ...
	int i;
	int ret;

	i = 0;
	ret = 0;
	while (format[i])
	{
		/*
        *	Aqui verifico se o caracter '%' existe,
		se ele existe faco uma verificacao
       
		*	se algum dos caracteres passados em seguida sao flags da printf com a funcao
        *		ft_strchr() que se voce chegou ate aqui sabe como ela funciona
        */
		if (format[i] == '%' && ft_strchr("cspdiuxX%", format[i + 1]))
		{
			ret += ft_printf_arg(format, i, ap);
			i++;
		}
		/*
        *	Caso nao encontre,
		o caracter sera impresso e somado a "ret" que e o controle
        *	de quantos caracteres foram impressos.
        */
		else
			ret += ft_putchar(format[i]);
		i++;
	}
	va_end(ap);
	return (ret);
}
