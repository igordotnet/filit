/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgonzale <bgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 19:48:04 by bgonzale          #+#    #+#             */
/*   Updated: 2019/01/07 19:48:07 by bgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*sptr;
	int				i;
	unsigned char	ch;

	sptr = (unsigned char *)s;
	i = 0;
	ch = (unsigned char)c;
	while (n--)
	{
		if (*(sptr + i) == ch)
			return ((void *)(s + i));
		i++;
	}
	return (NULL);
}
