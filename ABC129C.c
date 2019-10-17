#include<stdio.h>
#include<stdlib.h>

#define NEW(p,n){p=malloc((n)*sizeof(p[0]));if(p==NULL){printf("not enough memory\n");exit(1);};}
//pの型の変数n個の要素分のメモリを確保し、そのアドレスをpに代入するマクロ

#define div 1000000007

int main(void){
    int N, M;
    scanf("%d %d",&N, &M);

    //A[0]~A[N]に格納する
    long* A;
    NEW(A,N+1);
    for(int i=0;i<=N;i++){
        A[i]=0;
    }
    //壊れている段aにはA[a]=-1を格納
    for(int i=1;i<=M;i++){
        int a;
        scanf("%d",&a);
        A[a]=-1;
    }

    //初期値
    A[0]=1;
    if(A[1]!=-1) A[1]=1;
    for(int i=2;i<=N;i++){
        if(A[i]==-1) continue;

        if(A[i-2]!=-1) A[i]=(A[i]+A[i-2])%div;
        if(A[i-1]!=-1) A[i]=(A[i]+A[i-1])%div;
        //ここがA[i]+=A[i-1]%divだと、計算順序の関係でWAになる
    }

    printf("%ld\n",A[N]);

    return 0;
}

//困ったところは34行目くらい