#include<stdio.h>
#include<stdlib.h>

#define NEW(p,n){p=malloc((n)*sizeof(p[0]));if(p==NULL){printf("not enough memory\n");exit(1);};}
//pの型の変数n個の要素分のメモリを確保し、そのアドレスをpに代入するマクロ

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
long ans=0;


int count_753(long s,long N,int a, int b, int c){
    if(s>N) return ans;

    if(a+b+c==3) ans++;

    count_753((s*10+3),N,1,b,c);
    count_753((s*10+5),N,a,1,c);
    count_753((s*10+7),N,a,b,1);
}

int main(void){
    long N;
    scanf("%ld",&N);

    ans=count_753(0,N,0,0,0);

    printf("%ld\n",ans);

    return 0;
}