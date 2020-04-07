#include "header.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * 
 * main - check for split function
 * Return: always 0
*/
int main(void)
{
    int i = 0;
    int n;
    char **array;
    char *buffer = NULL;
    size_t buffsize = 0;

    printf("$ ");
    n = getline(&buffer, &buffsize, stdin);
    array = split(buffer, n);
    while (array[i])
    {
        printf("%d--> %s\n", n, array[i]);
        i++;
    }
    free(buffer);
    return (0);
}