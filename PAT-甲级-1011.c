/*** 原创***/
/*** 题目网址： https://www.patest.cn/contests/pat-a-practise/1011 ***/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    double Sum = 1.0, Max = 0.00, Temp=0.00;
    char Name[3] = {'\0'};
    int i=0, j=0, k=0, Flag=0;

    for(i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
        {
            scanf("%lf", &Temp);
            if(Temp-Max>1e-6)
            {
                Max = Temp;
                Flag++;
            }
        }
        if(1==Flag)
            Name[k++] = 'W';
        else if(2==Flag)
            Name[k++] = 'T';
        else if(3==Flag)
            Name[k++] = 'L';
        Sum *= Max;
        Flag=0, Max=0;
    }
    for(i=0; i<3; i++)
        printf("%c ", Name[i]);
    printf("%.2f", (Sum*0.65-1)*2);

    return 0;
}
