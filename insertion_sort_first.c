/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort_first.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calpha <calpha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 18:57:22 by oem               #+#    #+#             */
/*   Updated: 2020/08/15 20:27:59 by calpha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void search_struct_to_move(t_number **list_a, int *step_a, int *step_b, int *logic_a, int *logic_b)
{
    int min = 2147483647;
    int num = (*list_a)->n;
    while (*list_a)
    {
        if ((*list_a)->sum_steps < min)
        {
            min = (*list_a)->sum_steps;
            *step_a = (*list_a)->step_a;
            *step_b = (*list_a)->step_b;
            *logic_a = (*list_a)->logic_a;
            *logic_b = (*list_a)->logic_b;
        }
        *list_a = (*list_a)->next;
        if (num == (*list_a)->n)
            break;
    }
}

int insertion_sort_first(t_number **list_a, t_number **list_b, int quantity)
{
    int i;

    i = 0;
    int step_a = 0;
    int step_b = 0;
    int logic_a = 0;
    int logic_b = 0;

    while (*list_a)
    {
        quantity--;
        if (*list_b == NULL)
        {
            pb_three(&list_a, &list_b);
            show_me_two(list_a, list_b);
            usleep(500000);
            i++;
        }

        find_min_steps_from_a_to_b_three(list_a, list_b);

        search_struct_to_move(list_a, &step_a, &step_b, &logic_a, &logic_b);

        if ((logic_a == 0 && logic_b == 0) || (logic_a == 1 && logic_b == 1))
        {
            int zn;
            zn = step_a - step_b < 0 ? -(step_a - step_b) : step_a - step_b;
            int max;
            max = step_a > step_b ? step_a : step_b;
            int q = max - zn;
            step_a = step_a - q;
            step_b = step_b - q;
            while(q)
            {
                if (logic_a == 0)
                {
                    rr_three(&list_a, &list_b);
                    show_me_two(list_a, list_b);
                    i++;
                }
                else
                {
                    rrr_three(&list_a, &list_b);
                    show_me_two(list_a, list_b);
                    i++;
                }
                q--;
                // usleep(500000);
                // show_me_two(list_a, list_b);
            }
        }
        while(step_a)
        {
            if (logic_a == 0)
            {
                ra_three(&list_a);
                show_me_two(list_a, list_b);
                i++;
            }
            else
            {
                rra_three(&list_a);
                show_me_two(list_a, list_b);
                i++;
            }
            step_a--;
            // usleep(500000);
            // show_me_two(list_a, list_b);
        }
        while(step_b)
        {
            if (logic_b == 0)
            {
                rb_three(&list_b);
                show_me_two(list_a, list_b);
                i++;
            }
            else
            {
                rrb_three(&list_b);
                show_me_two(list_a, list_b);
                i++;
            }
            step_b--;
            // usleep(500000);
            // show_me_two(list_a, list_b);
        }
        pb_three(&list_a, &list_b);
        i++;
        // usleep(500000);
        show_me_two(list_a, list_b);

        if (quantity == 1)
            break;
    }
    return (i);
}