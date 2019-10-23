#include<stdio.h>
#include<stdlib.h>

#define NEW(p,n){p=malloc((n)*sizeof(p[0]));if(p==NULL){printf("not enough memory\n");exit(1);};}
//pの型の変数n個の要素分のメモリを確保し、そのアドレスをpに代入するマクロ

int main(void){
    int N, K;
    scanf("%d %d",&N, &K);

    double ans=0;
    double filter=K;
    double p=1;

    int i=N;
    while(i>0){
        if(i>=filter){
            ans+=p;
            i--;
        }
        else{
            filter=filter/2;
            p=p/2;
        }
    }

    ans=ans/N;
    printf("%.9f\n",ans);

    return 0;
}

//たまにいは降順でwhileループ回したほうがいいこともある
//出力桁数の指定方法→L28