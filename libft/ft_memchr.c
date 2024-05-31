/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 10:20:01 by nfigueir          #+#    #+#             */
/*   Updated: 2024/05/31 12:40:06 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(char *s, int c, size_t n)
{
	char	*str = (char *)(s);
	size_t	 i;
	
	i = 0;
	while (i < n)
	{
		if (*(unsigned char *)(str + i) == (unsigned char)c)
			return ((void *)(str + i));
		i++;
	}
	return (NULL);
}

//int	main(void)
//{
//	char s[] = "matenda@hotmail.com";
//	char *domain = ft_memchar(s, '@', ft_strlen(s));
//
//	printf("domain: %s\n", domain);
//	return (0);
//}
