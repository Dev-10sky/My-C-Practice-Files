#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>
#include <netinet/in.h>
#include "break.h"
#include "object.h"
#include "print.h"
#include "outbuf.h"
#include "telnet.h"
#include "client.h"
#include "tcp.h"

// define a random port macro
#define PORT 18812

void server(void (*action)(char *, int))
{
    CLIENT * client;
    int i;
    struct sockaddr_in addres;
    int listener = tcpListen(&addres, PORT);
    if (listener == -1)
    {
        return;
    }


    for (clientInit(), breakInit(); breakTest();)
    {
        fd_set fds;
        int fd = listener;
        FD_ZERO(&fds);
        FD_SET(listener, &fds);
        for (i = 0; (client = clientGet(i)) != NULL; i++)
        {
            if (client->fd != -1)
            {
                FD_SET(client->fd, &fds);
            }
            if (client->fd > fd)
            {
                fd = client->fd;
            }
        }
        if (tcpSelect(fd + 1, &fds) == -1)
        {
            break;
        }

        if (FD_ISSET(listener, &fds))
        {
            fd = tcpAccept(&addres, listener);
            if (fd == -1)
            {
                break;
            }
            printConsole("Socket %d connected.\n", fd);
            outbufClear();
            telnetConfigure();
            outbufFormat("Welcome to the Little Cave Adventure.\n");
            client = clientGetFree();
            if (client != NULL)
            {
                client->fd = fd;
                client->obj = nobody;
                telnetInit(&client->inbuf);
                telnetAppendPrompt(&client->inbuf);
                outbufFlush(fd);
            }
            else
            {
                outbufFormat("The sockets are occupied, try to connect later.\n");
                outbufFlush(fd);
                tcpDisconnect(fd);
            }
        }
        for (i = 0; breakTest() && (client = clientGet(i)) != NULL; i++)
        {
            if (FD_ISSET(client->fd, &fds))
            {
                static char buffer[1024];
                int len = read(client->fd, buffer, sizeof buffer);
                if (len > 0)
                {
                    player = client->obj;
                    printSetCurrent(client->fd);
                    telnetParse(&client->inbuf, client->fd, action, buffer, len);
                    if (player != client->obj)
                    {
                        printConsole("Socket %d is %s.\n", fd, player->description);
                        client->obj = player;
                    }
                }
                else if (len == 0)
                {
                    tcpDisconnect(client->fd);
                    client->fd = -1;
                }
            }
        }
    }
    printConsole("Interrupted by signal %d.\n", breaksSignalNumber());
    for (i = 0; (client = clientGet(i)) != NULL; i++)
    {
        tcpDisconnect(client->fd);
    }
    tcpClose(listener, PORT);
}