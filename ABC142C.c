#include<stdio.h>
#include<stdlib.h>

#define NEW(p,n){p=malloc((n)*sizeof(p[0]));if(p==NULL){printf("not enough memory\n");exit(1);};}
//pの型の変数n個の要素分のメモリを確保し、そのアドレスをpに代入するマクロ

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define SWAP(type, x, y) do { type tmp = x; x = y; y = tmp; } while (0)

#define MOD 1000000007 

typedef struct{
    int id;
    int sum;
}data;

//昇順
int asc(const void* a, const void* b){
    data p=*(data*)a;
    data q=*(data*)b;
    return p.sum-q.sum;
}

int main(void){
    int N;
    scanf("%d",&N);

    //A[0]~A[N-1]に格納する
    data* A;
    NEW(A,N);
    for(int i=0;i<N;i++){
        A[i].id=i+1;
        scanf("%d",&A[i].sum);
    }

    qsort(A,N,sizeof(data),asc);

    for(int i=0;i<N;i++){
        printf("%d ",A[i].id);
    }
    printf("\n");

    return 0;
}

//特に困ったことなし