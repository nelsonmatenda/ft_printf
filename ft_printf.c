/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 13:00:08 by nfigueir          #+#    #+#             */
/*   Updated: 2024/05/27 13:24:55 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int     ft_print(const char *fmt);

int	ft_printf(const char *first_arg, ...)
{
	// FAZER UM LOOP QUE VAI CHECAR CADA CARACTER CASO ENCONTRE
    // UM ESPECIFICADOR (%) CHAMO UMA FUNCAO QUE FAÇA O PARSING
    va_list all_arg;
    int nbr_char_printed;
    int i;
    
    va_start(all_arg, first_arg);
    i = 0;
    nbr_char_printed = 0;
    while (first_arg[i])
    {
        if (first_arg[i] == '%')
        {
            // fazer alguma parsing
            nbr_char_printed += ft_call_prints(&first_arg[++i]); // TODO: fazer a funcao
            i++;
        }
        else
            //nbr_char_printed += ft_putchar_fd(first_arg[i], 1);
        i++;
    }
    va_end(all_arg);
    return (nbr_char_printed);
}

int     ft_call_prints(const char *fmt)
{
    char   *flag;
    char    spec[9];
    int i;
    
    i = 0;
    flag = "-+ #0";
    spec[] = ft_memchr("cspdiuxX%", *fmt, ft_strlen)
    while (!spec)
    {
        if (ft_memchr(flag, *fmt, ft_strlen(flag)))
        {
            ft_set_flag(); // TODO: uma fun
        }
        else {
            printf("nao cheguei %i", i);
        }
        fmt++;
        spec =  ft_memchr("cspdiuxX%", *fmt, ft_strlen);
    }
    return (1);        
}

int main()
{
    puts("Começando...");
    ft_printf("Esta é a minha %# c que achas");
    return 0;
}