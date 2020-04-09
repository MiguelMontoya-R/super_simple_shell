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
	char **token;
	pid_t child_pid;
	int n;
	int i = 0;
	int status;

	printf("#cisfun$ ");
	while ((n = getline(&buffer, &buffsize, stdin)) != -1)
	{
		token = split(buffer, n);
		while(token[i])
		{
			printf("%s\n", token[i]);
			i++;
		}
		child_pid = fork();
		if (child_pid == 0)
		{
			if (execve(token[0], token, NULL) == -1)
				perror("Error");
		}
		else
			wait(&status);
		
		free(token);
		free(buffer);
		printf("#cisfun$ ");
	}
	return (0);
}
