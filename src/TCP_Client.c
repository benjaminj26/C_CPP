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
    int connfd, port = 15000;
    memset((void *)&server, 0, sizeof(server));
    
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    inet_pton(AF_INET, "127.0.0.1", &server.sin_addr);

    connfd = socket(AF_INET, SOCK_STREAM, 0);

    if (connfd < 0)
    {
        printf("Unable to create socket\n");
        return 1;
    }

    int val;
    val = connect(connfd, (struct sockaddr *)&server, (socklen_t)sizeof(server));

    if (val < 0)
    {
        printf("Failed to connect to server\n");
        return 1;
    }
    while (1)
    {
        size_t buff_len = 0;

        char *buffer = NULL;
        printf("Enter a string: ");
        getline(&buffer, &buff_len, stdin);

        write(connfd, buffer, strlen(buffer));
        free(buffer);
        buffer = NULL;
        
        char receive_buff[200];
        memset(receive_buff, 0, sizeof(receive_buff));
        
        read(connfd, receive_buff, sizeof(receive_buff));

        printf("Message from server:\n%s\n", receive_buff);
    }

    close(connfd);

    return 0;
}