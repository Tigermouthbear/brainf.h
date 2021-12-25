#include <stdlib.h>
#include <stdio.h>
#define BRAINF(c) {                    \
char *p, *b, *u, *i;                   \
p = b = calloc(30000, 1);              \
u = i = c;                             \
while(*i) {                            \
    int m = 0;                         \
    if(*i == '>') p++;                 \
    if(*i == '<') p--;                 \
    if(*i == '+') ++*p;                \
    if(*i == '-') --*p;                \
    if(*i == '.') putchar(*p);         \
    if(*i == ',') *p = getchar();      \
    if(*i == '[' && !*p) {             \
        while(*(++i) != 0) {           \
            if(*i == '[') m++;         \
            if(*i == ']' && !m--)      \
                break;                 \
        }                              \
        if(!*i) goto end;              \
    }                                  \
    if(*i == ']' && *p) {              \
        while(--i != u-1) {            \
            if(*i == ']') m++;         \
            if(*i == '[' && !m--)      \
                break;                 \
        }                              \
        if(i == u-1) goto end;         \
    }                                  \
    i++;                               \
}                                      \
end:                                   \
free(b);                               \
}
