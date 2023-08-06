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

    listenfd = socket(AF_INET, SOCK_DGRAM, 0);

    int val = bind(listenfd, (struct sockaddr *)&server, sizeof(server));
    if (val < 0)
    {
        printf("Failed to bind\n");
        return 1;
    }

    printf("Listening on port %d\n", port);

    while (1)
    {
        struct sockaddr_in client;
        memset(&client, 0, sizeof(client));
        char buffer[200];
        memset(buffer, 0, sizeof(buffer));
        socklen_t len = sizeof(client);
        recvfrom(listenfd, buffer, sizeof(buffer), 0, (struct sockaddr *)&client, &len);

        printf("Message from client:\n%s\n", buffer);

        socklen_t size = sizeof(client);
        memset(buffer, 0, sizeof(buffer));memset(buffer, 0, sizeof(buffer));
        sprintf(buffer, "Connection Accepted by Server");
        sendto(listenfd, buffer, sizeof(buffer), 0, (struct sockaddr *)&client, size);
    }

    return 0;
}