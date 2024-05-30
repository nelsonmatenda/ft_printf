/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util .c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 08:46:49 by nfigueir          #+#    #+#             */
/*   Updated: 2024/05/30 11:40:27 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

void    ft_init_data (t_data d, const char *s)
{
    d.s = s;
    d.nbr_char_printed = 0;
    d.place_holder = NULL;
    d.f.minus[0] = 0;
    d.f.minus[1] = 0;
    d.f.plus = 0;
    d.f.dot [0] = 0;
    d.f.dot [1] = 0;
    d.f.zero[0] = 0;
    d.f.zero[1] = 0;
    d.f.space = 0;
    d.f.hash = 0;
    d.f.width = 0;
    d.f.specifier = "cspdiuxX%";
}