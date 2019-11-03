#include<stdio.h>
#include<stdlib.h>

#define NEW(p,n){p=malloc((n)*sizeof(p[0]));if(p==NULL){printf("not enough memory\n");exit(1);};}
//pの型の変数n個の要素分のメモリを確保し、そのアドレスをpに代入するマクロ

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

long count_p(long X,int L, long* num, long* P, long tmp){
    long ans;
    if(L==0) ans=tmp+P[0];
    else{
        if(X==1) ans=tmp+0;
        else if(X==num[L]/2+1) ans=tmp+P[L-1]+1;
        else if(X==num[L]) ans=tmp+P[L];

        else if(X<(num[L]/2+1)){
            ans=count_p(X-1,L-1,num,P,tmp+0); //ここに+tmpはしない
        }
        else{
            ans=count_p(X-num[L-1]-2,L-1,num,P,tmp+P[L-1]+1); //ここに+tmpはしない
        }
    }

    return ans;
}

int main(void){
    int N;
    long X;
    scanf("%d%ld",&N,&X);

    //num[i]...レベルiバーガーが何枚か
    //P[i]...レベルiバーガーが何枚のパティがあるのか
    long num[N+1];
    long P[N+1];
    num[0]=P[0]=1;
    for(int i=1;i<=N;i++){
        num[i]=2*num[i-1]+3;
        P[i]=2*P[i-1]+1;
    }

    long ans=0;
    ans=count_p(X,N,num,P,ans);

    printf("%ld\n",ans);

    return 0;
}

//二分探索！