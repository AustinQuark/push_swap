/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira <avieira@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 20..//10 15:47:05 by avieira           #+#    #+#             */
/*   Updated: 2021/10/09 13:48:18 by avieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strdup(char *s1)
{
	char	*cpy;
	char	*temp;
	int		len;

	len = 0;
	while (s1[len])
		len++;
	cpy = malloc(sizeof(char) * (len + 1));
	if (!cpy)
		return (NULL);
	temp = cpy;
	while (len--)
		*temp++ = *s1++;
	*temp = 0;
	return (cpy);
}
