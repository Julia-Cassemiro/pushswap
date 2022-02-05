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
	int		value;	//o numero q clc dentro da lista

} t_list;

typedef struct s_box
{
	t_list *stack_a;
	t_list *stack_b;
	int 	size_a;	//tamanho da stack_a
	int 	size_b;	//tamanho da stack_b
	int		limit; //limite para o argv
	int		movements; //movimentos para troca
} t_box;


#endif