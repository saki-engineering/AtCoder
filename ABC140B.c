#include<stdio.h>
#include<stdlib.h>

#define NEW(p,n){p=malloc((n)*sizeof(p[0]));if(p==NULL){printf("not enough memory\n");exit(1);};}
//pの型の変数n個の要素分のメモリを確保し、そのアドレスをpに代入するマクロ

int main(void){
    int N;
    scanf("%d",&N);

    int* A;
    NEW(A,N);
    for(int i=0;i<N;i++){
        scanf("%d", &A[i]);
    }

    int* B;
    NEW(B,N);
    for(int i=0;i<N;i++){
        scanf("%d\n", &B[i]);
    }

    int* C;
    NEW(C,N);
    for(int i=0;i<N-1;i++){
        scanf("%d", &C[i]);
    }

    //料理を食べた時の総満足度
    int sum=0;
    for(int i=0;i<N;i++){
        sum+=B[i];
    }

    //得られるボーナス満足度
    int bonus=0;
    for(int i=0;i<N-1;i++){
        if(A[i+1]==A[i]+1){
            bonus+=C[A[i]-1];
        }
    }

    int ans=sum+bonus;

    printf("%d\n",ans);

    return 0;
}

//200点