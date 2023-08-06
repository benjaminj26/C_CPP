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
    int listenfd;
    memset((void *)&server, 0, sizeof(server));
    int port = 15000;
    
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    server.sin_addr.s_addr = htonl(INADDR_ANY);

    listenfd = socket(AF_INET, SOCK_STREAM, 0);

    if (listenfd < 0)
    {
        printf("Failed to create socket\n");
        return 1;
    }

    int val = bind(listenfd, (struct sockaddr *)&server, (socklen_t)sizeof(server));

    if (val < 0)
    {
        printf("Failed to bind socket\n");
        return 1;
    }

    val = listen(listenfd, 10);

    if (val < 0)
    {
        printf("Failed to listen on port %d\n", port);
        return 1;
    }

    printf("Listening on port %d\n", port);

    int connfd;
    struct sockaddr_in client;
    char buffer[300];
    
    memset(&client, 0, sizeof(client));
    socklen_t addrlen = sizeof(client);
    connfd = accept(listenfd, (struct sockaddr *)&client, &addrlen);
    while (1)
    {
        memset(buffer, 0, sizeof(buffer));
        read(connfd, buffer, sizeof(buffer));

        printf("Message from client:\n%s\n", buffer);

        memset(buffer, 0, sizeof(buffer));
        sprintf(buffer, "Connection Accepted by Server");
        write(connfd, buffer, strlen(buffer));
    }

    return 0;
}