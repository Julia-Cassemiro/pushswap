/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomes-c <jgomes-c@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 23:09:45 by jgomes-c          #+#    #+#             */
/*   Updated: 2022/02/05 23:09:45 by jgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"


void	five_cont_one(t_box *box);
void	five_cont_two(t_box *box, t_list *temp);

void	three_numbers(t_box *box)
{
	get_three(box);
	if (box->bottom > box->top && box->bottom < box->mid)
	{
		move_rra(box, 0);
		move_sa(box);
	}
	if (box->bottom > box->mid && box->bottom > box->top && box->top > box->mid)
		move_sa(box);
	if (box->bottom < box->top && box->bottom < box->mid)
	{
		if (box->top > box->mid && box->mid > box->bottom)
			move_sa(box);
		move_rra(box, 0);
	}
	if (box->bottom > box->mid && box->bottom < box->top)
		move_ra(box);
}

//move big and min for stack b
void	four_numbers(t_box *box)
{
	int		min;
	int		max;

	min = get_min(box);
	max = get_max(box, 0);
	if (box->stack_a->value == min || box->stack_a->value == max)
		move_pb(box);
	else if (box->stack_a->next->value == min || box->stack_a->next->value == max)
	{
		move_sa(box);
		move_pb(box);
	}
	else
	{
		move_rra(box, 0);
		move_pb(box);
	}
	three_numbers(box);
	if (box->stack_b->value == max)
	{
		move_pa(box);
		move_ra(box);
	}
	else
		move_pa(box);
}

void	five_numbers(t_box *box)
{
	t_list	*temp;

	box->min = get_min(box);
	box->max = get_max(box, 0);
	five_cont_one(box); // envia os dois primeiros números da pilha A para a pilha B.
	three_numbers(box); // usa a lógica de 3 números aleatórios para classificar os números em A.
	temp = box->stack_b;
	five_cont_two(box, temp); // certifica-se de que a pilha A pode aceitar corretamente os números da pilha B.
}

void	five_cont_two(t_box *box, t_list *temp)
{
	temp = box->stack_b;
	box->first = temp->value;
	box->last = temp->next->value;
	if (box->first < box->last)
	{
		move_sb(box);
		move_pa(box);
		move_ra(box);
		move_pa(box);
	}
	else if (box->first > box->last)
	{
		move_pa(box);
		move_ra(box);
		move_pa(box);
	}
	else
	{
		move_pa(box);
		move_pa(box);
	}
}

void	five_cont_one(t_box *box)
{
	t_list	*temp;

	temp = box->stack_a;
	while (box->size_b <= 2)
	{
		if (temp->value == box->min || temp->value == box->max)
		{
			move_pb(box);
			temp = box->stack_a;
			continue ;
		}
		if (temp->next->value == box->min || temp->next->value == box->max)
		{
			move_sa(box);
			move_pb(box);
			temp = box->stack_a;
			continue ;
		}
		else
		{
			move_rra(box, 0);
			temp = box->stack_a;
			continue ;
		}
	}
}
