
/*** 原创***/
/*** 用时 1小时30分***/
/*** 主要思路，使用单向链表进行处理***/
/*** 我这种方法很复杂，准备采用 Zhaowang lynnprosper中提示的方法再做一次***/
/*** 题目网址： https://www.patest.cn/contests/pat-a-practise/1002 ***/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct LNode *PtrToNode;
struct LNode
{
    int exp;  ///指数
    double cft; /// 系数
    PtrToNode Next;
};
typedef PtrToNode PolyPtr;

int main(void)
{
    PolyPtr A=NULL, B=NULL, Tmp=NULL, TmpB=NULL;
    int i=0, K[2]= {0};

    Tmp = A = (PolyPtr) calloc(1, sizeof(struct LNode));
    B = (PolyPtr) calloc(1, sizeof(struct LNode));

    A->cft=0.0, A->exp=-1, A->Next=NULL;
    B->cft=0.0, B->exp=0, B->Next=NULL;

    scanf("%d", &K[0]);
    for(i=0; i<K[0]; i++)
    {
        Tmp->Next = (PolyPtr) calloc(1, sizeof(struct LNode));
        Tmp = Tmp->Next, Tmp->Next = NULL;
        scanf("%d%lf", &Tmp->exp, &Tmp->cft);
    }
    Tmp = A->Next;

    scanf("%d", &K[1]);
    K[0] += K[1];
    for(i=0; i<K[1]; i++)
    {
        scanf("%d%lf", &B->exp, &B->cft);
        while((Tmp->exp > B->exp)&&(NULL!=Tmp->Next))
            Tmp = Tmp->Next;
        if(Tmp->exp > B->exp)
        {
            Tmp->Next = (PolyPtr) calloc(1, sizeof(struct LNode));
            Tmp=Tmp->Next;
            Tmp->cft = B->cft, Tmp->exp=B->exp, Tmp->Next=NULL;
        }
        else if(Tmp->exp == B->exp)
        {
            Tmp->cft += B->cft;
            if(fabs(Tmp->cft)<1e-6)
                K[0] -= 2;
            else
                K[0] -= 1;
        }
        else
        {
            TmpB=(PolyPtr) calloc(1, sizeof(struct LNode));
            TmpB->cft=Tmp->cft, TmpB->exp=Tmp->exp, TmpB->Next=Tmp->Next;

            Tmp->cft=B->cft, Tmp->exp=B->exp;
            Tmp->Next=(PolyPtr) calloc(1, sizeof(struct LNode));
            Tmp->Next->cft=TmpB->cft, Tmp->Next->exp=TmpB->exp, Tmp->Next->Next=TmpB->Next;
            free(TmpB);
        }
    }

    Tmp = A->Next;
    printf("%d", K[0]);

    for(; NULL!=Tmp; )
    {
        if(fabs(Tmp->cft)>=1e-6)
            printf(" %d %.1f", Tmp->exp, Tmp->cft);
        TmpB = Tmp, Tmp=Tmp->Next;
        free(TmpB);
    }
    free(A);
    free(B);

    return 0;
}
