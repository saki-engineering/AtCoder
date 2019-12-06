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

    int F[N][10];
    for(int i=0;i<N;i++){
        for(int j=0;j<10;j++) scanf("%d",&F[i][j]);
    }

    long P[N][11];
    for(int i=0;i<N;i++){
        for(int j=0;j<11;j++) scanf("%ld",&P[i][j]);
    }

    long ans=-9999999999;
    for(int p=1;p<(1<<10);p++){
        long tmp=0;
        ///店iについて
        for(int i=0;i<N;i++){
            int c=0;
            for(int j=0;j<10;j++){
                if((p>>j)&F[i][j]) c++;
            }
            tmp+=P[i][c];
        }
        ans=MAX(ans,tmp);
    }
    printf("%ld\n",ans);

    return 0;
}