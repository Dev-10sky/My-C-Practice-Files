#include <ctype.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <netinet/in.h>
#include "tcp.h"

// the maximum length of any data in the out buffer
#define MAX_LEN 4095

static int outbufLen;
static char outbufData[MAX_LEN + 1];

// function will return a character if it's a space else return a whitespace
static int asSpace(int c)
{
    return isspace(c) ? c : ' ';
}

// this function will reset the out buffer to empty
void outbufClear(void)
{
    outbufLen = 0;
}

// this function will return the out buffer to a previous position
void outbufRewind(int len)
{
    outbufLen -= len;
}

// thsi function will add the a new character to the out buffer
void outbufByte(char c)
{
    if (outbufLen < MAX_LEN)
    {
        outbufData[outbufLen++] = c;
    }
}

// this function will add data to the out buffer by loopinng through it
void outbufBytes(const char *data, int length)
{
    for (; length > 0; length--)
    {
        outbufByte(*data++);
    }
}

// this function will add a space to the out buffer
void outbufAsSpace(char c)
{
    outbufByte(asSpace(c));
}

void outbufFormatVar(const char *format, va_list ap)
{
    // get the pointer to write to the out buffer
    char *ptr = outbufData + outbufLen;
    outbufLen +=  vsnprintf(ptr, sizeof outbufData - outbufLen, format, ap);
    if (outbufLen > MAX_LEN)
    {
        outbufLen = MAX_LEN;
    }
    while (outbufLen < MAX_LEN && (ptr = strchr(ptr, '\n')) != NULL)
    {
        memmove(ptr + 1, ptr, outbufData + ++outbufLen - ptr);
        *ptr = '\r';
        ptr += 2;
    }
}


void outbufFormat(const char *format, ...)
{
    va_list ap;
    va_start(ap, format);
    outbufFormatVar(format, ap);
    va_end(ap);
}

// this function checks to see if the prefix is at the start of the out buffer
bool outbufStartsWith(const char *prefix, int len)
{
    return outbufLen >= len && strncmp(outbufData, prefix, len) == 0;
}

// this function will copy the chars from "from" to the "to" position
bool outbufMove(int from, int to)
{
    outbufLen += to - from;
    if (outbufLen > MAX_LEN)
    {
        outbufLen = MAX_LEN;
    }
    if (to < outbufLen)
    {
        memmove(outbufData + to, outbufData + from, outbufLen - to);
    }
    return to <= outbufLen;
}

// this function will copy the chars in string to the out buffer
void outbufInsertString(int pos, const char *string)
{
    int len = strlen(string);
    if (outbufMove(pos, pos + len))
    {
        strncpy(outbufData + pos, string, len);
    }
}

// this function will insert spaces in the out buffer of size length
void outbufInsertSpaces(int pos, const char *data, int len)
{
    if (outbufMove(pos, pos + len))
    {
        for (int i = 0; i < len; i++)
        {
            outbufData[pos+i] = asSpace(data[i]);
        }
    }
}

// this function will send the current out buffer to the socket file descriptor
void outbufFlush(int fd)
{
    tcpSend(fd, outbufData, outbufLen);
}