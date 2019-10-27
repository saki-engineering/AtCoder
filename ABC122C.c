#include<stdio.h>
#include<stdlib.h>

#define NEW(p,n){p=malloc((n)*sizeof(p[0]));if(p==NULL){printf("not enough memory\n");exit(1);};}
//pの型の変数n個の要素分のメモリを確保し、そのアドレスをpに代入するマクロ

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

int main(void){
    int N,Q;
    scanf("%d%d",&N,&Q);

    char S[N+1];
    scanf("%s",S);

    //A[0]~A[N]に、S[0]~S[i]にACが何個あったかを格納する
    int A[N];
    A[0]=0;
    for(int i=1;i<N;i++){
        if(S[i-1]=='A' && S[i]=='C') A[i]=A[i-1]+1;
        else A[i]=A[i-1];
    }

    int ans[Q];

    for(int i=0;i<Q;i++){
        int l,r;
        scanf("%d%d",&l,&r);

        ans[i]=A[r-1]-A[l-1];
        
    }

    for(int i=0;i<Q;i++){
        printf("%d\n",ans[i]);
    }

    return 0;
}

//配列Aを作るという考えかた！これだとO(n)ですむ！
//特に困らなかった