#include <cstdio>
#include <cctype>
const int len=456733;
char buf[len],*cur(buf),*next(buf+1);
#define readBuf(){\
if(++cur==next)\
next=(cur=buf)+fread(buf,1,sizeof(buf),stdin);\
}
#define getInt(){\
int s(0);\
while(!isdigit(*cur))\
readBuf();\
while(isdigit(*cur)){\
s=s*10+*cur-48;\
readBuf();\
}\
}
