#include <stdio.h>
#include <stdlib.h>
#include "header.h"
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
/**
 * main - run some commands with full PATH
 *
 * Return: always 0
 */
int main(void)
{
	char *buffer = NULL;
	size_t buffsize = 0;
	char *array[1024];
	char *token;
	int i = 0;
	pid_t child_pid;
	int status;

	printf("#cisfun$ ");
	if (getline(&buffer, &buffsize, stdin) == -1)
		perror("Error");
	token = strtok(buffer, " \n");
	while (token)
	{
		array[i] = token;
		token = strtok(NULL, " \n");
		i++;
	}
	array[i] = NULL;
	child_pid = fork();
	if (child_pid == 0)
	{
		if (execve(array[0], array, NULL) == -1)
			perror("Error");
	}
	else
		wait(&status);

	free(buffer);
	return (0);
}
