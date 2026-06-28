/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annlecre <annlecre@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 08:31:21 by annlecre          #+#    #+#             */
/*   Updated: 2026/06/17 14:04:56 by annlecre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);

char	*ft_strchr(const char *s, int c);

char	*ft_itoa(int n);

void	ft_putchar_fd(char c, int fd);

int		ft_printchar(char c);

int		ft_printstr(const char *s);

int		ft_printsnbr(int n);

int		ft_printunbr(unsigned int n);

int		ft_printhexa(unsigned int n, char *hex_base);

int		ft_printptr(void *ptr);

#endif
