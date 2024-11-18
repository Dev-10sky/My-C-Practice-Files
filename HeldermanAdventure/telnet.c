#include <stdbool.h>
#include <stdio.h>
#include "outbuf.h"
#include "telnet.h"

// the prompt string for every command line in client view
static const char prompt[] = "--> ";

// this function sets default values for an INBUF object
void telnetInit(INBUF *inbuf)
{
    inbuf->iac = false;
    inbuf->negotiate = 0;
    inbuf->index = 0;
}

// this function will send telnet commands upon intial client connection
void telnetConfigure(void)
{
    // first config line will command no linemode usage
    // second config line will tell client that local echo is not needed
    static const char config[] = 
    {
        '\xFF', '\xFD', 34, '\xFF', '\xFA', 34, 1, 0, '\xFF', '\xF0',
        '\xFF', '\xFB', 1
    };
    outbufBytes(config, sizeof config);
}

// this function will use whitespaces to get ridf of the current telnet text line
void telnetInsertSpaces(INBUF *inbuf)
{
    outbufInsertString(0, "\r\r");
    outbufInsertSpaces(1, inbuf->data, inbuf->index);
    outbufInsertSpaces(1, prompt, sizeof prompt - 1);
}

// this function undoes the work of telnetInsertSpaces
void telnetDeleteSpaces(INBUF *inbuf)
{
    outbufMove(inbuf->index + sizeof prompt + 1, 0);
}

// this function prints out the prompt and words written after the --> symbol
void telnetAppendPrompt(INBUF *inbuf)
{
    outbufBytes(prompt, sizeof prompt - 1);
    outbufBytes(inbuf->data, inbuf->index);
}

// this function undoes the telnetAppendPrompt() effects
void telnetDeletePrompt(INBUF *inbuf)
{
    outbufRewind(inbuf->index + sizeof prompt - 1);
}

// this function will parse the input from the clients
extern void telnetParse(INBUF *inbuf, int fd, void (*action)(char *, int),
                        const char *data, int length)
{
    outbufClear();
    for (int i = 0; i < length; i++)
    {
        int c = data[i];
        if (c == '\xFF' || inbuf->iac)
        {
            // this will check for telnet commands
            // and use the iac and negotiate attributes to skip them
            if (c == '\xF0' || inbuf->negotiate != '\xFA')
            {
                inbuf->negotiate = c;
            }
            inbuf->iac = !inbuf->iac;
        }
        else if (inbuf->negotiate >= '\xFA' && inbuf->negotiate <= '\xFE')
        {
            // this will check for telnet commands
            // and use the iac and negotiate attributes to skip them
            if (inbuf->negotiate != '\xFA')
            {
                inbuf->negotiate = 0;
            }
        }
        else if (c == '\r')
        {
            // this will execute client's command when enter is pressed
            outbufFormat("\n");
            outbufFlush(fd);
            inbuf->data[inbuf->index] = '\0';
            (*action)(inbuf->data, sizeof inbuf->data);
            inbuf->index = 0;
            outbufClear();
            outbufBytes(prompt, sizeof prompt - 1);
        }
        else if (c == '\b' || c == '\x7F')
        {
            // when backspace or delete is pressed the last character is deleted
            if (inbuf->index > 0)
            {
                outbufByte('\b');
                outbufAsSpace(inbuf->data[--inbuf->index]);
                outbufByte('\b');
            }
        }
        else if (c >= ' ' && c < '\x7F')
        {
            // for ascii characters they will be stored in the inbuff 
            if (inbuf->index < sizeof inbuf->data - 1)
            {
                outbufByte(c);
                inbuf->data[inbuf->index++] = c;
            }
        }
    }
    outbufFlush(fd);
}