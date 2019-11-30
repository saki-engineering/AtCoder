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
    int x;
    int y;
}grid;

int main(void){
    int H,W,D;
    scanf("%d%d%d",&H,&W,&D);

    //A[0]~A[N-1]に格納する
    grid* G;
    NEW(G,H*W);
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            int v;
            scanf("%d",&v);
            G[v-1].x=i;
            G[v-1].y=j;
        }
    }

    int Q;
    scanf("%d",&Q);

    int* L;
    NEW(L,Q);
    int* R;
    NEW(R,Q);
    for(int i=0;i<Q;i++){
        scanf("%d%d",&L[i],&R[i]);
        L[i]--;
        R[i]--;
    }

    //累積和
    long* sum;
    NEW(sum,H*W);
    for(int i=0;i<H*W;i++){
        if(i/D==0) sum[i]=0;
        else sum[i]=sum[i-D]+abs(G[i].x-G[i-D].x)+abs(G[i].y-G[i-D].y);
    }

    for(int i=0;i<Q;i++){
        long ans=sum[R[i]]-sum[L[i]];
        printf("%ld\n",ans);
    }

    return 0;
}

//総和をwhileループでQ個求めると、O(H*W*Q)でTLEになってしまう。