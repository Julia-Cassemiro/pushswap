/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomes-c <jgomes-c@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 23:55:08 by jgomes-c          #+#    #+#             */
/*   Updated: 2022/01/12 23:55:08 by jgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"
#include "../includes/struct.h"

static void ft_initialise(t_box *box)
{
	box->stack_a = new_list(0);
	box->stack_b = new_list(0);
}

static int ft_create_stack(t_list **head, char **argv, t_box *box)
{
	t_list *temp;
	int i;
	int t_num;

	temp = *head;
}

//argc é a qtd de parametros
//argv é o 9 78 00
int main(int argc, char **argv)
{
	t_box	box;

	if (argc <= 2)
		exit(2);

	//converter argv pra int, e colocar os convertido na linkedinlist
	//cria uma função para isso!
	ft_initialise(&box);
	ft_create_stack(&box.stack_a, argv, &box);
	
}

t_box *new_list(int number)
{
	t_list *new;

	new = (t_list *)ft_calloc(1, sizeof(t_list)); //1 variáve ​​a ser alocada na memória e o tamanho em bytes dessa variavel
	if (new == NULL)
		exit(2);
	
	new->next = NULL;
	new->value = number;
	return (new);
}