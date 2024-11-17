#include <stdbool.h>
#include <stdio.h>
#include "object.h"
#include "telnet.h"
#include "client.h"

// limit the number of possible clients as a macro
#define MAX_CLIENTS 30

// intitialize an array of clients
static CLIENT clients[MAX_CLIENTS];


// this function will loop through all possible clients and 
// set them to be empty intitally
void clientInit(void)
{
    int i;
    for (i = 0; i < MAX_CLIENTS; i++)
    {
        clients[i].fd = -1;
    }
}

// Thsi function if given the speciifc client 
// will return a pointer to the speciic client in the array
CLIENT *clientGet(int i)
{
    return i < MAX_CLIENTS ? clients + i : NULL;
}

// This function when called will go through the array of clients
// and finds the first open array slot for a newly connected client
CLIENT *clientGetFree(void)
{
    CLIENT *client;
    int i;
    // loop through teh clients array for an avalable client slot
    for (i = 0; (client = clientGet(i)) != NULL && client->fd != -1; i++)
    {

    }
    return client;
}

