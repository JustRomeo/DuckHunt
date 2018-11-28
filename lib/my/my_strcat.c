/*
** EPITECH PROJECT, 2018
** my_strcat
** File description:
** Task 2 du jour 7 sur la lib
*/
#include <unistd.h>
#include <stdio.h>

void my_putchar(char c);

char *my_strcat(char *dest, char *src)
{
    int i = 0;
	int j = 0;
    int k = i + j;

    while (dest[j])
        j++;
    k = i + j;
	while (src[i]){
		dest[k] = src[i];
        i++;
        k = i + j;
    }
    k++;
    dest[k] = '\0';
    printf("return : %s\n", dest);
	return (dest);
}
