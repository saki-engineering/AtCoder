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
    int N,M;
    scanf("%d%d",&N,&M);

    long ans=1;
    if(abs(N-M)==0){
        for(int i=1;i<=N;i++) ans=(ans*i)%MOD;
        for(int i=1;i<=M;i++) ans=(ans*i)%MOD;
        ans=(ans*2)%MOD;
    }
    else if(abs(N-M)==1){
        for(int i=1;i<=N;i++) ans=(ans*i)%MOD;
        for(int i=1;i<=M;i++) ans=(ans*i)%MOD;
    }
    else ans=0;
    printf("%ld\n",ans);

    return 0;
}