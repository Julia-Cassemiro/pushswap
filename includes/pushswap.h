/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomes-c <jgomes-c@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 23:46:28 by jgomes-c          #+#    #+#             */
/*   Updated: 2022/01/12 23:46:28 by jgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

# include "./struct.h"
# include "./libft/libft.h"

int 	main(int argc, char **argv);
int		check_list(t_box *box, int box_num);
int		ft_isdigit_char(char *c, t_box *box);
void	free_stack(t_box *box);
int		ft_atoi(const char *str, t_box *box);
t_list	*new_box(int numb);
int	check_if_complete(t_box *box);

#endif