/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annlecre <annlecre@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 07:59:11 by annlecre          #+#    #+#             */
/*   Updated: 2026/04/28 11:08:51 by annlecre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*applies the function ’f’ on each character of the
string passed as argument, passing its index as first
argument. Each character is passed by address to ’f’
to be modified if necessary.*/

#include "libft.h"
#include <stdio.h>
/*
void	f(unsigned int i, char *c)
{
	*c = *c + i;
}*/

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		(*f)(i, &s[i]);
		i++;
	}
}
/*
int	main(void)
{
	char	str[] = "abcd";
	
	ft_striteri(str, f);
	printf("striteri : [%s]\n", str);
	return (0);
}*/
