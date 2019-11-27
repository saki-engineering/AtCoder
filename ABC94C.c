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
    int N;
    scanf("%d",&N);

    int* X;
    NEW(X,N);
    for(int i=0;i<N;i++){
        scanf("%d",&X[i]);
    }

    int* Y;
    NEW(Y,N);
    for(int i=0;i<N;i++) Y[i]=X[i];
    qsort(Y,N,sizeof(int),asc);

    for(int i=0;i<N;i++){
        if(X[i]>=Y[N/2]) printf("%d\n",Y[N/2-1]);
        else printf("%d\n",Y[N/2]);
    }

    return 0;
}

//特に困った事なし