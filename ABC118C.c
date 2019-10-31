#include<stdio.h>
#include<stdlib.h>

#define NEW(p,n){p=malloc((n)*sizeof(p[0]));if(p==NULL){printf("not enough memory\n");exit(1);};}
//pの型の変数n個の要素分のメモリを確保し、そのアドレスをpに代入するマクロ

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

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

    for(int i=0;i<N-1;i++){
        A[i+1]=gcd(A[i],A[i+1]);
    }
    printf("%d\n",A[N-1]);

    return 0;
}