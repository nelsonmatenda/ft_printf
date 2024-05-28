/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 13:00:08 by nfigueir          #+#    #+#             */
/*   Updated: 2024/05/28 12:55:32 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/printf.h"

void    ft_call_prints(const char *fmt, t_data d);

int	ft_printf(const char *first_arg, ...)
{
    t_data  data;
    int i;
    t_data  *teste;

    va_start(data.ap, first_arg);
    ft_init_data(data, first_arg);
    i = 0;
    while (first_arg[i])
    {
        if (first_arg[i] == '%')
        {
            ft_call_prints(&first_arg[++i], data); // TODO: fazer a funcao
            i++;
        }
        else
        {
            ft_putchar_fd(first_arg[i], 1);
            data.nbr_char_printed +=1;
        }
        i++;
    }
    va_end(all_arg);
    return (data.nbr_char_printed);
}

void     ft_call_prints(const char *fmt, t_data d)
{
    // TODO: do de "# .0-+"
    // cspdiuxX%
    if (*fmt = 'c')
        d.nbr_char_printed += ft_putchar(va_arg(d.ap, int));
    // if (*fmt = 's')
    //     d.nbr_char_printed += ft_putstr(va_arg(d.ap, char *));
    
}

char ft_find_spec(const char fmt)
{
    char *spec;
    char    *flags;

    flags = ""
    spec = ft_memchr(cspdiuxX%);
    while (!spec)
    {
        if (*spec == '')
    }
}

int main()
{
    puts("Começando...");
    ft_printf("Esta é a minha %# c que achas");
    return 0;
}