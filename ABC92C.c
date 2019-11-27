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
    int priority;
    double value;
}data;

//昇順
int asc(const void* a, const void* b){
    return *(int*)a-*(int*)b;
}

//降順
int desc(const void* a, const void* b){
    return *(int*)b-*(int*)a;
}

int main(void){
    int N;
    scanf("%d",&N);

    //A[0]~A[N-1]に格納する
    long* A;
    NEW(A,N+2);
    A[0]=0;
    for(int i=1;i<=N;i++){
        scanf("%ld",&A[i]);
    }
    A[N+1]=0;

    long sum=0;
    for(int i=1;i<=N+1;i++){
        sum+=labs(A[i]-A[i-1]);
    }

    for(int i=1;i<=N;i++){
        long ans=sum-labs(A[i]-A[i-1])-labs(A[i+1]-A[i])+labs(A[i+1]-A[i-1]);
        printf("%ld\n",ans);
    }
    return 0;
}

//困った事はない