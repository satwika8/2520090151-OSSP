#include <stdio.h>
#include <string.h>

int main()
{
    char command[100];

    printf("=====================================\n");
    printf("       Simple Shell Interactive      \n");
    printf("=====================================\n");

    while (1)
    {
        printf("myshell> ");

        if (fgets(command, sizeof(command), stdin) == NULL)
        {
            break;
        }

        command[strcspn(command, "\n")] = '\0';

        if (strcmp(command, "exit") == 0)
        {
            printf("Exiting shell...\n");
            break;
        }
        else if (strcmp(command, "hello") == 0)
        {
            printf("Hello! Welcome to the shell.\n");
        }
        else if (strcmp(command, "help") == 0)
        {
            printf("Available commands:\n");
            printf("  hello - Display greeting\n");
            printf("  help  - Display available commands\n");
            printf("  exit  - Exit the shell\n");
        }
        else if (strlen(command) == 0)
        {
            continue;
        }
        else
        {
            printf("Unknown command: %s\n", command);
        }
    }

    return 0;
}
