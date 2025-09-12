#include <stdio.h>
#include <fcntl.h>      7
#include <unistd.h>     
#include <stdlib.h>     

int main() {
    int source_fd, dest_fd;   
    char buffer[1024];
    ssize_t bytesRead;

   
    source_fd = open("source.txt", O_RDONLY);
    if (source_fd < 0) {
        perror("Error opening source file");
        exit(1);
    }

    dest_fd = open("destination.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (dest_fd < 0) {
        perror("Error opening/creating destination file");
        close(source_fd);
        exit(1);
    }

    while ((bytesRead = read(source_fd, buffer, sizeof(buffer))) > 0) {
        if (write(dest_fd, buffer, bytesRead) != bytesRead) {
            perror("Error writing to destination file");
            close(source_fd);
            close(dest_fd);
            exit(1);
        }
    }

    if (bytesRead < 0) {
        perror("Error reading source file");
    }

    printf("File copied successfully!\n");

    close(source_fd);
    close(dest_fd);

    return 0;
}

