/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchichep <jchichep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 16:04:19 by jchichep          #+#    #+#             */
/*   Updated: 2015/01/20 10:37:34 by jchichep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include		<string.h>

size_t			ft_strlen(const char *s)
{
	size_t		len;

	len = -1;
	while (s[++len]);
	return (len);
}
