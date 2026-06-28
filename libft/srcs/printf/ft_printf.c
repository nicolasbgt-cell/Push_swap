/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annlecre <annlecre@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 07:47:09 by annlecre          #+#    #+#             */
/*   Updated: 2026/06/17 14:03:47 by annlecre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

static int	is_specifier(char c)
{
	return (ft_strchr("cspdiuxX%", c) != NULL);
}

static int	ft_convert2(char c, va_list args)
{
	int	sub_len;

	sub_len = 0;
	if (c == 'x')
		sub_len += ft_printhexa(va_arg(args, unsigned int),
				"0123456789abcdef");
	if (c == 'X')
		sub_len += ft_printhexa(va_arg(args, unsigned int),
				"0123456789ABCDEF");
	else if (c == '%')
		sub_len += ft_printchar('%');
	return (sub_len);
}

static int	ft_convert(char c, va_list args)
{
	int	sub_len;

	sub_len = 0;
	if (c == 'c')
		sub_len += ft_printchar(va_arg(args, int));
	if (c == 's')
		sub_len += ft_printstr(va_arg(args, const char *));
	if (c == 'p')
		sub_len += ft_printptr(va_arg(args, void *));
	if (c == 'd')
		sub_len += ft_printsnbr(va_arg(args, int));
	if (c == 'i')
		sub_len += ft_printsnbr(va_arg(args, int));
	if (c == 'u')
		sub_len += ft_printunbr(va_arg(args, unsigned int));
	else
		ft_convert2(c, args);
	return (sub_len);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		len;

	va_start(args, format);
	i = 0;
	len = 0;
	while (format[i])
	{
		if (format[i] == '%' && is_specifier(format[i + 1]))
		{
			len += ft_convert(format[i + 1], args);
			i += 2;
		}
		else
		{
			len += ft_printchar(format[i]);
			i++;
		}
	}
	va_end(args);
	return (len);
}
/*
int     main(void)
{
        char a = '5';
        char *b = "abcde";
        int c = 6;
        int i = 0;
        int j = 0;
	float f = 42.424242;

        i = printf("%c\n", a);
        j = ft_printf("%c\n", a);
        printf("comp %d = %d\n", i, j);


        i = printf("hello\n");
        j = ft_printf("hello\n");
        printf("comp %d = %d\n", i, j);

        i = printf("%s\n", b);
        j = ft_printf("%s\n", b);
        printf("comp %d = %d\n", i, j);


        i = printf("%d\n", c);
        j = ft_printf("%d\n", c);
        printf("comp %d = %d\n", i, j);


        i = printf("%i\n", c);
        j = ft_printf("%i\n", c);
        printf("comp %d = %d\n", i, j);


        i = printf("%u\n", c);
        j = ft_printf("%u\n", c);
        printf("comp %d = %d\n", i, j);


        i = printf("%%\n");
        j = ft_printf("%%\n");
        printf("comp %d = %d\n", i, j);


        i = printf("%X\n", 10);
        j = ft_printf("%X\n", 10);
        printf("comp %d = %d\n", i, j);

	float	f = 42.42;
	ft_printf("ft_printf:%f%%\n", f);
	printf("printf:%f\n", f);
}*/
