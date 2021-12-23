#include <stdlib.h>
#include <stdio.h>
#define BRAINF(c) { \
char *p, *b, *u, *i;                   \
p = b = calloc(30000, 1);              \
u = i = c;                             \
while(*i != 0) {                       \
    if(*i == '>') p++;                 \
    if(*i == '<') p--;                 \
    if(*i == '+') ++*p;                \
    if(*i == '-') --*p;                \
    if(*i == '.') putchar(*p);         \
    if(*i == ',') *p = getchar();      \
    if(*i == '[') {                    \
        if(*p == 0) {                  \
            int m = 0;                 \
            while(*(++i) != 0) {       \
                if(*i == '[') m++;     \
                if(*i == ']') {        \
                    if(m == 0) break;  \
                    m--;               \
                }                      \
            }                          \
            if(*i == 0) goto end;      \
        }                              \
    }                                  \
    if(*i == ']') {                    \
        if(*p != 0) {                  \
            int m = 0;                 \
            while(--i != u-1) {       \
                if(*i == ']') m++;     \
                if(*i == '[') {        \
                    if(m == 0) break;  \
                    m--;               \
                }                      \
            }                          \
            if(i == u-1) goto end;    \
        }                              \
    }                                  \
    i++;                               \
}                                      \
end:                                   \
free(b);                               \
}
