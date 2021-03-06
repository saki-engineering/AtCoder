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
    int N,K;
    scanf("%d%d",&N,&K);

    //A[0]~A[N-1]に格納する
    int* A;
    NEW(A,N);
    for(int i=0;i<N;i++){
        scanf("%d",&A[i]);
    }
    qsort(A,N,sizeof(int),asc);

    int* B;
    NEW(B,N);
    int block=0;
    int tmp=1;
    if(N==1){
        block=1;
        B[0]=1;
    }
    else{
        for(int i=1;i<N;i++){
            if(A[i]==A[i-1]) tmp++;
            else{
                B[block]=tmp;
                tmp=1;
                block++;
            }
        }
        B[block]=tmp;
        block++;
    }
    qsort(B,block,sizeof(int),asc);

    int ans=0;
    for(int i=0;i<(block-K);i++){
        ans+=B[i];
    }
    printf("%d\n",ans);

    return 0;
}