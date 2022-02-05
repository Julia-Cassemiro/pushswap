/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomes-c <jgomes-c@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 00:33:07 by jgomes-c          #+#    #+#             */
/*   Updated: 2022/02/05 00:33:07 by jgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"


int	check_if_complete(t_box *box)
{
	t_list	*temp;
	int		ant_num;

	ant_num = 0;
	temp = box->stack_a;
	while (temp->next)
	{
		ant_num = temp->value;
		temp = temp->next;
		if (ant_num > temp->value) //se for maior q o da frente, n ta organizado
		{
			printf("n foi na ordem");

			return (0);
		}
	}
	printf("foi na ordem ja");
	free_stack(box);
	exit(1);
	return (1);
}