#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define NEW(p,n){p=malloc((n)*sizeof(p[0]));if(p==NULL){printf("not enough memory\n");exit(1);};}
//pの型の変数n個の要素分のメモリを確保し、そのアドレスをpに代入するマクロ

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define SWAP(type, x, y) do { type tmp = x; x = y; y = tmp; } while (0)

#define MOD 1000000007 

//昇順
int asc(const void* a, const void* b){
    return *(int*)a-*(int*)b;
}

int main(void){
    int N,M;
    scanf("%d%d",&N,&M);

    int* A;
    NEW(A,M);
    int N1=0;
    int* B;
    NEW(B,M)
    int N2=0;
    for(int i=0;i<M;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        if(a==1){
            A[N1]=b;
            N1++;
        }
        if(b==N){
            B[N2]=a;
            N2++;
        }
    }
    qsort(A,N1,sizeof(int),asc);
    qsort(B,N2,sizeof(int),asc);

    int flg=0;
    int s=0;
    int t=0;
    while(s<N1 && t<N2){
        if(A[s]==B[t]){
            flg=1;
            break;
        }
        else if(A[s]<B[t]) s++;
        else t++;
    }

    if(flg) printf("POSSIBLE\n");
    else printf("IMPOSSIBLE\n");

    return 0;
}