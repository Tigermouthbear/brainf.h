#include <stdlib.h>
#include <stdio.h>
#define BRAINF(c){char*p,*b,*u,*i;p=b=calloc(30000,1);u=i=c;while(*i){int m=0;if(*i==62)p++;if(\
*i==60)p--;if(*i==43)++*p;if(*i==45)--*p;if(*i==46)putchar(*p);if(*i==44)*p=getchar();if(*i==91\
&&!*p){while(*(++i)!=0){if(*i==91)m++;if(*i==93&&!m--)break;}if(!*i)goto end;}if(*i==93&&*p){wh\
ile(--i!=u-1){if(*i==93)m++;if(*i==91&&!m--)break;}if(i==u-1)goto end;}i++;}end:free(b);}
