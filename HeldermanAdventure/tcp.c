#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <netinet/in.h>
#include "object.h"
#include "print.h"


// The assert() function will return the return value
// if the function's return value is not -1 else and error is printed
static int assert(const char *name, int retval)
{
    if (retval == -1) perror(name);
    return retval;
}

// setPort() will take the socket address object and the port number. 
// It will set the address family, host ip address, and the port number
static struct sockaddr *setPort(struct sockaddr_in *addr, uint16_t port)
{
    addr->sin_family = AF_INET;         // address family
    addr->sin_addr.s_addr = INADDR_ANY; // host ip address of server machine
    addr->sin_port = htons(port);       // changes port number into network byte order
    return (struct sockaddr *)addr;
}

// this function accepts the sockaddr_in object and port number
// it will create a socket, bind it to the addr object, and start
// listening to it
int tcpListen(struct sockaddr_in *addr, uint16_t port)
{
    int fd = assert("socket", socket(AF_INET, SOCK_STREAM, 0)); // create socket file descriptor and assert success
    if (fd != -1)
    {
        int opt = 1;
        // use setsockopt to set the options for the socket that was created
        // use bind to bind the sockaddr_in object and the socket file descriptor
        // use listen to pay attention to client connections for the socket and allow 3 in backlog
        if (-1 != assert("setsockopt", setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, (char *)&opt, sizeof opt)) &&
            -1 != assert("bind", bind(fd, setPort(addr, port), sizeof *addr)) &&
            -1 != assert("listen", listen(fd, 3)))
        {
            // use the printConsole() function to let the users know
            printConsole("Listening to port %u.\n", (unsigned int)port);
        }
        else
        {
            // if any of the above operations fail close the file descriptor
            close(fd);
            fd = -1;
        }
    }
    return fd;
}

// function takes in the socket and port number
// it wil close the socket and let it be known via console
void tcpClose(int fd, uint16_t port)
{
    // closes the socket file desriptor and prints it to console
    close(fd);
    printConsole("No longer lsitening to port %u.\n", (unsigned int)port);
}

// this function makes the program monitor the set of file descriptors
int tcpSelect(int nfds, fd_set *readfds)
{
    // checks to see if the select for all of the file descriptors is succesful
    return assert("select", select(nfds, readfds, NULL, NULL, NULL));
}

// this function if given the socket address object and file descriptor
// will wait until a connection is made and return the assert() bool
int tcpAccept(struct sockaddr_in *addr, int listener)
{
    // gets the length of the entire socket address object
    socklen_t len = sizeof *addr;
    // checks to see if the accept() function blcoks until a succesful connection is made
    return assert("accept", accept(listener, (struct sockaddr *)addr, &len));
}

// This functuion accepts the socket and then closes it
void tcpDisconnect(int fd)
{
    // checks to see if file descriptor is not faulty and the closes it
    // and reports it via console print operation
    if (fd != -1)
    {
        close(fd);
        printConsole("Socket %d disconnected.\n", fd);
    }
}

// function will take in the file descripto, data string , and data length
// it will write the string to the file descriptor based on length
void tcpSend(int fd, const char *data, int len)
{
    // will hold the number of bytes written
    int written; 

    // the while loop will keep writing to the file descriptor until all data
    // has been read and written
    while (len > 0 && ((written = write(fd, data, len)) >= 0 || errno == EINTR ))
    {
        if (written > 0)
        {
            // sets the pointer to 1 + the last read position
            data += written;
            // deceases the amount needed to be written
            len -= written;
        }
    }
}