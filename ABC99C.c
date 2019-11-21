#include<stdio.h>
#include<stdlib.h>

#define NEW(p,n){p=malloc((n)*sizeof(p[0]));if(p==NULL){printf("not enough memory\n");exit(1);};}
//pの型の変数n個の要素分のメモリを確保し、そのアドレスをpに代入するマクロ

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define SWAP(type, x, y) do { type tmp = x; x = y; y = tmp; } while (0)

#define MOD 1000000007 

int main(void){
    int N;
    scanf("%d",&N);

    int* ans;
    NEW(ans,N+1);
    //初期値(1円ずつ引き出し)
    for(int i=0;i<=N;i++) ans[i]=i;

    for(int i=1;i<=N;i*=6){
        for(int k=0;k<=N-i;k++) ans[k+i]=MIN(ans[k+i],ans[k]+1);
    }
    for(int j=1;j<=N;j*=9){
        for(int k=0;k<=N-j;k++) ans[k+j]=MIN(ans[k+j],ans[k]+1);
    }

    printf("%d\n",ans[N]);

    return 0;
}

//貪欲法でいけないなら、DPを考えること
//DPの更新の仕方を、ans[i]ではなくans[k+i]にすると、forループが楽