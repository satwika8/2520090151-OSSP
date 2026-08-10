#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    pid_t pid;

    printf("Parent Process Started\n");
    printf("Parent PID: %d\n", getpid());

    pid = fork();

    if (pid < 0)
    {
        perror("fork failed");
        return 1;
    }

    if (pid == 0)
    {
        // Child process
        printf("\nChild Process Created\n");
        printf("Child PID: %d\n", getpid());
        printf("Parent PID of Child: %d\n", getppid());

        // Execute ls command
        execlp("ls", "ls", "-l", NULL);

        perror("exec failed");
        exit(1);
    }
    else
    {
        // Parent process
        printf("\nParent is waiting for child...\n");

        wait(NULL);

        printf("\nChild process completed.\n");
        printf("Parent process completed.\n");
    }

    return 0;
}
