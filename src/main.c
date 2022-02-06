/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomes-c <jgomes-c@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 03:02:58 by jgomes-c          #+#    #+#             */
/*   Updated: 2022/02/04 03:02:58 by jgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

static int create_stack(t_box *box, char **argv);
static void initialize(t_box *box);
static void count_argv(char **argv, t_box *box);

int main(int argc, char **argv)
{
	t_box box;
	t_list *temp;

	if (argc <= 2)
		exit(1);
	initialize(&box);
	create_stack(&box, argv);
	check_if_complete(&box); // ela vai ver se ja ta organizado, do menor para o maior
	if (argc <= 6)
		index_small(&box);
	temp = box.stack_a;
	while (temp != NULL)
	{
		printf("antes A: %d\n", temp->value);
		temp = temp->next;
	}
	// else
	// 	big_stack(&box);
	free_stack(&box);
	exit(0);
}

static int create_stack(t_box *box, char **argv)
{
	t_list *temp;
	int i;
	int box_int; // armazenar o int q ta vindo da argv

	temp = box->stack_a;
	i = 1;
	count_argv(argv, box);
	// while ate os parametros acabar, verifica se ele é digito
	while (argv[i] != NULL && ft_isdigit_char(argv[i], box) == 1)
	{
		// o argv esta como char aqui
		box_int = ft_atoi(argv[i], box); // se for um numero tranforma ele em int, ele veio como char do argv, e clc no box_int
		// meu box_int passa a ter o conteudo do argv
		// essa função anda pela struct, e verifica se tem numero repetidos na lista
		check_list(box, box_int);
		// se passou na checagem ela é um numero valido e n é repetido
		temp->value = box_int;	   // inserindo valor na list direto, a partir da temporaria
		if ((box->limit - 1) == i) // quando fazer o ultimo itemm da lista nao criar um a mais
		{
			box->size_a++;
			return (1);
		}
		temp->next = new_box(box_int); // criar uma nova box, q aponta para a null, e armazenar no value o box_int
		// agora eu movo a temp para frente
		temp = temp->next;
		i++;
		box->size_a++;
	}
	return (1);
}

static void initialize(t_box *box)
{
	box->stack_a = new_box(0);
	box->stack_b = new_box(0);
	box->size_a = 0;
	box->size_b = 0;
	box->movements = 0;
}

static void count_argv(char **argv, t_box *box)
{
	box->limit = 1;
	while (argv[box->limit] != NULL)
		box->limit++;
}