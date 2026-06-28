/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annlecre <annlecre@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 12:13:06 by annlecre          #+#    #+#             */
/*   Updated: 2026/05/02 07:28:38 by annlecre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>*/
#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	else
		return (0);
}
/*
int	main(void)
{
	printf("F:%d\n", ft_isalpha('F'));
	printf("z:%d\n", ft_isalpha('z'));
	printf("7:%d\n", ft_isalpha('7'));
	printf("42:%d\n", ft_isalpha(42));
}*/
