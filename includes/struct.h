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

//criou as struct para armazenamento e contagem e posição

typedef struct s_list
{
	struct s_list	*next;	//proximo bit, node
	int		value;	//numero q vai ta no node, separar os numeros por caixinha

} t_list;

typedef struct s_box
{
	t_list *stack_a;
	t_list *stack_b;
	int		limit; //limite para o argv
} t_box;


#endif