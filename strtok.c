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
    
    array = malloc(sizeof(char *) * n);
    token = strtok(str, " ");
    while (token)
    {
        array[i] = token;
        token = strtok(NULL,  " ");
        i++;
    }
    array[i] = NULL;
    return (array);
}