/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgonzale <bgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 19:47:28 by bgonzale          #+#    #+#             */
/*   Updated: 2019/01/07 19:47:31 by bgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memalloc(size_t size)
{
	void			*vptr;
	unsigned char	*chptr;

	if (!(vptr = (void *)malloc(sizeof(*vptr) * size)))
		return (NULL);
	chptr = (unsigned char *)vptr;
	while (size--)
		*chptr++ = (unsigned char)0;
	return (vptr);
}
