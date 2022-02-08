/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomes-c <jgomes-c@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 23:47:24 by jgomes-c          #+#    #+#             */
/*   Updated: 2022/01/12 23:47:24 by jgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_list
{
	struct s_list	*next;
	int				value;

}	t_list;

typedef struct s_box
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		size_a;
	int		size_b;
	int		limit;
	int		movements;
	int		top;
	int		mid;
	int		bottom;
	int		first;
	int		last;
	int		min;
	int		max;
	int		c_chunk;
	int		last_position;
	int		first_position;
	int		hold_first;
	int		hold_second;
	int		value;
	int		i;
}	t_box;

#endif