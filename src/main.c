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

#include "../includes/push_swap.h"

static int	create_stack(t_box *box, char **argv);
static void	initialize(t_box *box);
static void	count_argv(char **argv, t_box *box);

int	main(int argc, char **argv)
{
	t_box	box;

	if (argc <= 2)
		exit(1);
	initialize(&box);
	create_stack(&box, argv);
	check_if_complete(&box);
	if (argc <= 6)
		index_small(&box);
	else
		big_stack(&box);
	free_stack(&box);
	exit(0);
}

static int	create_stack(t_box *box, char **argv)
{
	t_list	*temp;
	int		i;
	int		box_int;

	temp = box->stack_a;
	i = 1;
	count_argv(argv, box);
	while (argv[i] != NULL && ft_isdigit_char(argv[i], box) == 1)
	{
		box_int = ft_atoi(argv[i], box);
		check_list(box, box_int);
		temp->value = box_int;
		if ((box->limit - 1) == i)
		{
			box->size_a++;
			return (1);
		}
		temp->next = new_box(box_int);
		temp = temp->next;
		i++;
		box->size_a++;
	}
	return (1);
}

static void	initialize(t_box *box)
{
	box->stack_a = new_box(0);
	box->stack_b = new_box(0);
	box->size_a = 0;
	box->size_b = 0;
	box->movements = 0;
	box->c_chunk = 0;
	box->i = 0;
}

static void	count_argv(char **argv, t_box *box)
{
	box->limit = 1;
	while (argv[box->limit] != NULL)
		box->limit++;
}
