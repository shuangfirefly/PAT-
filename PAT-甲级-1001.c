/*** 原创***/
/*** 题目网址：https://www.patest.cn/contests/pat-a-practise/1001 ***/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
    char Num[11]= {'\0'};
    int a=0, b=0, i=0, Cnt=0, Flag=0;

    scanf("%d%d", &a, &b);

    a += b;
    if(a)
    {
        Flag = (a<0)?-1:1;
        for(Cnt=0, i=0; a; i++)
        {
            Num[Cnt++] = abs(a%10) + '0'-0;
            ///sprintf(Num+Cnt, "%d", abs(a%10)), Cnt++;
            a /= 10;
            if((0==(i+1)%3)&&i&&a)
                Num[Cnt++] = ',';
        }
        if(Flag<0)
            Num[Cnt++] = '-';
    }
    else
        printf("0");

    for(--Cnt; Cnt>=0; Cnt--)
        printf("%c", Num[Cnt]);

    return 0;
}
