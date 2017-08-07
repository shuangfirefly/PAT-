/*** 原创***/
/*** 题目网址： https://www.patest.cn/contests/pat-a-practise/1005 ***/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char Tmp='\0', Num[4] = {'\0'}, NumStr[11][6] = {"zero", "one", "two", "three", "four", "five",
    "six", "seven", "eight", "nine", "ten"};
    int Sum=0, i=0;

    while('\n'!=(Tmp=getchar()))
        Sum += (Tmp - '0');

    sprintf(Num, "%d", Sum);

    printf("%s", NumStr[Num[i]-'0']);
    for(i=1; i<strlen(Num); i++)
        printf(" %s", NumStr[Num[i]-'0']);

    return 0;
}
