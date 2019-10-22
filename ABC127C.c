#include<stdio.h>
#include<stdlib.h>

#define NEW(p,n){p=malloc((n)*sizeof(p[0]));if(p==NULL){printf("not enough memory\n");exit(1);};}
//pの型の変数n個の要素分のメモリを確保し、そのアドレスをpに代入するマクロ

#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

int main(void){
    int N, M;
    scanf("%d %d",&N, &M);

    //全部通れるIDカードの範囲が[L,R]
    int L,R;
    int ltmp,rtmp;
    L=1;
    R=N;

    for(int j=1;j<=M;j++){
        scanf("%d %d",&ltmp, &rtmp);
        if(ltmp>L) L=ltmp;
        if(rtmp<R) R=rtmp;
    }

    int ans=R-L+1;
    if(ans<0) ans=0;
    printf("%d\n",ans);

    return 0;
}

//入力ごとに1回ずつ処理(共通部分をとる)するのではなく、一気に処理することも考える！