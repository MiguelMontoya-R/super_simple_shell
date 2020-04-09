#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
/**
* split - splits string 
* @str: string to split
* Return: pointer to array of each word
*/
char **split(char *str, int n)
{ 
    char **array;
    char *token;
    int i = 0;

    if (str == NULL)
    {
        dprintf(STDERR_FILENO, "Anything\n");
        exit(98);
    }    
    array = malloc(sizeof(char) * n);
    if (array == NULL)
    {
        free(array);
        exit(98);
    }
    token = strtok(str, " \n");
    while (token)
    {
        array[i] = token;
        token = strtok(NULL,  " \n");
        i++;
    }
    array[i] = NULL;
    return (array);
}