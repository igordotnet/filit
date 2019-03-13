/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgonzale <bgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 19:52:22 by bgonzale          #+#    #+#             */
/*   Updated: 2019/01/07 19:52:25 by bgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	char		*dptr;
	const char	*sptr;
	size_t		dlen;

	dptr = dst;
	sptr = src;
	while (*dptr && dstsize)
	{
		dptr++;
		dstsize--;
	}
	dlen = dptr - dst;
	if (!dstsize)
		return (ft_strlen(src) + dlen);
	while (*sptr && dstsize-- > 1)
		*dptr++ = *sptr++;
	while (*sptr)
		sptr++;
	*dptr = '\0';
	return (dlen + (sptr - src));
}
