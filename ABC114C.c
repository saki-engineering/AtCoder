#include<stdio.h>
#include<stdlib.h>

#define NEW(p,n){p=malloc((n)*sizeof(p[0]));if(p==NULL){printf("not enough memory\n");exit(1);};}
//pの型の変数n個の要素分のメモリを確保し、そのアドレスをpに代入するマクロ

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
long ans=0;


int count_753(long key,long N,int f3, int f5, int f7){
    int ans=0;
    //停止判定(key>N)を、再帰関数の中に組み込んでしまうと楽
    if(key>N) return ans;

    //f3=1 and f5=1 and f7=1を、and文で書くんじゃなくて、ただの足し算で書くとすごくスマートになる
    if(f3+f5+f7==3) ans++;

    ans+=count_753((key*10+3),N,1,f5,f7);
    ans+=count_753((key*10+5),N,f3,1,f7);
    ans+=count_753((key*10+7),N,f3,f5,1);

    return ans;
}

int main(void){
    long N;
    scanf("%ld",&N);

    ans=count_753(0,N,0,0,0);

    printf("%ld\n",ans);

    return 0;
}