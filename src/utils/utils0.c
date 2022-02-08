/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomes-c <jgomes-c@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 18:40:45 by jgomes-c          #+#    #+#             */
/*   Updated: 2022/01/27 18:40:45 by jgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	ft_isdigit_char(char *c, t_box *box)
{
	int	i;

	i = 0;
	if (c[i] == '-' || c[i] == '+')
		i++;
	while (c[i] != '\0')
	{
		if (c[i] >= '0' && c[i] <= '9')
			i++;
		else
		{
			ft_putendl_fd("Error", 1);
			free_stack(box);
			exit(0);
		}
	}
	return (1);
}

void	free_stack(t_box *box)
{
	t_list	*temp;

	temp = box->stack_a;
	if (temp != NULL)
	{
		while (temp->next != NULL)
		{
			temp = temp->next;
			free(box->stack_a);
			box->stack_a = temp;
		}
	}
	free(box->stack_a);
	if (box->size_b > 0)
	{
		temp = box->stack_b;
		while (temp->next)
		{
			temp = temp->next;
			free(box->stack_b);
			box->stack_b = temp;
		}
	}
	free(box->stack_b);
	return ;
}

int	ft_atoi(const char *str, t_box *box)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
		result = result * 10 + (*str++ - '0');
	if ((result * sign) > INT_MAX || (result * sign) < INT_MIN)
	{
		free_stack(box);
		ft_putendl_fd("Error", 1);
		exit(1);
	}
	return ((int)(result * sign));
}

int	check_list(t_box *box, int box_int)
{
	t_list	*temp;

	temp = box->stack_a;
	if (temp->next == NULL)
		return (1);
	while (temp->next != NULL)
	{
		if (temp->value == box_int)
		{
			ft_putendl_fd("Error", 1);
			free_stack(box);
			exit(1);
		}
		temp = temp->next;
	}
	return (1);
}

t_list	*new_box(int box_int)
{
	t_list	*new;

	new = (t_list *)ft_calloc(1, sizeof(t_list));
	if (new == NULL)
		exit(1);
	new->next = NULL;
	new->value = box_int;
	return (new);
}
