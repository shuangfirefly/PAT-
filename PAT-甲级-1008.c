/*** 原创***/
/*** 题目网址： https://www.patest.cn/contests/pat-a-practise/1008 ***/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    int N=0, Start=0, Stop=0, i=0, Time=0;

    scanf("%d%d", &N, &Start);

    Time = Start * 6 + 5;
    for(i=1; i<N; i++)
    {
        scanf("%d", &Stop);
        if(Stop>Start)
            Time += ((Stop-Start)*6+5);
        else
            Time += (abs(Stop-Start)*4+5);
        Start = Stop;
    }

    printf("%d", Time);
    return 0;
}
