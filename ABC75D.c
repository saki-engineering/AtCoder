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
    long x;
    long y;
}data;

int main(void){
    int N,K;
    scanf("%d%d",&N,&K);

    //A[0]~A[N-1]に格納する
    data* A;
    NEW(A,N);
    for(int i=0;i<N;i++){
        scanf("%ld%ld",&A[i].x,&A[i].y);
    }

    long ans=1e18*4;
    for(int a=0;a<N;a++){
        for(int b=0;b<N;b++){
            for(int c=0;c<N;c++){
                for(int d=0;d<N;d++){
                    long x0=MIN(A[a].x, A[b].x);
                    long x1=MAX(A[a].x, A[b].x);

                    long y0=MIN(A[c].y, A[d].y);
                    long y1=MAX(A[c].y, A[d].y);

                    int tmp=0;
                    for(int i=0;i<N;i++){
                        if(x0<=A[i].x && A[i].x<=x1 && y0<=A[i].y && A[i].y<=y1) tmp++;
                    }
                    if(tmp>=K) ans=MIN(ans,(x1-x0)*(y1-y0));
                }
            }
        }
    }
    printf("%ld\n",ans);

    return 0;
}