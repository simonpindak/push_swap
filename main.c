/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semen <semen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 20:09:54 by calpha            #+#    #+#             */
/*   Updated: 2020/03/31 14:27:58 by semen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main (int ac, char *av[])
{
	if (validation(ac, av) == 0)
	{
		ft_putstr("Error\n");
		exit(0);
	}
	sorting(ac, av);
	return (0);
}
