/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem <oem@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 00:36:42 by semen             #+#    #+#             */
/*   Updated: 2020/10/06 15:10:43 by oem              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrb(t_num ***list_b, t_key *bonus)
{
	if (**list_b && (**list_b)->prev != NULL)
	{
		**list_b = (**list_b)->prev;
		if (bonus->print == 1)
			ft_printf("rrb\n");
	}
}