#include<stdio.h>
#include<stdlib.h>

#define NEW(p,n){p=malloc((n)*sizeof(p[0]));if(p==NULL){printf("not enough memory\n");exit(1);};}
//pの型の変数n個の要素分のメモリを確保し、そのアドレスをpに代入するマクロ

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

//昇順
int asc(const void* a, const void* b){
    return *(int*)a-*(int*)b;
}

//降順
int desc(const void* a, const void* b){
    return *(int*)b-*(int*)a;
}

int main(void){
    int N,K;
    scanf("%d%d",&N,&K);

    //A[0]~A[N-1]に格納する
    int* x;
    NEW(x,N);
    for(int i=0;i<N;i++){
        scanf("%d",&x[i]);
    }

    int ans=MIN(abs(x[0])+abs(x[K-1]-x[0]), abs(x[K-1])+abs(x[K-1]-x[0]));
    for(int i=1;i<N+1-K;i++){
        int tmp=MIN(abs(x[i])+abs(x[K+i-1]-x[i]), abs(x[K+i-1])+abs(x[K+i-1]-x[i]));
        ans=MIN(ans,tmp);
    }
    printf("%d\n",ans);

    return 0;
}

//逐次的に、次はどのろうそくに火を付けるのか探す必要はない
//連続したK個につけるのが最適とわかっているんだから、どのK個につくかという結果だけ考える！