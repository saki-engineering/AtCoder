#include<stdio.h>
#include<stdlib.h>

#define NEW(p,n){p=malloc((n)*sizeof(p[0]));if(p==NULL){printf("not enough memory\n");exit(1);};}
//pの型の変数n個の要素分のメモリを確保し、そのアドレスをpに代入するマクロ

#define MIN(a, b) ((a) < (b) ? (a) : (b))


int main(void){
    int N;
    scanf("%d",&N);

    //A[0]~A[N]に格納
    int* A;
    NEW(A,N+1);
    for(int i=0;i<=N;i++){
        scanf("%d",&A[i]);
    }
    //B[0]~B[N-1]に格納する
    int* B;
    NEW(B,N);
    for(int i=0;i<N;i++){
        scanf("%d",&B[i]);
    }

    long ans=0;
    //i番目の勇者が倒す数
    for(int i=0;i<N;i++){
        //i番目の勇者がi番目の街で倒す数
        if(A[i]>=B[i]){
            ans+=B[i];
            A[i]-=B[i];
            B[i]=0;
        }
        else{
            ans+=A[i];
            B[i]-=A[i];
            A[i]=0;
        }
        //i番目の勇者がi+1番目の街で倒す数
        if(A[i+1]>=B[i]){
            ans+=B[i];
            A[i+1]-=B[i];
            B[i]=0;
        }
        else{
            ans+=A[i+1];
            B[i]-=A[i+1];
            A[i+1]=0;
        }
    }

    printf("%ld\n",ans);

    return 0;
}


//300点
//このアルゴリズム考えるのが無理すぎる
//意外と単純に考えて良い