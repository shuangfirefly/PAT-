/*** 原创***/
/*** 原题网址：https://www.patest.cn/contests/pat-a-practise/1002 ***/
/*** 用时 15分钟***/
/*** 使用字符串进行映射，可以少些很多代码~。😄***/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
    int i=0, TmpInt=0, K[2]= {0};
    double N[1001]= {0.00}, TmpDbl=0;

    scanf("%d", &K[0]);

    for(i=0; i<K[0]; i++)
    {
        scanf("%d", &TmpInt);
        scanf("%lf", &N[TmpInt]);
    }

    scanf("%d", &K[1]);
    K[0] += K[1];

    for(i=0; i<K[1]; i++)
    {
        scanf("%d", &TmpInt);
        scanf("%lf", &TmpDbl);
        if(fabs(N[TmpInt])>=1e-6)
            K[0] -= 1;
        N[TmpInt] += TmpDbl;
        if(fabs(N[TmpInt])<1e-6)
            K[0] -= 1;
    }
    printf("%d", K[0]);

    for(i=1000; i>=0; i--)
        if(fabs(N[i])>=1e-6)
            printf(" %d %.1f", i, N[i]);

    return 0;
}
