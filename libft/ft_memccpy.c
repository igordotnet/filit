/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgonzale <bgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 19:47:54 by bgonzale          #+#    #+#             */
/*   Updated: 2019/01/07 19:47:58 by bgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*dptr;
	unsigned char	*sptr;
	int				i;

	dptr = (unsigned char *)dst;
	sptr = (unsigned char *)src;
	i = 0;
	while (n--)
	{
		*(dptr + i) = *(sptr + i);
		if (*(dptr + i) == (unsigned char)c)
			return (dst + i + 1);
		i++;
	}
	return (NULL);
}
