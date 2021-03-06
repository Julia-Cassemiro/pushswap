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

#include "../../includes/push_swap.h"

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
		if (ant_num > temp->value)
			return (0);
	}
	free_stack(box);
	exit(1);
	return (1);
}
