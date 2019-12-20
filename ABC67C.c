#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define NEW(p,n){p=malloc((n)*sizeof(p[0]));if(p==NULL){printf("not enough memory\n");exit(1);};}
//pの型の変数n個の要素分のメモリを確保し、そのアドレスをpに代入するマクロ

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define SWAP(type, x, y) do { type tmp = x; x = y; y = tmp; } while (0)

#define MOD 1000000007 

int main(void){
    int N;
    scanf("%d",&N);

    //A[0]~A[N-1]に格納する
    long* A;
    NEW(A,N);
    for(int i=0;i<N;i++){
        scanf("%ld",&A[i]);
    }

    long* sum;
    NEW(sum,N);
    sum[0]=A[0];
    for(int i=1;i<N;i++){
        sum[i]=sum[i-1]+A[i];
    }

    long ans=9999999999999999;
    for(int i=0;i<N-1;i++){
        ans=MIN(ans,labs((sum[N-1]-sum[i])-sum[i]));
    }
    printf("%ld\n",ans);

    return 0;
}