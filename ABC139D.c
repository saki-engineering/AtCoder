#include<stdio.h>
#include<stdlib.h>

#define NEW(p,n){p=malloc((n)*sizeof(p[0]));if(p==NULL){printf("not enough memory\n");exit(1);};}
//pの型の変数n個の要素分のメモリを確保し、そのアドレスをpに代入するマクロ

int main(void){
    int N;
    scanf("%d",&N);

    long ans=0;
    for(int i=1;i<N;i++){
        ans+=i;
    }
    printf("%ld\n",ans);

    return 0;
}

//400点