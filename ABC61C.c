#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define NEW(p,n){p=malloc((n)*sizeof(p[0]));if(p==NULL){printf("not enough memory\n");exit(1);};}
//pの型の変数n個の要素分のメモリを確保し、そのアドレスをpに代入するマクロ

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define SWAP(type, x, y) do { type tmp = x; x = y; y = tmp; } while (0)

#define MOD 1000000007 

typedef struct{
    int a;
    long b;
}data;

//昇順
int asc(const void* a, const void* b){
    data p=*(data*)a;
    data q=*(data*)b;
    if((p.a-q.a)>0) return 1;
    else if((p.a-q.a)<0) return -1;
    else return 0;
}

int main(void){
    int N;
    long K;
    scanf("%d%ld",&N,&K);

    //A[0]~A[N-1]に格納する
    data* A;
    NEW(A,N);
    for(int i=0;i<N;i++){
        scanf("%d %ld",&A[i].a, &A[i].b);
    }
    qsort(A,N,sizeof(data),asc);

    long sum=0;
    for(int i=0;i<N;i++){
        sum+=A[i].b;
        if(sum>=K){
            printf("%d\n",A[i].a);
            break;
        }
    }

    return 0;
}