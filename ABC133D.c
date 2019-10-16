#include<stdio.h>
#include<stdlib.h>

#define NEW(p,n){p=malloc((n)*sizeof(p[0]));if(p==NULL){printf("not enough memory\n");exit(1);};}
//pの型の変数n個の要素分のメモリを確保し、そのアドレスをpに代入するマクロ

int main(void){
    int N;
    scanf("%d",&N);

    //A[1]~A[N]にダムの水量を格納する
    int* A;
    NEW(A,N+1);
    for(int i=1;i<=N;i++){
        scanf("%d",&A[i]);
    }

    //B[1]~B[N]に、山の水量を格納する
    int* B;
    NEW(B,N+1);

    //山1には2xだけ降った
    int x=0;
    for(int i=1;i<=N;i++){
        if(i%2==1) x+=A[i];
        else x-=A[i];
    }
    //本当はこうだけど、打ち消されるので省略
    //x=x/2;
    //B[1]=2*x;
    B[1]=x;

    for(int i=2;i<=N;i++){
        B[i]=2*(A[i-1]-B[i-1]/2);
    }

    for(int i=1;i<=N;i++){
        printf("%d ",B[i]);
    }
    printf("\n");

    return 0;
}

//400点
//方程式をとくことはできない、直接答えを求める式を入れること