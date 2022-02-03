/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomes-c <jgomes-c@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 20:39:37 by jgomes-c          #+#    #+#             */
/*   Updated: 2022/01/27 20:39:37 by jgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/pushswap.h"

static void ft_initialise(t_box *box);
static void	count_argv(char **argv, t_box *box); //contagem elementos no argv
static int ft_create_stack(t_list **head, char **argv, t_box *box);

static void	count_argv(char **argv, t_box *box) //contagem elementos no argv
{
	box->limit = 1;
	while (argv[box->limit] != NULL) //enqt n for null, incrementa
		box->limit++;
}

static int ft_create_stack(t_list **head, char **argv, t_box *box)
{
	t_list *temp; //pra q?
	int i;
	int t_num;

	temp = *head; //nossa temporaria recebe &box.stack_a
	i = 1;
	count_argv(argv, box);
	while (argv[i] != NULL && ft_isdigit_char(argv[i], box) == 1)
	{
		i++;
	}
	return (1);
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
	ft_create_stack(&box.stack_a, argv, &box); //cria espaço a partir do argv
	exit(0);
	
}

t_box *new_list(int number)
{
	t_list *new;

	new = (t_list *)ft_calloc(1, sizeof(t_list)); //1 variáve ​​a ser alocada na memória e o tamanho em bytes dessa variavel
	if (new == NULL)
		exit(2);
	
	new->next = NULL;
	new->value = number;

}

static void ft_initialise(t_box *box)
{
	box->stack_a = 0;
	box->stack_b = 0;
}