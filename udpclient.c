#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main() {
    int sockfd;
    char buffer[BUFFER_SIZE];
    struct sockaddr_in server_addr;
    socklen_t addr_len = sizeof(server_addr);

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("Socket failed");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    while (1) {

        printf("Enter message (type 'exit' to quit): ");
        fgets(buffer, BUFFER_SIZE, stdin);

        if (strncmp(buffer, "exit", 4) == 0)
            break;
    
        sendto(sockfd, buffer, strlen(buffer), 0,
               (struct sockaddr *)&server_addr, addr_len);

        int n = recvfrom(sockfd, buffer, BUFFER_SIZE, 0,
                         NULL, NULL);
        buffer[n] = '\0';

        printf("Server reply: %s\n", buffer);
    }

    close(sockfd);
    return 0;
}

