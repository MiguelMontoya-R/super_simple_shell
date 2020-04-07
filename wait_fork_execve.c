#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
/**
 * 
 * 
 */
int main(void)
{
    char *argv[] = {"/bin/ls", "-l", "/tmp/", NULL};
    pid_t child_pid;
    pid_t parent_pid;
    int i = 0;
    int status;

    while (i < 5)
    {
        child_pid = fork();
        if (child_pid == -1)
        {
            perror("Error: ");
            return (1);
        }
        if (child_pid == 0)
	{
		if (execve(argv[0], argv, NULL) == -1)
		{
			perror("Error:");
		}

		printf("Executing fork\n");
	}
        else
        {
            wait(&status);
            printf("Waiting proccess passed\n");
        }
	parent_pid = getppid();            
        printf("parent-> %u and child-> %u\n", parent_pid, child_pid);
        i++;
    }
    return(0);
}
