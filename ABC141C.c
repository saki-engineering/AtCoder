#include<stdio.h>
#include<stdlib.h>

#define NEW(p,n){p=malloc((n)*sizeof(p[0]));if(p==NULL){printf("not enough memory\n");exit(1);};}
//pの型の変数n個の要素分のメモリを確保し、そのアドレスをpに代入するマクロ

int main(void){
    int N, K, Q;
    scanf("%d %d %d",&N, &K, &Q);

    int A[Q+1]; //A[1]~A[Q]に格納
    for(int i=1;i<=Q;i++){
        scanf("%d",&A[i]);
    }

    int B[N+1]; //B[1]~B[N]に格納、B[i]はi番目の人の得点
    for(int i=1;i<=N;i++){
        B[i]=K-Q;
    }

    for(int i=1;i<=Q;i++){
        B[A[i]]++;
    }

    for(int i=1;i<=N;i++){
        if(B[i]>0){
            printf("Yes\n");
        }
        else{
            printf("No\n");
        }
    }

    return 0;
}


//300点
//特に困らなかった！