/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgonzale <bgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 19:54:25 by bgonzale          #+#    #+#             */
/*   Updated: 2019/01/07 19:54:30 by bgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strldup(const char *s1, int i)
{
	int		j;
	char	*ptr;

	j = 0;
	if (!(ptr = (char *)malloc(sizeof(*ptr) * (i + 1))))
		return (NULL);
	while (j < i)
	{
		ptr[j] = s1[j];
		j++;
	}
	ptr[j] = '\0';
	return (ptr);
}

char		*ft_strtrim(char const *s)
{
	int		beg;
	int		i;
	int		end;

	if (!s)
		return (NULL);
	beg = -1;
	i = 0;
	end = -2;
	while (s[i])
	{
		while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && s[i])
			i++;
		if (s[i])
			beg = i;
		while (s[i])
		{
			if (s[i] != ' ' && s[i] != '\n' && s[i] != '\t')
				end = i;
			i++;
		}
	}
	return (ft_strldup(s + beg, end - beg + 1));
}
