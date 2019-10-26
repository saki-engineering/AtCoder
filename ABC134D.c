#include<stdio.h>
#include<stdlib.h>

#define NEW(p,n){p=malloc((n)*sizeof(p[0]));if(p==NULL){printf("not enough memory\n");exit(1);};}
//pの型の変数n個の要素分のメモリを確保し、そのアドレスをpに代入するマクロ

int main(void){
    int N;
    scanf("%d",&N);

    //A[1]~A[N]に格納する
    int* A;
    NEW(A,N+1);
    for(int i=1;i<=N;i++){
        scanf("%d",&A[i]);
    }

    //ボールを入れる箱の個数
    int M=0;

    //ボールを入れる方法を格納する
    //B[i]は番号iの箱
    int* B;
    NEW(B,N+1);
    for(int i=N;i>0;i--){
        //iの倍数が書かれた箱のボースの総数をsumに数える
        int index=i;
        int sum=0;
        while(index<=N){
            sum+=B[index];
            index+=i;
        }

        if((sum%2)==A[i]) B[i]=0;
        else{
            B[i]=1;
            M+=1;
        }
    }

    printf("%d\n",M);
    if(M!=0){
        for(int i=1;i<=N;i++){
            if(B[i]==1) printf("%d ",i);
        }
        printf("\n");
    }

    return 0;
}

//400点
//昇順で考えるより降順で考えたほうがいいこともあるよね