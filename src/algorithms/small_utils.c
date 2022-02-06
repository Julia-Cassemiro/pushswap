/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomes-c <jgomes-c@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 00:08:15 by jgomes-c          #+#    #+#             */
/*   Updated: 2022/02/06 00:08:15 by jgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

void	index_small(t_box *box)
{
	if (box->size_a == 2)
		move_sa(box);
	if (box->size_a == 3)
		three_numbers(box);
	if (box->size_a == 4)
		four_numbers(box);
	if (box->size_a == 5)
		five_numbers(box);
}

void	get_three(t_box *box)
{
	box->top = box->stack_a->value;
	box->mid = box->stack_a->next->value;
	box->bottom = box->stack_a->next->next->value;
}

int	get_min(t_box *box)
{
	t_list	*temp;
	int		min;

	temp = box->stack_a;
	min = temp->value;
	while (temp != NULL)
	{
		if (temp->value < min)
			min = temp->value;
		temp = temp->next;
	}
	return (min);
}

int	get_max(t_box *box, int i)
{
	t_list	*temp;
	int		max;

	if (i == 0)
		temp = box->stack_a;
	else
		temp = box->stack_b;
	max = temp->value;
	while (temp != NULL)
	{
		if (temp->value > max)
			max = temp->value;
		temp = temp->next;
	}
	return (max);
}