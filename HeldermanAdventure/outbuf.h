#include <stdarg.h>
#ifndef OUTBUF_H
#define OUTBUF_H

extern void outbufClear(void);
extern void outbufRewind(int len);
extern void outbufByte(char c);
extern void outbufBytes(const char *data, int length);
extern void outbufAsSpace(char c);
extern void outbufFormatVar(const char *format, va_list ap);
extern void outbufFormat(const char *format, ...);
extern bool outbufStartsWith(const char *prefix, int len);
extern bool outbufMove(int from, int to);
extern void outbufInsertString(int pos, const char *string);
extern void outbufInsertSpaces(int pos, const char *data, int len);
extern void outbufFlush(int fd);

#endif