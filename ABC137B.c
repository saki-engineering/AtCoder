#include<stdio.h>
#include<stdlib.h>

#define NEW(p,n){p=malloc((n)*sizeof(p[0]));if(p==NULL){printf("not enough memory\n");exit(1);};}
//pの型の変数n個の要素分のメモリを確保し、そのアドレスをpに代入するマクロ

int main(void){
    int K, X;
    scanf("%d %d",&K, &X);

    int min=X-(K-1);
    int max=X+(K-1);

    for(int i=min;i<=max;i++){
        printf("%d\n",i);
    }

    printf("\n");

    return 0;
}

//200点
//とくに苦労なし