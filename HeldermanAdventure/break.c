#include <stdbool.h>
#include <string.h>
#include <signal.h>

static volatile sig_atomic_t done = 0;

// this function will be called and set done when a breakInit signal is called
static void handler(int signum)
{
    done = signum;
}

// this function will watch for SIGINT and SIGTERM errors and sto the program
void breakInit(void)
{
    struct sigaction action;
    memset(&action, 0, sizeof(action));
    action.sa_handler = handler;
    sigaction(SIGINT, &action, NULL);
    sigaction(SIGTERM, &action, NULL);

}

// this function will be used by the program to see if it should end
// if ever returns false then the program will exit
bool breakTest(void)
{
    return done == 0;
}


// this function will return the signal number indicator "done"
int breaksSignalNumber(void)
{
    return done;
}