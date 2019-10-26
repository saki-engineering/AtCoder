#include<stdio.h>
#include<stdlib.h>

#define NEW(p,n){p=malloc((n)*sizeof(p[0]));if(p==NULL){printf("not enough memory\n");exit(1);};}
//pの型の変数n個の要素分のメモリを確保し、そのアドレスをpに代入するマクロ

#define MIN(a,b) ((a) < (b) ? (a) : (b))

int main(void){
    int N;
    scanf("%d",&N);

    int* B;
    NEW(B,N-1);
    for(int i=0;i<N-1;i++){
        scanf("%d\n", &B[i]);
    }

    long ans;
    ans=B[0]; //A[0]=B[0]
    for(int i=1;i<N-1;i++){
        ans+=MIN(B[i-1],B[i]); //A[i]=min(B[i-1],B[i])
    }
    ans+=B[N-2]; //A[N-1]=B[N-2];

    printf("%ld\n",ans);

    return 0;
}

//300点
//解法の肝はコメント部分、実際に紙に書いてA[i]を求めて仕組みを探すこと