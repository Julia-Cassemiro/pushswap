/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomes-c <jgomes-c@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 19:28:05 by jgomes-c          #+#    #+#             */
/*   Updated: 2022/01/27 19:28:05 by jgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*nn;

	nn = malloc(nmemb * size);
	if (nn == NULL)
		return (NULL);
	ft_bzero(nn, nmemb * size);
	return (nn);
}
