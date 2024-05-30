/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 13:00:08 by nfigueir          #+#    #+#             */
/*   Updated: 2024/05/30 13:22:08 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int    ft_call_prints(const char *fmt, t_data d);

int	ft_printf(const char *first_arg, ...)
{
    t_data  data;
    int i;

    va_start(data.ap, first_arg);
    ft_init_data(data, first_arg);
    i = 0;
    while (first_arg[i])
    {
        if (first_arg[i] == '%')
            ft_call_prints(&first_arg[++i], data); // TODO: fazer a funcao
        else
        {
            data.nbr_char_printed += ft_putchar(first_arg[i]);
        }
        i++;
    }
    va_end(data.ap);
    return (data.nbr_char_printed);
}

int     ft_call_prints(const char *fmt, t_data d)
{
    if (ft_strchr(d.f.specifier, *fmt))
        printf("existe um especificador");
    else
    {
        if (*fmt == 'c')
            d.nbr_char_printed += ft_putchar(va_arg(d.ap, int));
        else if (*fmt == 's')
            d.nbr_char_printed += ft_putstr(va_arg(d.ap, char *));
        else if (*fmt == 'p')
        {
            if (va_arg(d.ap, void *))
                d.nbr_char_printed += ft_putaddress(va_arg(d.ap, void *));
            d.nbr_char_printed += ft_putstr("0x0");
        }
        else if (*fmt == 'd' || *fmt == 'i')
            d.nbr_char_printed += ft_putnbr(va_arg(d.ap, int));
        else if (*fmt == 'u')
            d.nbr_char_printed += ft_putunsigned(va_arg(d.ap, unsigned int));
        else if (*fmt == 'x' || *fmt == 'X')
            d.nbr_char_printed += ft_puthexa(va_arg(d.ap, unsigned int), *fmt);
        else if (*fmt == '%')
            d.nbr_char_printed += ft_putchar('%');
        else
            return (-1);//printf("Nenhum specificador"); // TODO: apagar
    }
    return (0);   
}

// char ft_find_spec(const char fmt)
// {
//     char *spec;
//     char    *flags;

//     flags = ""
//     spec = ft_memchr(cspdiuxX%);
//     while (!spec)
//     {
//         if (*spec == '')
//     }
// }

int main()
{
    puts("Começando...");
    ft_printf("Esta é a minha %s que achas", "printf");
    return 0;
}