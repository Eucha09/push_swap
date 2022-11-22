/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eujeong <eujeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 14:36:54 by eujeong           #+#    #+#             */
/*   Updated: 2022/11/11 15:40:05 by eujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALIDATOR_H
# define VALIDATOR_H

# include "push_swap_oper.h"

int	is_int(char *str);
int	is_valid(int argc, char *argv[]);
int	is_duplicate(t_stack *a, int value);
int	arg_to_stack(int argc, char *argv[], t_stack *a);
int	is_sorted(t_stack *a);

#endif