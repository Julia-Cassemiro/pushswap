/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomes-c <jgomes-c@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 17:03:12 by jgomes-c          #+#    #+#             */
/*   Updated: 2022/02/05 17:03:12 by jgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	aux_move_pb(t_box *box, t_list *new_stack, t_list *aux);
void	aux_move_pa(t_box *box, t_list *new_stack, t_list *aux);

void	move_pb(t_box *box)
{
	t_list	*aux;
	t_list	*new_stack;

	if (box->stack_b == NULL)
		box->stack_b = new_box(0);
	if (box->size_a == 0)
		return ;
	aux = box->stack_a;
	new_stack = aux->next;
	if (box->size_b == 0)
	{
		aux_move_pb(box, new_stack, aux);
		return ;
	}
	aux->next = NULL;
	aux->next = box->stack_b;
	box->stack_a = new_stack;
	box->stack_b = aux;
	box->size_b++;
	box->size_a--;
	box->movements++;
	write(1, "pb\n", 3);
}

void	aux_move_pb(t_box *box, t_list *new_stack, t_list *aux)
{
	box->stack_b->value = aux->value;
	box->stack_a = new_stack;
	free(aux);
	aux = NULL;
	box->size_b++;
	box->size_a--;
	box->movements++;
	write(1, "pb\n", 3);
	return ;
}

void	move_pa(t_box *box)
{
	t_list	*aux;
	t_list	*new_stack;

	if (box->size_b == 0)
		return ;
	aux = box->stack_b;
	new_stack = aux->next;
	if (box->size_a == 0)
	{
		aux_move_pa(box, new_stack, aux);
		return ;
	}
	aux->next = NULL;
	aux->next = box->stack_a;
	box->stack_b = new_stack;
	box->stack_a = aux;
	box->size_b--;
	box->size_a++;
	box->movements++;
	write(1, "pa\n", 3);
}

void	aux_move_pa(t_box *box, t_list *new_stack, t_list *aux)
{
	box->stack_a->value = aux->value;
	box->stack_b = new_stack;
	free(aux);
	aux = NULL;
	box->size_b--;
	box->size_a++;
	box->movements++;
	write(1, "pa\n", 3);
	return ;
}
