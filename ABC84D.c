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
    int l;
    int r;
}data;

int main(void){
    int Q;
    scanf("%d",&Q);

    //A[0]~A[N-1]に格納する
    data* A;
    NEW(A,Q);
    for(int i=0;i<Q;i++){
        scanf("%d%d",&A[i].l,&A[i].r);
    }

    //iが素数のとき、prime[i]は1、そうでないなら0
    int* prime;
    int N=1e5;
    NEW(prime,N+1);
    prime[1]=0;
    for(int i=2;i<=N;i++) prime[i]=1;
    for(int i=2;i<=N;i++){
        if(prime[i]==1){
            int j=2;
            while(i*j<=N){
                prime[i*j]=0;
                j++;
            }
        }
    }

    int* ans;
    NEW(ans,N+1);
    ans[0]=0;
    for(int i=1;i<=N;i++){
        if(prime[i]){
            if(prime[(i+1)/2]) ans[i]=1;
        }
    }
    for(int i=1;i<=N;i++) ans[i]+=ans[i-1];

    for(int i=0;i<Q;i++){
        printf("%d\n",ans[A[i].r]-ans[A[i].l-1]);
    }

    return 0;
}