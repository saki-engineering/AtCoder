#include<stdio.h>
#include<stdlib.h>

#define NEW(p,n){p=malloc((n)*sizeof(p[0]));if(p==NULL){printf("not enough memory\n");exit(1);};}
//pの型の変数n個の要素分のメモリを確保し、そのアドレスをpに代入するマクロ

//最大公約数
int gcd(int a, int b){
    //a>bになるように入れ替え
    if(a<b){
        int tmp=a;
        a=b;
        b=tmp;
    }

    //ユークリッドの互除法
    if(a%b==0) return b;
    return gcd(b,a%b);
}

int main(void){
    int N;
    scanf("%d",&N);

    //A[0]~A[N-1]に格納する
    int* A;
    NEW(A,N);
    for(int i=0;i<N;i++){
        scanf("%d",&A[i]);
    }

    //L[i]は、A[0]~A[i]のgcdを格納
    int* L;
    NEW(L,N);
    L[0]=A[0];
    for(int i=1;i<N;i++){
        L[i]=gcd(L[i-1],A[i]);
    }

    //R[i]は、A[i]~A[N-1]のgcdを格納
    int* R;
    NEW(R,N);
    R[N-1]=A[N-1];
    for(int i=N-2;i>=0;i--){
        R[i]=gcd(R[i+1],A[i]);
    }

    //A[i]を除いた時の最大公約数をM[i]に格納
    int* M;
    NEW(M,N);

    M[0]=R[1];
    M[N-1]=L[N-2];
    for(int i=1;i<N-1;i++){
        M[i]=gcd(L[i-1],R[i+1]);
    }

    int ans=0;
    for(int i=0;i<N;i++){
        if(ans<M[i]) ans=M[i];
    }
    printf("%d\n",ans);

    return 0;
}

//最大公約数は、どんな順番で計算してもいい
//L,Rの考え方ができるか？？