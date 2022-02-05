/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_rr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomes-c <jgomes-c@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 02:32:14 by jgomes-c          #+#    #+#             */
/*   Updated: 2022/02/05 02:32:14 by jgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

void	rotate(t_list **box);

void	move_ra(t_box *box)
{
	if (box->size_a <= 1)
		return ;
	rotate(&box->stack_a);
	write(1, "ra\n", 3);
	box->movements++;
}

void	move_rb(t_box *box)
{
	if (box->size_b <= 1)
		return ;
	rotate(&box->stack_b);
	write(1, "rb\n", 3);
	box->movements++;
}

void	move_rr(t_box *box)
{
	rotate(&box->stack_a);
	rotate(&box->stack_b);
	write(1, "rr\n", 3);
	box->movements++;
}

void	rotate(t_list **box)
{
	t_list	*temp;
	t_list	*aux;
	t_list	*first;

	aux = (*box)->next;
	temp = aux;
	first = *box;
	first->next = NULL;
	while (aux->next)
		aux = aux->next;
	aux->next = first;
	*box = temp;
}