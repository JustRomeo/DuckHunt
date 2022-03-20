/*
** EPITECH PROJECT, 2018
** my_printf
** File description:
** header
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

void my_putchar(char c);
int my_put_nbr(int nb);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_getnbr(char const *str);
char *my_strcpy(char *dest, char const *src);
int my_strcmp(char const *s1, char const *s2);
char *my_revstr(char *str);
char *my_strcat(char *dest, char const *src);
char *my_putint_in_str(int z);
int my_getlong(char const *str);
int my_put_long(long nb);
int my_getdouble(char *str);
int my_put_double(int nbr);
char *my_hexa(int nbr);

void case_flag(va_list list, char flag, char str)
{
    switch (flag) {
    case '%': my_putchar('%'); break;
    case 'b': ; break; //binary base;
    case 'c': my_putchar(va_arg(list, int)); break;
    case 'd': my_put_nbr(va_arg(list, int)); break;
    case 'f': my_put_double(va_arg(list, double)); break;
    case 'l': my_put_long(va_arg(list, long)); break;
        //case 'n': my_put_nbr(my_strlen(str)); break; //number of bits return by printf
    case 'o': ; break; //octal integer
    case 'p': ; break; //pointer
    case 's': my_putstr(va_arg(list, char *)); break;
    case 'u': my_put_nbr(va_arg(list, unsigned int)); break;
    case 'x': my_putstr(my_hexa(va_arg(list, int))); break;
    case 'S': ; break; //str + char spéciaux
    }
}

int my_printf(char *str, ...)
{
    int i = 0;
    va_list list;

    va_start(list, str);

    while (str[i] != '\0') {
        if (str[i] == '%') {
            case_flag(list, str[i + 1], str);
            i++;
        }
        else
            my_putchar(str[i]);
        i++;
    }
    return (0);
}
