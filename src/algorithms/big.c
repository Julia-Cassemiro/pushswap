/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomes-c <jgomes-c@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 04:09:51 by jgomes-c          #+#    #+#             */
/*   Updated: 2022/02/06 06:50:10 by jgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	big_stack(t_box *box)
{
	int	bigf_chunk;

	bigf_chunk = f_chunk(box);
	while (box->size_a > 0)
	{
		if (box->size_a == 1)
		{
			check_send(box, box->stack_a->value);
			move_pb(box);
			break ;
		}
		if (box->i == box->c_chunk)
		{
			box->c_chunk = 0;
			bigf_chunk = f_chunk(box);
			box->i = 0;
		}
		check_swap(box, bigf_chunk);
		box->i++;
	}
	box->stack_a = new_box(0);
	back_to_a(box);
}

//decide which movement is better
void	check_swap(t_box *box, int bigf_chunk)
{
	int	half;

	half = (box->size_a / 2);
	find_min(box, bigf_chunk);
	box->hold_second = get_number(box, bigf_chunk);
	if (box->first_position <= half - (box->last_position - half))
		parse_to_send(box);
	else
		check_second(box);
	return ;
}

//get bigger number but less than bigf_chunk "inside chunk" + position
int	get_number(t_box *box, int bigf_chunk)
{
	t_list	*aux;
	int		num;

	box->last_position = 0;
	num = 0;
	aux = box->stack_a;
	while (aux)
	{
		if (aux->value <= bigf_chunk)
			num = aux->value;
		aux = aux->next;
	}
	aux = box->stack_a;
	while (aux)
	{
		if (aux->value == num)
			return (num);
		aux = aux->next;
		box->last_position++;
	}
	return (num);
}

//find 25th bigger number inside chunk(25)
int	f_chunk(t_box *box)
{
	t_list	*temp;
	t_list	*aux;

	box->max = INT_MAX;
	aux = box->stack_a;
	box->min = get_min(box);
	while (box->stack_a)
	{
		temp = box->stack_a;
		while (temp)
		{
			if (temp->value > box->min && temp->value < box->max)
				box->max = temp->value;
			temp = temp->next;
		}
		box->c_chunk++;
		aux = aux->next;
		if (box->c_chunk == 25 || aux->next == NULL)
			return (box->max);
		box->min = box->max;
		box->max = INT_MAX;
	}
	return (box->max);
}

void	check_second(t_box *box)
{
	t_list	*temp;

	temp = box->stack_a;
	if (box->last_position == 0)
	{
		check_send(box, box->hold_second);
		move_pb(box);
		return ;
	}
	while (temp)
	{
		if (box->size_a == 1)
			return ;
		temp = temp->next;
		temp = box->stack_a;
		if (temp->value == box->hold_second)
		{
			check_send(box, box->hold_second);
			move_pb(box);
			return ;
		}
		move_rra(box, 0);
	}
}
