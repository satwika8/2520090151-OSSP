#include <stdio.h>
#include <unistd.h>
#include <termios.h>
#include <string.h>

int main()
{
    struct termios oldt, newt;
    char ch;
    char buffer[100];
    int index = 0;

    printf("=====================================\n");
    printf("       Keyboard Input Program        \n");
    printf("=====================================\n");
    printf("Type characters. Press Backspace to delete.\n");
    printf("Press Enter to process the command.\n");
    printf("Type exit to quit.\n\n");

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;

    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    while (1)
    {
        printf("input> ");
        fflush(stdout);

        index = 0;

        while (1)
        {
            ch = getchar();

            if (ch == '\n')
            {
                buffer[index] = '\0';
                printf("\n");

                if (index == 0)
                {
                    printf("Empty input.\n");
                }
                else if (strcmp(buffer, "exit") == 0)
                {
                    printf("Exiting...\n");

                    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
                    return 0;
                }
                else
                {
                    printf("Command entered: %s\n", buffer);
                }

                break;
            }

            if (ch == 127 || ch == '\b')
            {
                if (index > 0)
                {
                    index--;
                    printf("\b \b");
                    fflush(stdout);
                }
            }
            else if (index < 99)
            {
                buffer[index++] = ch;
                putchar(ch);
                fflush(stdout);
            }
        }
    }

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);

    return 0;
}
