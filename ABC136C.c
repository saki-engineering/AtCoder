#include<stdio.h>
#include<stdlib.h>

#define NEW(p,n){p=malloc((n)*sizeof(p[0]));if(p==NULL){printf("not enough memory\n");exit(1);};}
//pの型の変数n個の要素分のメモリを確保し、そのアドレスをpに代入するマクロ

int main(void){
    int N;
    scanf("%d",&N);

    //H[0]~H[N-1]に格納する
    int* H;
    NEW(H,N);
    for(int i=0;i<N;i++){
        scanf("%d",&H[i]);
    }

    //ansが0ならYes,1ならNo
    int ans=0;
    for(int i=N-2;i>=0;i--){
        if(H[i]-H[i+1]==1){
            H[i]=H[i]-1;
        }
        else if(H[i]-H[i+1]>1){
            ans=1;
            break;
        }
    }

    if(ans==0){
        printf("Yes\n");
    }
    else{
        printf("No\n");
    }
    return 0;
}

//300点
//解き方わかんなかった左からじゃなくて、右からやることを考えよう！！！