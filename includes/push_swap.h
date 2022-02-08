/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomes-c <jgomes-c@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 06:49:02 by jgomes-c          #+#    #+#             */
/*   Updated: 2022/02/06 06:49:02 by jgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "./libft/libft.h"
# include "./struct.h"

# define INT_MAX 2147483647
# define INT_MIN -2147483648

int		main(int argc, char **argv);
int		check_list(t_box *box, int box_num);
int		ft_isdigit_char(char *c, t_box *box);
void	free_stack(t_box *box);
int		ft_atoi(const char *str, t_box *box);
t_list	*new_box(int numb);
int		check_if_complete(t_box *box);
void	move_sa(t_box *box);
void	move_sb(t_box *box);
void	move_ss(t_box *box);
void	move_rra(t_box *box, int info);
void	move_rrb(t_box *box, int info);
void	move_rrr(t_box *box);
void	move_ra(t_box *box);
void	move_rb(t_box *box);
void	move_rr(t_box *box);
void	move_pb(t_box *box);
void	move_pa(t_box *box);
void	index_small(t_box *box);
void	three_numbers(t_box *box);
void	get_three(t_box *box);
int		get_min(t_box *box);
int		get_max(t_box *box, int i);
void	four_numbers(t_box *box);
void	five_numbers(t_box *box);
void	big_stack(t_box *box);
int		f_chunk(t_box *box);
void	check(t_box *box, int i);
void	check_send(t_box *box, int big);
void	check_swap(t_box *box, int bigf_chunk);
void	check_second(t_box *box);
void	check_support(t_box *box, int cont, int min);
int		get_number(t_box *box, int bigf_chunk);
void	find_min(t_box *box, int bigf_chunk);
void	parse_to_send(t_box *box);
void	back_to_a(t_box *box);
int		get_position(t_box *box, int max);
void	five_cont_one(t_box *box);
void	five_cont_two(t_box *box, t_list *temp);
void	move_aux(t_box *box);

#endif