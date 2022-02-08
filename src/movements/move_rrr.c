/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_rrr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomes-c <jgomes-c@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 04:44:40 by jgomes-c          #+#    #+#             */
/*   Updated: 2022/02/05 04:44:40 by jgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	move_rra(t_box *box, int info)
{
	t_list	*aux;
	t_list	*last;
	t_list	*temp;

	aux = box->stack_a;
	temp = aux;
	while (aux->next->next)
		aux = aux->next;
	last = aux->next;
	aux->next = NULL;
	last->next = temp;
	box->stack_a = last;
	if (info == 1)
		return ;
	box->movements++;
	write(1, "rra\n", 4);
}

void	move_rrb(t_box *box, int info)
{
	t_list	*aux;
	t_list	*last;
	t_list	*temp;

	aux = box->stack_b;
	temp = aux;
	while (aux->next->next)
		aux = aux->next;
	last = aux->next;
	aux->next = NULL;
	last->next = temp;
	box->stack_b = last;
	if (info == 1)
		return ;
	box->movements++;
	write(1, "rrb\n", 4);
}

void	move_rrr(t_box *box)
{
	move_rra(box, 1);
	move_rrb(box, 1);
	box->movements++;
	write(1, "rrr\n", 4);
}
