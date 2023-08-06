#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>

int main()
{
    struct sockaddr_in server;
    int connfd;
    memset((void *)&server, 0, sizeof(server));
    int port = 15000;
    
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    inet_pton(AF_INET, "127.0.0.1", &server.sin_addr);

    connfd = socket(AF_INET, SOCK_DGRAM, 0);

    while (1)
    {
        char buffer[200];
        memset(buffer, 0, sizeof(buffer));
        char *string = NULL;
        printf("Enter a string: ");
        size_t len = 0;

        getline(&string, &len, stdin);

        sendto(connfd, string, len, 0, (struct sockaddr*)&server, sizeof(server));

        socklen_t size = sizeof(server);
        recvfrom(connfd, buffer, sizeof(buffer), 0, (struct sockaddr*)&server, &size);
        printf("Message from Server:\n%s\n", buffer);
        free(string);
    }
    return 0;
}