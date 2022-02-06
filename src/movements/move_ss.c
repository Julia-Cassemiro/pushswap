/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move0.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomes-c <jgomes-c@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 01:01:31 by jgomes-c          #+#    #+#             */
/*   Updated: 2022/02/05 01:01:31 by jgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

void	aux_ss(t_list **list);

void	move_sa(t_box *box)
{
	t_list *temp;
	t_list *aux;

	if (box->size_a <= 0)
		return ;
	temp = new_box(0);
	aux = box->stack_a;
	temp->value = aux->value;
	aux->value = aux->next->value;
	aux->next->value = temp->value;
	box->movements++;
	free(temp);
	write(1, "sa\n", 3);
}

void	move_sb(t_box *box)
{
	t_list *temp;
	t_list *aux;

	if (box->size_b <= 1)
		return ;
	temp = new_box(0);
	aux = box->stack_b;
	temp->value = aux->value;
	aux->value = aux->next->value;
	aux->next->value = temp->value;
	box->movements++;
	free(temp);
	write(1, "sb\n", 3);
}

void	move_ss(t_box *box)
{
	aux_ss(&box->stack_a);
	aux_ss(&box->stack_b);
	box->movements++;
	write(1, "ss\n", 3);
}

void	aux_ss(t_list **list)
{
	t_list	*temp;
	t_list	*aux;

	temp = new_box(0);
	aux = *list;
	temp->value = aux->value;
	aux->value = aux->next->value;
	aux->next->value = temp->value;
	free(temp);
}
