/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_utils1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomes-c <jgomes-c@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 04:09:26 by jgomes-c          #+#    #+#             */
/*   Updated: 2022/02/06 06:50:10 by jgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	back_to_a(t_box *box)
{
	t_list	*temp;
	int		i;

	box->max = get_max(box, 1);
	i = get_position(box, box->max);
	temp = box->stack_b;
	while (temp)
	{
		if (box->size_b == 1)
			break ;
		if (temp->value == box->max)
		{
			move_pa(box);
			temp = box->stack_b;
			box->max = get_max(box, 1);
			i = get_position(box, box->max);
		}
		else
		{
			check(box, i);
			temp = box->stack_b;
		}
	}
	move_pa(box);
}

//move "max" to top
void	check(t_box *box, int i)
{
	if (i > (box->size_b / 2))
		move_rrb(box, 0);
	else
		move_rb(box);
}

int	get_position(t_box *box, int max)
{
	t_list	*temp;
	int		i;

	i = 0;
	temp = box->stack_b;
	while (temp)
	{
		i++;
		if (temp->value == max)
			return (max);
		temp = temp->next;
	}
	return (0);
}
