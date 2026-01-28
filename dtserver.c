

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <arpa/inet.h>

int main() {
    int server_fd, client_fd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len;
    char buffer[100];
    time_t current_time;

    
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        perror("Socket creation failed");
        exit(1);
    }

 
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(8080);


    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        exit(1);
    }


    listen(server_fd, 5);
    printf("TCP Date-Time Server started...\n");

    addr_len = sizeof(client_addr);
    client_fd = accept(server_fd, (struct sockaddr *)&client_addr, &addr_len);

    if (client_fd < 0) {
        perror("Accept failed");
        exit(1);
    }


    time(&current_time);
    strcpy(buffer, ctime(&current_time));


    send(client_fd, buffer, strlen(buffer), 0);

    printf("Date and Time sent to client\n");

    close(client_fd);
    close(server_fd);

    return 0;
}
















