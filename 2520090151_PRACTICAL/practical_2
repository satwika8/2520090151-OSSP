#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    int source, destination;
    char buffer[1024];
    ssize_t bytes_read, bytes_written;

    source = open("sample.txt", O_RDONLY);

    if (source == -1)
    {
        perror("Error opening source file");
        return 1;
    }

    destination = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);

    if (destination == -1)
    {
        perror("Error opening destination file");
        close(source);
        return 1;
    }

    while ((bytes_read = read(source, buffer, sizeof(buffer))) > 0)
    {
        bytes_written = write(destination, buffer, bytes_read);

        if (bytes_written != bytes_read)
        {
            perror("Error writing to destination file");
            close(source);
            close(destination);
            return 1;
        }
    }

    if (bytes_read == -1)
    {
        perror("Error reading source file");
    }

    close(source);
    close(destination);

    printf("File copied successfully.\n");

    return 0;
}
