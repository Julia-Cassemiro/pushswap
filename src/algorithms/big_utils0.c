/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_utils0.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomes-c <jgomes-c@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 04:09:56 by jgomes-c          #+#    #+#             */
/*   Updated: 2022/02/06 06:50:10 by jgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

//find number smallest number than bigf_chunk
void	find_min(t_box *box, int bigf_chunk)
{
	t_list	*temp;

	temp = box->stack_a;
	box->first_position = 0;
	while (temp)
	{
		if (temp->value < bigf_chunk)
		{
			box->hold_first = temp->value;
			break ;
		}
		box->first_position++;
		temp = temp->next;
	}
}

void	parse_to_send(t_box *box)
{
	t_list	*temp;

	temp = box->stack_a;
	if (box->first_position == 0)
	{
		check_send(box, box->hold_first);
		move_pb(box);
		return ;
	}
	while (temp)
	{
		temp = box->stack_a;
		if (temp->value == box->hold_first)
		{
			check_send(box, box->hold_first);
			move_pb(box);
			return ;
		}
		move_ra(box);
	}
}

void	check_send(t_box *box, int big)
{
	t_list	*temp;

	box->value = 0;
	if (box->size_b == 0)
		return ;
	temp = box->stack_b;
	box->min = INT_MIN;
	while (temp)
	{
		if (temp->value < big && temp->value > box->min)
			box->min = temp->value;
		temp = temp->next;
	}
	temp = box->stack_b;
	while (temp)
	{
		box->value++;
		if (temp->value == box->min)
			check_support(box, box->value, box->min);
		temp = temp->next;
	}
	return ;
}

void	check_support(t_box *box, int cont, int min)
{
	t_list	*temp;

	temp = box->stack_b;
	if (cont > (box->size_b / 2))
	{
		while (temp->value != min)
		{
			move_rrb(box, 0);
			temp = box->stack_b;
		}
		return ;
	}
	else
	{
		while (temp->value != min)
		{
			move_rb(box);
			temp = box->stack_b;
		}
		return ;
	}
}
