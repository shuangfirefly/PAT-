/*** 原创 ***/

#include <stdio.h>
#include <math.h>

int main(void)
{
    char Num[11]= {'\0'};
    int a=0, b=0, i=0, Cnt=0, Flag=0;

    scanf("%d%d", &a, &b);

    a += b;
    if(a)
    {
        Flag = (a<0)?-10:10;
        for(Cnt=0, i=0; a; )
        {
            Num[Cnt++] = abs(a%Flag) + '0'-0;
            ///sprintf(Num+Cnt, "%d", abs(a%Flag)), Cnt++;
            i++;
            a /= 10;
            if((0==i%3)&&i&&a)
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
